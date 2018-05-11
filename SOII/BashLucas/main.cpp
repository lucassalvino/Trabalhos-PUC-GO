#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <future>
#include <signal.h>

using namespace std;

void trataSignal(int sig);
void executeExecCommand(vector<char*> args);
void executCommmand (vector<char*> args);
void executPipeCommands (vector<char*> args);
void runFork(vector<char*> args, bool esperaFilho = true)
{
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Falha ao criar fork");
    }
    else
    {
        if(pid==0){
            executCommmand(args);
        }else{
            if(esperaFilho)
                if(waitpid( pid, 0, 0 ) < 0){// aguarda conclusao do processo filho
                    printf("Filho não respondeu ");
                }
        }
    }
}

string GetHost()
{//get nome da maquina
    char ret[255];
    * ret = 0;
    gethostname(ret, sizeof(ret));
    return string(ret);
}

string GetShellBash()
{//monta string a ser exibida como promtp
    char atual [1225];
    * atual = 0;
    if(getcwd(atual, sizeof(atual)) == 0)
        throw "Impossivel pegar o caminho da pasta atual!!!!";
    string caminhoAtual(atual);
    int i =(int)caminhoAtual.size()-1;
    for(; caminhoAtual[i] != '/'; i--);
    string folder = "~";
    for(; i < (int)caminhoAtual.size(); i++)
        folder += caminhoAtual[i];
    if(caminhoAtual == string("/"))folder = "/";
    return string (GetHost() + ":" +folder+ "$ ");
}

void executCommmand (vector<char*> args)
{//executa um commando e seus argumentos
    if(args.size() <= 0) return;

    if(strcmp(args[0], "exec") == 0)
        executeExecCommand(args);

    char** arg = new char*[args.size()+1];
    for ( int k = 0; k < (int)args.size(); k++ )
        arg[k] = args[k];
    arg[(int)args.size()] = 0;

    execvp(args[0], arg);
    perror( args[0] );
}

void executPipeCommands (vector<char*> args){
    int i;
    for( i=1; i<(int)args.size()-1; i++)
    {
        int pd[2];
        pipe(pd);

        if (!fork()) {
            dup2(pd[1], 1); // remap output back to parent
            execlp(args[i], args[i], NULL);
            perror("exec");
            abort();
        }

        // remap output from previous child to input
        dup2(pd[0], 0);
        close(pd[1]);
    }
    execlp(args[i], args[i], NULL);
    perror("exec");
}

void executeExecCommand(vector<char*> args)
{//executa um comando com exec
    args.erase(args.begin());//tira exec
    executCommmand(args);//executa comando
    exit(1);//xau
}

bool ContinueForkCommand(vector<char*> args)
{//verifica se é para fazer o fork
    if(args.size() <= 0) return false; // no imput the command

    if(strcmp(args[0], "cd") == 0) // trata 'cd'
    {
        if((int)args.size() != 2)
            throw "O comando CD espera um parametro";
        string dest(args[1]);
        if (chdir(dest.c_str()) == -1)
            throw "Diretorio nao existe ou está inacessível";
        return false;
    }
    if(strcmp(args[0], "exec") == 0)//trata 'exec'
    {
        executeExecCommand(args);
        exit(0);
        return false;
    }
    if(strcmp(args[(int)args.size()-1], "&") == 0)// trata '&'
    {
        args.erase(args.end()-1);
        runFork(args, false);
        return false;
    }
    return true;
}

bool TrataPipe(char * entrada){
    vector<char*> args;
    char* prin = strtok(entrada," ");
    char* tmp = prin;

    while ( tmp != NULL ){
        args.push_back( tmp );
        tmp = strtok( NULL, " " );
    }
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Falha ao criar fork");
    }
    else
    {
        if(pid==0){
            executPipeCommands(args);
        }else{
            if(waitpid( pid, 0, 0 ) < 0){// aguarda conclusao do processo filho
                printf("Filho não respondeu ");
            }
        }
    }
    return true;
}

bool MasterShell(){//fluxo principal do shell
    char entrada[5000];
    printf("%s", GetShellBash().c_str());
    scanf(" %[^\n]", entrada);

    char * pipe = strchr(entrada,'|');
    if(pipe!=0)
        return  TrataPipe(entrada);

    vector<char*> args;
    char* prin = strtok(entrada," ");
    char* tmp = prin;

    if ( strcmp( prin , "exit" ) == 0 )
        exit(0);

    while ( tmp != NULL ){
        args.push_back( tmp );
        tmp = strtok( NULL, " " );
    }

    if(!ContinueForkCommand(args))return true;

    runFork(args);

    return true;
}
int main(){
    signal(SIGINT, trataSignal);
    while (MasterShell());
    return 0;
}

void trataSignal(int sig)
{//identifica e trata o ctrl+c
    char  c;
    signal(sig, SIG_IGN);
    printf("\nCtrl-C? [s/n] ");
    c = getchar();
    if (c == 's' || c == 'S')
        exit(0);
    else{
        main();
    }
}


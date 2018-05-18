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
#include <fcntl.h>
#include <sstream>
#include <cstddef>
#include <string>


using namespace std;

void trataSignal(int sig);
void executeExecCommand(vector<char*> args);
void executCommmand (vector<char*> args);
void executPipeCommands (vector<char*> args);
void splitRedirecionamento( string str, char c, string &str1, string &str2);
void parseArgs( string cmd, char * argv[]);

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

void RedirecionamentoEntrada(char* entrada){
    pid_t pid = fork();
    if(pid < 0){
        printf("Falha ao gerar fork");
    }else{
        if(pid==0){
            char* parametros [255];
            string line(entrada), cmd, arquivo;
            int in;
            splitRedirecionamento(line,'<',cmd,arquivo);
            in = open(arquivo.c_str(),O_RDONLY);
            dup2(in, 0);
            close(in);
            execvp(parametros[0], parametros);
            //exit(0);
        }
        else{
            wait(NULL);
        }
    }
    /*pid_t pid;
    pid = fork();
    if (pid == -1) { //error
        printf("Falha ao criar fork");
        return;
    }
    if (pid == 0) {

        parseArgs(cmd,parametros);
        //close stdin

        //open file
        in = open(arquivo.c_str(),O_RDONLY);

        dup2(in, 0);
        close(in);

        execvp(parametros[0], parametros);
        exit(0);
    }
    else {
        wait (NULL);
    }*/
}

void RedirecionamentoSaida(char *entrada){
    char* parametros[255];
    string line(entrada), cmd, file;
    pid_t pid;
    pid = fork();
    if (pid ==-1) { //error
        printf("Falha ao criar fork");
        return;
    }
    if (pid == 0) {
        splitRedirecionamento(line,'>',cmd,file);
        parseArgs(cmd,parametros);
        close(1);
        mode_t mode = 0644;
        creat(file.c_str(),mode);
        execvp(parametros[0], parametros);
        printf("falha executar comando com redirecionamento de saida");
        exit(0);
    }
    else {
        wait (NULL);
    }
}

//http://man7.org/linux/man-pages/man2/pipe.2.html
void executPipeCommands (vector<char*> args){
    int i;
    for( i=1; i<(int)args.size()-1; i++)
    {
        int pd[2];//Extremidades dos pipe
        pipe(pd);
        if (!fork()) {
            dup2(pd[1], 1); // saída de volta para o pai
            execlp(args[i], args[i], NULL);
            perror("exec");
            abort();
        }
        //saída do filho anterior para entrada
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

bool TrataRedirecionamentoEntrada(char * entrada){
    RedirecionamentoEntrada(entrada);
    return true;
}

bool TrataRedirecionamentoSaida(char * entrada){
    RedirecionamentoSaida(entrada);
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

    char * entr = strchr(entrada,'<');
    if(entr!=0){
        *entr = 0;
        return TrataRedirecionamentoEntrada(entrada);
    }

    entr = strchr(entrada,'>');
    if(entr!=0){
        *entr = 0;
        return TrataRedirecionamentoSaida(entrada);
    }


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

void splitRedirecionamento( string str, char c, string &str1, string &str2 )
{
    size_t pos = str.find( c );
    str1 = str.substr( 0, pos );
    pos = str.find_first_not_of( " \t", pos + 1 );
    str2 = str.substr( pos );
}

void parseArgs( string cmd, char * argv[ ] )
{
    int argc = 0;
    size_t start = 0;
    size_t end = 0;
    string arg;

    while( end != string::npos  && argc < 255 - 1) {
        start = cmd.find_first_not_of( " \t", end );
        if( start == string::npos )
            break;
        end = cmd.find_first_of( " \t", start );
        arg = cmd.substr( start, end - start );
        argv[argc] = new char[arg.length( ) + 1];
        strcpy(argv[argc], arg.c_str());
        argc++;
    }
    argv[argc] = NULL;
}

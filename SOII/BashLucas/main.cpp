#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <unistd.h>

using namespace std;

string GetHost()
{
    char ret[255];
    * ret = 0;
    gethostname(ret, sizeof(ret));
    return string(ret);
}

string GetShellBash()
{
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

void executeExecCommand(vector<char*> args);

void executCommmand (vector<char*> args)
{
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

void executeExecCommand(vector<char*> args)
{
    args.erase(args.begin());
    executCommmand(args);
    exit(1);
}

bool ContinueForkCommand(vector<char*> args)
{
    if(args.size() <= 0) return false; // no imput the command

    if(strcmp(args[0], "cd") == 0)
    {
        if((int)args.size() != 2)
            throw "O comando CD espera um parametro";
        string dest(args[1]);
        if (chdir(dest.c_str()) == -1)
            throw "Diretorio nao existe ou está inacessível";
        return false;
    }
    if(strcmp(args[0], "exec") == 0)
    {
        executeExecCommand(args);
        exit(0);
        return false;
    }
    if(strcmp(args[(int)args.size()-1], "&") == 0)
    {
    }
    return true;
}

bool MasterShell(){
    char entrada[5000];
    printf("%s", GetShellBash().c_str());
    scanf(" %[^\n]", entrada);

    vector<char*> args;
    char* prin = strtok(entrada," ");
    char* tmp = prin;

    if ( strcmp( prin , "exit" ) == 0 )
        return false;

    while ( tmp != NULL ){
        args.push_back( tmp );
        tmp = strtok( NULL, " " );
    }

    if(!ContinueForkCommand(args))return true;

    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Falha ao criar fork");
        return false;
    }
    else
    {
        if(pid==0){
            executCommmand(args);
            return false;
        }else{
            if(waitpid( pid, 0, 0 ) < 0){
                printf("Filho não respondeu ");
                return false;
            }
        }
    }
    return true;
}

int main(){
    while (MasterShell());
    return 0;
}

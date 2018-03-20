#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

bool MasterShell()
{
    printf("pcname:~$ ");
    char linha[5000];
    * linha = 0;
    scanf(" %[^\n]", linha);
    vector<char*> args;
    char* principal = strtok(linha," ");
    char* tmp = principal;
    if ( strcmp( principal , "exit" ) == 0 )
        return false;
    while ( tmp != NULL )
    {
       args.push_back( tmp );
       tmp = strtok( NULL, " " );
    }
    char** argumentos = new char*[args.size()+1];
    for ( int k = 0; k < args.size(); k++ )
          argumentos[k] = args[k];
    argumentos[(int)args.size()] = 0;
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Falha ao criar fork para execucao de comando");
        exit(1);
    }else{
        if(pid==0){
            execvp(principal, argumentos);
            perror( linha );
            return false;
        }else{
            if(waitpid( pid, 0, 0 ) < 0)
            {
                perror("Processo filho nao respondeu ");
                return false;
            }
        }
    }
    return true;
}

int main()
{
    while (MasterShell());
    return 0;
}

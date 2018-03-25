#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
using namespace std;
bool MasterShell(){
    printf("=>> ");
    char entrada[5000];
    * entrada = 0;
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
    char** arg = new char*[args.size()+1];
    for ( int k = 0; k < args.size(); k++ )
          arg[k] = args[k];
    arg[(int)args.size()] = 0;
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Falha ao criar fork");
        return false;
    }else{
        if(pid==0){
            execvp(prin, arg);
            perror( entrada );
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
    while (MasterShell() == true);
    return 0;
}

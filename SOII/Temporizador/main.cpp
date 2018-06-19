#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdlib.h>

#define NUMEROPROCESSOS 2
#define PRIORIDADEPAI	 	5
#define PRIORIDADEALTA		4
#define PRIORIDAEMEDIA		3
#define PRIORIDADEBAIXA		2
int *g_shm_addr;

#define		DESBLOQUEADO	1
#define		ALTA_BLOQUEADA	2
#define		BAIXA_BLOQUEADA	3
void PrioridadeALta( void );
void PrioridadeMedia( void );
void PrioridadeBaixa( void );
void sa110_terminate(void);

int main( int argc, char *argv[] )
{
    struct sched_param param;
    int rtn;
    int count;
    int pid[NUMEROPROCESSOS];
    param.sched_priority = PRIORIDADEPAI;
    if( sched_setscheduler( 0, SCHED_RR, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar agendamento ... voce é root?\n");
        exit(1);
    }
    param.sched_priority = PRIORIDADEPAI;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar compartilhamento!\n");
        exit(1);
    }
    *g_shm_addr = DESBLOQUEADO;
    rtn = 1;
    for( count = 0; count < NUMEROPROCESSOS; count++ ) {
        if( rtn != 0 ) {
            pid[count] = rtn = fork();
        } else {
            break;
        }
    }
    if( rtn == 0 ) {
        switch( count ) {
        case 1:
            PrioridadeBaixa();
            break;
        case 2:
            PrioridadeMedia();
            //PrioridadeALta();
            break;
        }
        exit(0);
    } else {
        sleep(3);
        kill(pid[0], SIGTERM);
        kill(pid[1], SIGTERM);
        kill(pid[2], SIGTERM);
    }
}
void PrioridadeALta( void )
{
    struct sched_param param;
    param.sched_priority = PRIORIDADEALTA;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro!\n");
        exit(1);
    }

    printf( "Processo de prioridade alta iniciada...\n" );
    while(1) {
        usleep(1000000);
        *g_shm_addr = ALTA_BLOQUEADA;
        printf("Prioridade alta iniciou...!\n");
        usleep(1000000);
        printf("Prioridade alta terminou!\n");
        *g_shm_addr = DESBLOQUEADO;
    }
}

void PrioridadeMedia( void )
{
    struct sched_param param;
    int i;
    param.sched_priority = PRIORIDAEMEDIA;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar prioridade!\n");
        exit(1);
    }
    while(1) {
        if( *g_shm_addr == BAIXA_BLOQUEADA ) {
            printf( "Prioridade media iniciou...\n" );
            for( i = 0; i < 100000000; i++ );
            fprintf(stderr,"Prioridade media terminou!\n");
        }
        usleep(10000);
    }
}

void PrioridadeBaixa( void )
{
    struct sched_param param;
    param.sched_priority = PRIORIDADEBAIXA;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Error setting priority!\n");
        exit(1);
    }
    while(1) {
        usleep(100000);
        *g_shm_addr = BAIXA_BLOQUEADA;
        fprintf(stderr,"Prioridade baixa iniciou!\n");
        usleep(100000);
        fprintf(stderr,"Prioridade baixa terminou!\n");
        *g_shm_addr = DESBLOQUEADO;
    }
}

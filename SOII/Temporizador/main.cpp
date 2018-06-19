/*******************************************************************************
*
* Experiment #6: Scheduling, Priorities, and Priority Inversion
*
*    Programmer: Eric Sorton
*          Date: 3/10/97
*           For: MSE599, Special Topics Class
*
*       Purpose: This program demostrates the priority inversion of two
*		 processes.  To demonstrate this, three processes are created
*		 along with one shared memory segment and one sempahore.  The
*		 shared memory segment is used to allow the processes to
*		 communicate who has the lock.  The semaphore is the critical
*		 resource that both two processes need.
*
*		 Three processes will be started, a high priority process,
*		 a middle priority process, and a low priority process.  The
*		 high and low priority processes both need to get the lock.
*		 It is critical that the high priority process get the lock
*		 quickly when it needs it.
*
*		 However, this is not the case, the following scenario happens:
*
*			1) Low priority process gets lock
*			2) High priority process needs lock
*			3) Middle priority process runs and takes up a lot
*				of CPU time delaying the time that it takes
*				the High priority process to get the lock.
*			4) When Middle finally finishes, Low runs, releases
*				Lock.
*			5) Finally, High gets the Lock.
*
*******************************************************************************/

/*
 * Needed Includes
 */
#include <errno.h>		/* errno and error codes */
#include <sys/time.h>		/* for gettimeofday() */
#include <unistd.h>		/* for gettimeofday(), getpid() */
#include <stdio.h>		/* for printf() */
#include <unistd.h>		/* for fork() */
#include <sys/types.h>		/* for wait() */
#include <sys/wait.h>		/* for wait() */
#include <signal.h>		/* for kill(), sigsuspend(), others */
#include <sys/ipc.h>		/* for all IPC function calls */
#include <sys/shm.h>		/* for shmget(), shmat(), shmctl() */
#include <sys/sem.h>		/* for semget(), semop(), semctl() */
#include <sched.h>		/* for scheduling calls/constants */
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#define SHM_KEY		4321			/* Choose a number */
#define SEM_KEY		1234			/* Choose a number */
#define NO_OF_CHILDREN 3
#define PARENT_PRIORITY	 	5
#define HIGH_PRIORITY		4
#define MIDDLE_PRIORITY		3
#define LOW_PRIORITY		2
struct sembuf g_lock_sembuf[1];
struct sembuf g_lock_nowait_sembuf[1];
struct sembuf g_unlock_sembuf[1];
int g_shm_id;
int g_sem_id;
int *g_shm_addr;

#define		UNLOCKED	1
#define		HIGH_HAS_LOCK	2
#define		LOW_HAS_LOCK	3
void PrioridadeALta( void );
void PrioridadeMedia( void );
void PrioridadeBaixa( void );
void sa110_terminate(void);

int main( int argc, char *argv[] )
{
    struct sched_param param;
    int rtn;
    int count;
    int pid[NO_OF_CHILDREN];
    param.sched_priority = PARENT_PRIORITY;
    if( sched_setscheduler( 0, SCHED_RR, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar agendamento ... voce é root?\n");
        exit(1);
    }
    param.sched_priority = PARENT_PRIORITY;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar compartilhamento!\n");
        exit(1);
    }
    g_lock_sembuf[0].sem_num   =  0;
    g_lock_sembuf[0].sem_op    = -1;
    g_lock_sembuf[0].sem_flg   =  0;
    g_lock_nowait_sembuf[0].sem_num   =  0;
    g_lock_nowait_sembuf[0].sem_op    = -1;
    g_lock_nowait_sembuf[0].sem_flg   =  IPC_NOWAIT;
    g_unlock_sembuf[0].sem_num =  0;
    g_unlock_sembuf[0].sem_op  =  1;
    g_unlock_sembuf[0].sem_flg =  0;
    if( ( g_sem_id = semget( SEM_KEY, 1, IPC_CREAT | 0666 ) ) == -1 ) {
        fprintf(stderr,"falha ao criar semafaro!");
        exit(1);
    }
    if( semop( g_sem_id, g_unlock_sembuf, 1 ) == -1 ) {
        fprintf(stderr,"falha ao criar semafaro!");
        exit(1);
    }
    if( (g_shm_id = shmget( SHM_KEY, sizeof(int), IPC_CREAT | 0666)) == -1 ) {
        fprintf(stderr,"falha ao criar memoria compartilhada!\n");
        exit(1);
    }
    if( (g_shm_addr = (int *)shmat(g_shm_id, NULL, 0)) == (int *)-1 ) {
        fprintf(stderr,"falha ao acessar memoria compartilhada!\n");
        exit(1);
    }
    *g_shm_addr = UNLOCKED;
    rtn = 1;
    for( count = 0; count < NO_OF_CHILDREN; count++ ) {
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
            break;
        case 3:
          //  PrioridadeALta();
            break;
        }
        exit(0);
    } else {
        sleep(3);
        kill(pid[0], SIGTERM);
        kill(pid[1], SIGTERM);
        kill(pid[2], SIGTERM);
        if( shmctl(g_shm_id,IPC_RMID,NULL) != 0 ) {
            fprintf(stderr,"Memoria compartilhada não foi encontrada!\n");
            exit(1);
        }
        if( semctl( g_sem_id, 0, IPC_RMID, 0) != 0 ) {
            fprintf(stderr,"Não remoivi o semáforo!\n");
            exit(1);
        }
        sa110_terminate();
    }
}
void PrioridadeALta( void )
{
    struct sched_param param;
    int rtn;
    param.sched_priority = HIGH_PRIORITY;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro!\n");
        exit(1);
    }

    printf( "Processo de prioridade alta iniciada...\n" );
    while(1) {
        usleep(1000000);
        while( (rtn = semop( g_sem_id, g_lock_sembuf, 1 )), rtn != 0 && errno == EAGAIN ) {
            usleep(100000);
        }
        if( rtn != 0 ) {
            fprintf(stderr,"falha ao realizar acesso a semáfaro!");
            exit(1);
        }
        *g_shm_addr = HIGH_HAS_LOCK;
        printf("Prioridade alta iniciou...!\n");
        usleep(1000000);
        printf("Prioridade alta terminou!\n");
        if( semop( g_sem_id, g_unlock_sembuf, 1 ) == -1 )
        {
            fprintf(stderr,"falha ao acessar semáforo");
            exit(1);
        }
        *g_shm_addr = UNLOCKED;
    }
}

void PrioridadeMedia( void )
{
    struct sched_param param;
    int i;
    param.sched_priority = MIDDLE_PRIORITY;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Erro ao criar prioridade!\n");
        exit(1);
    }
    while(1) {
        if( *g_shm_addr == LOW_HAS_LOCK ) {
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
    param.sched_priority = LOW_PRIORITY;
    if( sched_setparam( 0, &param ) == -1 ) {
        fprintf(stderr,"Error setting priority!\n");
        exit(1);
    }
    while(1) {
        usleep(100000);
        if( semop( g_sem_id, g_lock_sembuf, 1 ) == -1 )
            exit(1);
        *g_shm_addr = LOW_HAS_LOCK;
        fprintf(stderr,"Prioridade baixa iniciou!\n");
        usleep(100000);
        fprintf(stderr,"Prioridade baixa terminou!\n");
        if( semop( g_sem_id, g_unlock_sembuf, 1 ) == -1 )
        {
            exit(1);
        }
        *g_shm_addr = UNLOCKED;
    }
}

void sa110_terminate()
{
    printf("Fim\n");
}

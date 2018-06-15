#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/sem.h>

sem_t  func1, func2;

void *funcao1(void *);
void *funcao2(void *);

int main(void)
{
    srand(time(NULL));

    sem_init(&func1, 0 , 1);
    sem_init(&func2, 0, 20);

    pthread_t thd0, thd1;

    pthread_create(&thd0, 0, funcao1, NULL);
    pthread_create(&thd1, 0, funcao2, NULL);

    pthread_join(thd0,0);
    pthread_join(thd1,0);
    exit(0);
}

void *funcao1(void *p_arg)
{
    while(1)
    {
        sem_wait(&func1);
        printf("Funcao 01\n");
        sem_post(&func2);
        sleep(1);
    }
}

void *funcao2(void *p_arg)
{
    while(1)
    {
        sem_wait(&func2);
        printf("funcao 02\n");
        sem_post(&func1);
        sleep(2);
    }
}

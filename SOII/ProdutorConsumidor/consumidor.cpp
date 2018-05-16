#include "definicaodados.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <time.h>
#include <sys/shm.h>
using namespace std;
//g++ consumidor.cpp -lpthread -lrt -o consumidor
int main(){
    void *memoria_compartilhada = (void *)0;
    struct StructMemoriaCompartilhada * instanciaMemoriaCompartilhada;
    int shmid = shmget((key_t)1234, sizeof(struct StructMemoriaCompartilhada), 0666 | IPC_CREAT);
    if(shmid < 0)
        throw "Memoria compartilhada não acessível";

    memoria_compartilhada = shmat(shmid, (void *)0, 0);

    if(memoria_compartilhada == (void *)-1)
        throw "Memoria não acessível";

    instanciaMemoriaCompartilhada = (struct StructMemoriaCompartilhada*)memoria_compartilhada;

    while(true)
    {
        sem_wait(&instanciaMemoriaCompartilhada->pos_ocupada);
        instanciaMemoriaCompartilhada->inicio = (instanciaMemoriaCompartilhada->inicio + 1) % TAMANHO_BUFFER;
        printf("Consumindo [%d]\n", instanciaMemoriaCompartilhada->Buffer[instanciaMemoriaCompartilhada->inicio]);
        sem_post(&instanciaMemoriaCompartilhada->pos_vazia);
        sleep(random()%TEMPO_ESPERA);
    }
    return 0;
}

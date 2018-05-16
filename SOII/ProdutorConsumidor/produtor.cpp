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
//g++ produtor.cpp -lpthread -lrt -o produtor
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

    sem_init(&instanciaMemoriaCompartilhada->pos_vazia, 0, TAMANHO_BUFFER);
    sem_init(&instanciaMemoriaCompartilhada->pos_ocupada, 0, 0);
    instanciaMemoriaCompartilhada->inicialidado = true;
    int i = 0;
    while(true)
    {
        sem_wait(&instanciaMemoriaCompartilhada->pos_vazia);// aguarda buffer fazio
        printf("Produzido [%d]\n", i);
        instanciaMemoriaCompartilhada->final = (instanciaMemoriaCompartilhada->final + 1) % TAMANHO_BUFFER;
        instanciaMemoriaCompartilhada->Buffer[instanciaMemoriaCompartilhada->final] = i;
        sem_post(&instanciaMemoriaCompartilhada->pos_ocupada);
        sleep(random() % TEMPO_ESPERA);
        i++;
    }
    return 0;
}

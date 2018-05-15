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
    return 0;
}

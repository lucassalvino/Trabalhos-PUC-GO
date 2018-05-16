#ifndef DEFINICAODADOS_H
#define DEFINICAODADOS_H

#define TAMANHO_BUFFER 10
#define TEMPO_ESPERA 2

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

struct StructMemoriaCompartilhada {
    int Buffer[TAMANHO_BUFFER];
    sem_t pos_vazia; //semafaro buffer vazio
    sem_t pos_ocupada; //semafaro com buffer ocupado
    int inicio, final;
    bool inicialidado;
    StructMemoriaCompartilhada(){
        inicialidado = false;
        inicio = final = 0;
    }
};


#endif // DEFINICAODADOS_H

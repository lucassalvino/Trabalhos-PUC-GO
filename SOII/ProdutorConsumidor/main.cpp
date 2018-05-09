#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
using namespace std;

#define TAMANHO_BUFFER 5
#define TEMPO_ESPERA 2

int buffer[TAMANHO_BUFFER];

sem_t pos_vazia; //semafaro buffer vazio
sem_t pos_ocupada; //semafaro com buffer ocupado

int inicio = 0, final = 0;

void* produtor(void *v) {// Rotina do produtor
    for (int i = 0;; i++) {
        sem_wait(&pos_vazia);// aguarda buffer fazio
        printf("Produzido [%d]\n", i);
        final = (final + 1) % TAMANHO_BUFFER;// Lista Circular para adição de elementos produzidos
        buffer[final] = i;
        sem_post(&pos_ocupada);//sinaliza elementos no buffer
        sleep(random() % TEMPO_ESPERA);
    }
    return NULL;
}

void* consumidor(void *v) {// Rotina Consumidor
    for (;;) {
        sem_wait(&pos_ocupada);//aguarda alementos no buffer
        inicio = (inicio + 1) % TAMANHO_BUFFER; // Listar circular para consumo de elementos no buffer
        printf("Consumindo [%d]\n", buffer[inicio]);
        sem_post(&pos_vazia);// sinaliza espaço no buffer
        sleep(random() % TEMPO_ESPERA);
    }
    return NULL;
}

int main()
{
    pthread_t thr_produtor, thr_consumidor;// threads produtor consumidor
    srand(time(0)); // inicializa seed do random
    sem_init(&pos_vazia, 0, TAMANHO_BUFFER); //inicializa semafaro buffer vazio
    sem_init(&pos_ocupada, 0, 0); //inicializa semafaro buffer ocupado
    pthread_create(&thr_produtor, NULL, produtor, NULL);// instancia thread produtor
    pthread_create(&thr_consumidor, NULL, consumidor, NULL); // instancia thread consumidor
    pthread_join(thr_produtor, NULL);// Executa produtor
    pthread_join(thr_consumidor, NULL);// Executa Consumidor
    sem_destroy(&pos_vazia); // desaloca semafaro buffer vazio
    sem_destroy(&pos_ocupada);// desaloca semafaro buffer ocupado
    return 0;
}

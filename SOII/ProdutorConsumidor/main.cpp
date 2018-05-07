#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
using namespace std;

#define TAMANHO_BUFFER 10
#define TEMPO_ESPERA 5

int buffer[TAMANHO_BUFFER];

sem_t pos_vazia;
sem_t pos_ocupada;

int inicio = 0, final = 0;

void* produtor(void *v) {
    for (int i = 0;; i++) {
        sem_wait(&pos_vazia);
        printf("Produzido [%d]\n", i);
        final = (final + 1) % TAMANHO_BUFFER;
        buffer[final] = i;
        sem_post(&pos_ocupada);
        sleep(random() % TEMPO_ESPERA);
    }
    return NULL;
}

void* consumidor(void *v) {
    for (;;) {
        sem_wait(&pos_ocupada);
        inicio = (inicio + 1) % TAMANHO_BUFFER;
        printf("Consumindo [%d]\n", buffer[inicio]);
        sem_post(&pos_vazia);
        sleep(random() % TEMPO_ESPERA);
    }
    return NULL;
}

int main()
{
    pthread_t thr_produtor, thr_consumidor;
    srand(time(0));
    sem_init(&pos_vazia, 0, TAMANHO_BUFFER);
    sem_init(&pos_ocupada, 0, 0);
    pthread_create(&thr_produtor, NULL, produtor, NULL);
    pthread_create(&thr_consumidor, NULL, consumidor, NULL);
    pthread_join(thr_produtor, NULL);
    pthread_join(thr_consumidor, NULL);
    sem_destroy(&pos_vazia);
    sem_destroy(&pos_ocupada);
    return 0;
}

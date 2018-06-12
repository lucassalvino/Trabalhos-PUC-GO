#include <iostream>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
using namespace std;

bool Executa = true;

void Tarefa01 (){
    printf("Tarefa 01\n");
    while(Executa){
        double startTime = omp_get_wtime();
        while ((omp_get_wtime() - startTime) <=1) {}
        Executa = false;
    }
}

void Tarefa02(){
    printf("Tarefa 02\n");
    while(!Executa){
        double startTime = omp_get_wtime();
        while ((omp_get_wtime() - startTime) <=2) {}
        Executa = true;
    }
}

void GerenteTarefas(){
    while(true){
        printf("Iniciando ciclo...\n");
        thread a(Tarefa01), b(Tarefa02);
        a.join();
        b.join();
    }
}

int main()
{
    GerenteTarefas();
    return 0;
}

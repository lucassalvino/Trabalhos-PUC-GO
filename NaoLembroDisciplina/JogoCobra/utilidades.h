#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <ctime>

class Utilidades{//contem funçoes de proposito gerais
public:
    static char getch();//retorna um caracter sem a necessidade de teclar enter. FUNCIONA NO LINUX APENAS. procurar no windows caso seja necessário
    static void pausa (float delay1);//pausa todos os processos no tempo delay1
};

#endif // UTILIDADES_H

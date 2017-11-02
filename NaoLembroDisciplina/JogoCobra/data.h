#ifndef DATA_H
#define DATA_H
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <thread>
#include <utility>
#include <iostream>

#include "jogador.h"

/* dados gerais utilizados no jogo*/

using namespace std;
class Data
{
public:
    static pair<int,int> SOMATORIO_DIREITA;//somatorio para andar para direita
    static pair<int,int> SOMATORIO_ESQUERDA;//somatorio para andar para esquerda
    static pair<int,int> SOMATORIO_CIMA;//somatorio para andar para cima
    static pair<int,int> SOMATORIO_BAIXO;//somatorio para anda para baixo
    static pair<int,int> posiComida;//posição onde a comida está
    static pair<int,int> obstaculo;//obstaculo aleatorio

    static float tempoPausa;
    static Jogador jogador;//jogador|| pode existir vários jogadores, implementar sockt
    static int modoJogo;//modo de jogo| 1→ modo texto, 2→ modo gráfico
private:
};

#endif // DATA_H

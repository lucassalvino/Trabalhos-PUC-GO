#ifndef DATA_H
#define DATA_H

#include "tabuleiro.h"

class Data
{
public:
    static void setItemPosicaoTabuleiro(int i,int j,int jogador);
    static int temGanhador();
    static void reiniciaJogo();
    static int getItemPosicao(int i, int j);
private:
    static Tabuleiro tabule;
};

#endif // DATA_H

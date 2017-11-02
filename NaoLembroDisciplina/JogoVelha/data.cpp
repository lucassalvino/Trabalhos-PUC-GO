#include "data.h"

Tabuleiro Data::tabule;

void Data::setItemPosicaoTabuleiro(int i, int j, int jogador)
{
    tabule.setItemPosicao(i,j,jogador);
}

int Data::temGanhador()
{
    return tabule.verificaGanhador();
}

void Data::reiniciaJogo()
{
    tabule.inicializaJogo();
}

int Data::getItemPosicao(int i, int j)
{
    return tabule.getItemPosicao(i,j);
}

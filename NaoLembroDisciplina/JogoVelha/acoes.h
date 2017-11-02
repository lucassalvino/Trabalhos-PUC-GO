#ifndef ACOES_H
#define ACOES_H

#include "data.h"
class Acoes
{
public:
    static void realizaMocimentacaoJogador1(int i,int j);
    static void realizaMocimentacaoJogador2(int i,int j);
    static void realizarJogada(int i,int j);
    static void recomecarJogo();
    int static getItemPosicao(int i,int j);
private:
    static int token;
    static bool jogar;
};

#endif // ACOES_H

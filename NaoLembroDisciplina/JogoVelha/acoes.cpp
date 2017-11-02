#include "acoes.h"

bool Acoes::jogar = true;
int Acoes::token = JOGADOR1;

void Acoes::realizaMocimentacaoJogador1(int i,int j)
{
    if(jogar == false)throw string("Recomesse o jogo!");
    Data::setItemPosicaoTabuleiro(i,j,JOGADOR1);
    token = JOGADOR2;
    if(Data::temGanhador()!=VAZIO){
        jogar = false;
        throw string("O Jogador 1 Ganhou!!");
    }
}

void Acoes::realizaMocimentacaoJogador2(int i, int j)
{
    if(jogar == false)throw string("Recomesse o jogo!");
    Data::setItemPosicaoTabuleiro(i,j,JOGADOR2);
    token = JOGADOR1;
    if(Data::temGanhador()!=VAZIO){
        jogar = false;
        throw string("O Jogador 2 Ganhou!!");
    }
}

void Acoes::realizarJogada(int i, int j)
{
    switch (token) {
    case JOGADOR1:
       realizaMocimentacaoJogador1(i,j);
        break;
    case JOGADOR2:
        realizaMocimentacaoJogador2(i,j);
        break;
    }
}

void Acoes::recomecarJogo()
{
    Data::reiniciaJogo();
    jogar = true;
}

int Acoes::getItemPosicao(int i, int j)
{
    return Data::getItemPosicao(i,j);
}

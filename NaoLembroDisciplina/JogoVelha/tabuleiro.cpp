#include "tabuleiro.h"

Tabuleiro::Tabuleiro()
{
    mapa = new int*[N];
    for(int i=0;i<N;i++)
        mapa[i] = new int[N];
    inicializaJogo();
}
Tabuleiro::~Tabuleiro(){
    for(int i=0;i<N;i++)
        delete [] mapa[i];
    delete []mapa;
}

int Tabuleiro::getItemPosicao(int i, int j)
{
    if(!posicaoHeValida(i,j))throw string("Posicao excede o tamanho do tabuleiro [GET]");
    return mapa[i][j];
}

void Tabuleiro::setItemPosicao(int i, int j, int item)
{
    if(!posicaoHeValida(i,j))throw string("Posicao excede o tamanho do tabuleiro [SET]");
    if(item<VAZIO || item>JOGADOR2) throw string("Valor a ser setado deve estar no intervalo [0,4]");
    if(mapa[i][j]!=VAZIO)throw string("Posicao já foi marcada!!!");
    mapa[i][j]=item;
}

void Tabuleiro::_inicializaVazio()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            mapa[i][j] = VAZIO;
}

int Tabuleiro::_somaLinha(int i)
{
    int soma=0;
    for(int j=0;j<N;j++)soma+=mapa[i][j];
    return soma;
}

int Tabuleiro::_somaColuna(int j)
{
    int soma=0;
    for(int i=0;i<N;i++)soma+=mapa[i][j];
    return soma;
}

int Tabuleiro::_somaDiagonalPrincipal()
{
    int soma=0;
    for(int i=0;i<N;i++)soma+=mapa[i][i];
    return soma;
}

int Tabuleiro::_somaDiagonalSegundaria()
{
    int soma=0,j=2;
    for(int i=0;i<N;i++)
        soma+=mapa[i][j--];
    return soma;
}

bool Tabuleiro::posicaoHeValida(int i, int j)
{
    return !(i<0 || j<0 || j>=N || i>=N);
}

short Tabuleiro::validaPontuacao(int linha, int coluna)
{
    if(linha == (JOGADOR1 * 3) || coluna == (JOGADOR1 * 3))return JOGADOR1;
    if(linha == (JOGADOR2 * 3) || coluna == (JOGADOR2 * 3))return JOGADOR2;
    return VAZIO;
}

void Tabuleiro::inicializaJogo(){
    if(mapa == 0)throw string("Tem algo de muito errado aí hein");
    _inicializaVazio();
}

int Tabuleiro::verificaGanhador()
{
    int linha;
    int coluna;
    short val;
    for(int i=0;i<N;i++){
        linha = _somaLinha(i);
        coluna = _somaColuna(i);
        val = validaPontuacao(linha,coluna);
        if(val!=VAZIO)return val;
    }
    linha = _somaDiagonalPrincipal();
    coluna  = _somaDiagonalSegundaria();
    val = validaPontuacao(linha,coluna);
    return val;
}

#ifndef TABULEIRO_H
#define TABULEIRO_H


#define VAZIO 0
#define JOGADOR1 1
#define JOGADOR2 4

#define N 3
#include <iostream>
using namespace std;
class Tabuleiro{
public:
    Tabuleiro();
    ~Tabuleiro();
    int getItemPosicao(int i,int j);
    void setItemPosicao(int i,int j,int item);
    void inicializaJogo();
    int verificaGanhador();
private:
    void _inicializaVazio();
    int _somaLinha(int i);
    int _somaColuna(int j);
    int _somaDiagonalPrincipal();
    int _somaDiagonalSegundaria();
    bool posicaoHeValida(int i,int j);
    short validaPontuacao(int linha, int coluna);
    int** mapa;
};

#endif // TABULEIRO_H

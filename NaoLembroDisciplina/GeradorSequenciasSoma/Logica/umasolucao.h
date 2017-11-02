#ifndef UMASOLUCAO_H
#define UMASOLUCAO_H
//Lucas Salvino de Deus
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class UmaSolucao
{
public:
    UmaSolucao();
    vector<int> getSolucao();//retorna solucao inteiro
    int getQuantidadeElementos();//retorna a quantidade de elementos atualmente na solucao
    int getElementoSolucaoAt(int posicao);//retorna o elemento na posicao posicao
    int getSomaElementosSolucao();//retorna o somatorio dos elementos da solucao
    void setElementoSolucao(int elemento,int index);//adiciona elemento na posicao index
    void addElementoSolucao(int elemento);//adiciona elemento ao final do vetor Solucao
    void clear();//limpa o vetor solucao
private:
    vector<int> solucao;
    bool validaPosicaoDentroSolucao(int posicao);//retorna true caso a posicao esteja dentro do vetor, false caso contrario
};

#endif // UMASOLUCAO_H

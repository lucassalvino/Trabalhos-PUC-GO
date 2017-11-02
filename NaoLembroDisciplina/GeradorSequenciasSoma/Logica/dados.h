#ifndef DADOS_H
#define DADOS_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
using namespace std;
#include "umasolucao.h"
class Dados{
public:
    ~Dados();
    static int getNumeroSolucoes();
    static list<UmaSolucao>getSolucao();
    static void setSolucao(list<UmaSolucao> valor);
    static void addSolucao(UmaSolucao soluca);
    static int getQuantidadeElementosPorSolucao();
    static void setQuantidadeElementosPorSolucao(int value);
    static int getValorTotalSomatorio();
    static void setValorTotalSomatorio(int value);
    static int getN();
    static void setN(int value);

    static void limparDados();

    static int getNumSolucoes();
    static void setNumSolucoes(int value);

    static void saveSolucoesArquivo(string caminho);

private:
    Dados();
    list<UmaSolucao> solucoes;
    static Dados* _dados;
    int quantidadeElementosPorSolucao;
    int valorTotalSomatorio;
    int n;
    int numSolucoes;
    static void verificaInstancia();//verifica se _dados foi inicializado
};

#endif // DADOS_H

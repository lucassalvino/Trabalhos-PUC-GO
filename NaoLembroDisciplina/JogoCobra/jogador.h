#ifndef JOGADOR_H
#define JOGADOR_H


#include <iostream>
#include <stdio.h>
#include "itemmovel.h"
#include <list>


using namespace std;

#define CAMINHO_ARQUIVO "Config/jogador.txt"

class Jogador{
public:
    Jogador(string nome);
    Jogador();
    list<ItemMovel> getCobrina();
    void setCobrinha(list<ItemMovel> cobra);
    void addNoCobrinha(ItemMovel add);
    void addNoCobrinha();
    void morteJogador();
    string getNome();
    int getPontuacao();
    void addPontuacao(int val){pontuacao+=val;}

    void carregarJogadorArquivoTexto();
    void salvarJogadorArquivoTexto();
    void salvaJogadorArquivo();

    void inicializaJogador(string nome);
    int getNumeroMortes() const;
    void setNumeroMortes(int value);


    ItemMovel* getCabecaCobra();
    int getRecorde() const;


    int getTamanho() const;

protected:
    int pontuacao;
    int tamanho;
    string nome;
    list<ItemMovel>cobrinha;
    int numeroMortes;
    int recorde;
};

#endif // JOGADOR_H

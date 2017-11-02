#ifndef MAPA_H
#define MAPA_H

#include <assert.h>
#include <iostream>


using namespace std;

#define MAPA_NAO_INICIALIZADA throw string ("Mapa ainda não foi inicializado")

/*Classe representa o mapa onde ocorrerá o jogo.
Utiliza-se de uma matriz de ordem NxM para executar o jogo*/

//ITENS POSSIVEIS DE EXISTIREM NO MAPA
#define CAMINHO_CHAO 0
#define CAMINHO_GRAMA 1
#define ALIMENTO 2
#define PAREDE 3
#define COBRA 4
#define CABECAC0BRA 5


class Mapa{
public:
    ~Mapa();
    static void inicializaMapa(int n,int m);//inicializa o mapa com NxM celulas para o jogo
    static void setItemPosicaoMapa(int item,int i,int j);//seta o item na posicao i,j
    static int getItemPosicaoMapa(int i, int j);//retorna o elemento na osicao i,j
    static void limparMapa();
    static void apagarMapa();
    static int getN();
    static int getM();
private:
    int ** mapa;//matriz do mapa
    int n,m;//dimensões do mapa
    static Mapa * __mapa;//pode existir somente uma instância do mapa
    Mapa();
};

/*
 * -> site funcionando até dia 16 agora
 * -> dia 14 de junho tudo ok
 * -> r
 *
*/
#endif // MAPA_H

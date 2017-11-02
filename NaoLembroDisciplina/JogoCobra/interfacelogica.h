#ifndef INTERFACELOGICA_H
#define INTERFACELOGICA_H
#include "mapa.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <thread>
#include "data.h"
#include "utilidades.h"
#include "avancarnivel.h"

#include "modotexto.h"

#define CONFIG "Config/config.txt"



class InterfaceLogica
{//fachada entre mapa, jogador, modo texto e modo gráfico
public:
    static void andar();//itens moveis com exceção da comida andão uma posição
    static void virar(int direcao);//vira cobra para a direcao
    static void inicia();//inicia o jogo
    static bool carregaJogador();//carrega jogador
    static void salvaJogador();//salvo o jogador
    static void jogar();//inicia o jogo conforme as configurações carregadas em inica()
private:
    static void carregaJogadorManual();//caso a jogador não tenha sido carregado em carregaJogador() carrega o jogador aqui, em modo texto
    static void proxPosicao(ItemMovel& item);//atualiza item para sua proximaPosicao

    static void _JogoModoTexto();
    static void _JogoModoGrafico();
    static void validaPosicao(int &x,int& y);

    static int ** getMapaBuffer();
    static void somatorioItem(int &x, int &y, pair<int,int>soma);
    static void verificaComida();//se nao existir cria comida
    static void verificaAlimentacao();//come
    static void verificaMorte();
    static void morreu_Texto();
    static void verificaObstaculo();
    static void acoesMorte();

    static char realizaLeitura();
    static void __leituraTeclado();
    static void __jogo();
    static void __observerNivel();
    static bool continuaThread;
    static bool imprimirProxNivel;
    static void processaLeituraTeclado(char leitura);
};

#endif // INTERFACELOGICA_H

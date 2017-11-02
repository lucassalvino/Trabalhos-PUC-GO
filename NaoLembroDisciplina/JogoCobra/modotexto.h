#ifndef MODOTEXTO_H
#define MODOTEXTO_H
#include "mapa.h"
#include "jogador.h"
#include "niveis.h"

#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



/////////////////////////////////////////////////////////////////////
#define RESETE  0
#define NORMAL  1
#define NEGRITO 2
#define CINZA_CLARO  3
#define SUBLINHADO  4
#define NEGATIVO  5
#define CINZA_CLARO_2 6
#define VERMELHO 7
#define VERDE  8
#define AMARELO  9
#define AZUL 10
#define ROCHO  11
#define AZUL_CLARO 12
#define BRANCO  13
/////////////CONTORNOS//////////////////
#define CONTORNO_CINZA  14
#define CONTORNO_VERMELHO  15
#define CONTORNO_VERDE  16
#define CONTORNO_AMARELO  17
#define CONTORNO_AZUL 18
#define CONTORNO_ROCHO 19
#define CONTORNO_AZUL_CLARO 20
#define CONTORO_BRANCO  21
#define CONTORNO_NORMAL  22
/////////////////////////////////////////////
#define LIMPA_TELA printf("\33[H\33[2J")
#define CURSOR_OFF system("tput civis")
#define CURSOR_ON system("tput cnorm")

class Par{
    public:
        int a,b;
        Par(){}
        Par(int letra,int contorno){set(letra,contorno);}
        void set(int letra,int contorno){
            a=letra;
            b=contorno;
        }
        void ativar(){
            active_pair(a,b);
        }
        void desativar(){
            active_pair(0);
        }
    private:
       void active_pair(int a);
       void active_pair(int a,int b);
       void gotoxy(int x,int y);
};

class ModoTexto{//realiza a impressao em modo texto do jogo
public:
    static void printMapa(Mapa* mapa);
    static void printMapa(int n,int m, int **mapa);
    static void printJogador(Jogador* jogado,bool bonus);
    static void printMorte(int tamanho, ItemMovel posi);
    static void printPassouNivel(int nivel);
    ~ModoTexto();
private:
    static void printCaracterMapa(int val);
    static Par* cobra;
    static Par* grama;
    static Par* parede;
    static Par* chao;
    static Par* alimento;
    static Par* bonus;
    static Par* jogador;
};

#endif // MODOTEXTO_H

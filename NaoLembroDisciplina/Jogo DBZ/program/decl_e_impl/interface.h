#ifndef INTERFACE_H
#define INTERFACE_H
//bibliotecas instaladas
#include <allegro.h>
#include <stdlib.h>
#include <time.h>
//arquivos de defineção
#include "defines.h"
#include "joy.cpp"
#include "base_dados.cpp"
#include "utilidades.h"
//arquivos das classes
#include "item.cpp"
#include "animacao.cpp"
#include "jogador.cpp"
#include "vida.cpp"
//class interface de jogo espero
class Interface{
   static jogador *gamer[2];
   static Vida *gamer_life[2];
   static BITMAP *tmp_player_0,*tmp_player_1, *itens[NUM_BARRAS],*fundo[2],*bau[2],*objetos_screen[OBJETOS_SCREEN],*morte,*deft;
   static BITMAP *fundo_menu,*faces[NUM_PERSONAGENS],*quadro,*fundos[NUM_FUNDOS],*combo;
   static int tempo_0,tempo_1,mov_player_0,mov_player_1,movi_0[NUM_ANIMA],movi_1[NUM_ANIMA],carrega_ki,mostrar_bau[3],po_bau;
   static bool travado_0,travado_1,backp_0,backp_1;
   static bool golpe_pr_0,golpe_pr_1,trava_player_2,algem_morreu;

   static int multiplayer_a_computer();
   static void event_prees_tecla(int ,int ,bool ,int);
   static void print_status_jogadores();
   static bool estao_de_frente();
   static bool da_para_atacar();
   static bool dividindo_golpes(int,int);
   static void inicializa_sprites_gerais();
   static int menu();
   static void load_personagens();
   static void select_mapa(int);
   static void print_personagens_selecionados();
   static void select_personagem(int,int);
public:
   static void start();
};
BITMAP * Interface::fundo_menu;
BITMAP * Interface::faces[NUM_PERSONAGENS];
BITMAP * Interface::quadro;
BITMAP * Interface::fundos[NUM_FUNDOS];

Vida * Interface::gamer_life[2];
jogador * Interface::gamer[2];
BITMAP * Interface:: tmp_player_0=0;
BITMAP * Interface:: tmp_player_1=0;
BITMAP * Interface:: itens[NUM_BARRAS];
BITMAP * Interface::fundo[2];
BITMAP * Interface::bau[2];
BITMAP * Interface::objetos_screen[OBJETOS_SCREEN];
BITMAP * Interface::morte;
BITMAP * Interface::deft;
BITMAP * Interface::combo;
bool Interface::golpe_pr_0;
bool Interface::golpe_pr_1;
bool Interface::algem_morreu;
bool Interface::trava_player_2;
int  Interface:: mov_player_0=0;
int  Interface::po_bau=0;
int  Interface::mostrar_bau[3];
int  Interface:: mov_player_1=0;
int  Interface:: carrega_ki=0;
int  Interface:: movi_0[NUM_ANIMA];
int  Interface:: movi_1[NUM_ANIMA];
int  Interface:: tempo_0;
int  Interface:: tempo_1;
bool Interface:: travado_0;
bool Interface:: travado_1;
bool Interface:: backp_0;
bool Interface:: backp_1;
int al_j0,al_j1;
int x,y,x1,y1;


#endif // INTERFACE_H

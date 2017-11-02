#include "data.h"

float Data::tempoPausa = 0.2;
pair<int,int> Data::SOMATORIO_DIREITA = make_pair(0,1);
pair<int,int> Data::SOMATORIO_ESQUERDA = make_pair(0,-1);
pair<int,int> Data::SOMATORIO_CIMA = make_pair(-1,0);
pair<int,int> Data::SOMATORIO_BAIXO = make_pair(1,0);
pair<int,int> Data::posiComida = make_pair(-1,-1);
pair<int,int> Data::obstaculo = make_pair(-1,-1);

Jogador Data::jogador;
int Data::modoJogo = 0;

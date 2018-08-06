#include "jogador.h"
jogador::jogador(string pasta,bool orienta,int a){
	sprites=new animacao(pasta,a);
	orientacao_sprite=orienta;
}
void jogador::troca_orientacao(){
	if(orientacao_sprite)orientacao_sprite=false;
	else orientacao_sprite=true;
}
void jogador::set_x_y(int a,int b){
	x=a;
	y=b;
}
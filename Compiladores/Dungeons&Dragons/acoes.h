#include <stdio.h>
#include <stdlib.h>

#define VIDAPADRAO 20000
#define VIDATIAMAT 150000
#define _HANK 0
#define _PRESTO 1
#define _BOBBY 2
#define _DIANA 3
#define _SHEILA 4
#define _ERICK 5
#define _TIAMAT 6

int Vidas[7] = {0};

int dadoMeninos = 0;
int dadoTiamat = 0;

int DX(int x){
	return (rand()%x) + 1;
}

int D20(){
	return DX(20);
}

int D10(){
	return DX(10);
}

void imprimeDadoJogadores(){
	printf("\tDado Joagadores: [%d]\n\tDado Tiamat [%d]\n", dadoMeninos, dadoTiamat);
}

void atualizaDados(){
	dadoMeninos = D20();
	dadoTiamat = D10();
	imprimeDadoJogadores();
}

void inicializaVidas(){
	for(int i = 0; i <= 5; i++)
		Vidas[i] = VIDAPADRAO;
	
	Vidas[6] = VIDATIAMAT;
}

void jogadaHank(){}
void jogadaPresto(){}
void jogadaBobby(){}
void jogadaDiana(){}
void jogadaSheila(){}

void executaJogadaMeninos(int jogador){
	atualizaDados();
	bool defendeu = (dadoMeninos < dadoTiamat);

	switch(jogador){
		case _HANK:
		jogadaHank();
		break;
		case _PRESTO:
		jogadaPresto();
		break;
		case _BOBBY:
		jogadaBobby();
		break;
		case _DIANA:
		jogadaDiana();
		break;
		case _SHEILA:
		jogadaSheila();
		break;
	}

	if(defendeu){
		printf("Mas Tiamat conseguiu defender.\n");
	}
}


void ataqueCabecaBranca(){}
void ataqueCabecaVerde(){}
void ataqueCabecaVermelha(){}
void ataqueCabecaAzul(){}
void ataqueCabecaPreta(){}


void executaJogadaTiamat(){
	atualizaDados();
	bool defendeu = (dadoTiamat < dadoMeninos && Vidas[_ERICK] > 0);
	int cabeca = rand()%5;
	switch(cabeca){
		case 0:
			ataqueCabecaBranca();
			break;
		case 1:
			ataqueCabecaVerde();
			break;
		case 2:
			ataqueCabecaVermelha();
			break;
		case 3:
			ataqueCabecaAzul();
			break;
		case 4:
			ataqueCabecaPreta();
			break;
	}
	if(defendeu)
		printf("Mas Herik conseguiu defender o ataque.\n");
}
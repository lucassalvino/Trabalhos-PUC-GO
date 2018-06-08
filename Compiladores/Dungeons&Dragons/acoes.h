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

float Vidas[7] = {20000, 20000, 20000, 20000, 20000, 20000, 150000};
char Nomes[7][20] = {"Hank", "Presto", "Bobby", "Diana", "Sheila", "Erick", "Tiamat" };
int numeroMeninosVivos = 6;

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
	for(int i = 0; i < 7; i++)
		printf("\tPersonagem: %s\t Vida: %.2f\n", Nomes[i], Vidas[i]);
	printf("\tDado Joagadores: [%d]\t\tDado Tiamat [%d]\n", dadoMeninos, dadoTiamat);
}

void atualizaDados(){
	dadoMeninos = D20();
	dadoTiamat = D10();
	imprimeDadoJogadores();
}

float pontosRetiradosDragao(){
	if(Vidas[_TIAMAT]<=0){
		printf("%s ja esta morto\n", Nomes[_TIAMAT]);
		exit(-1);
	}
	int porcentagem = dadoMeninos - dadoTiamat;
	if(porcentagem < 0)porcentagem *=-1;
	return Vidas[_TIAMAT] * (porcentagem/100.0);
}

void jogadaHank(){
	printf("Hank atira uma flecha\n");
}
void jogadaPresto(){
	printf("Presto dispara um raio arcano\n");
}
void jogadaBobby(){
	printf("Bobby usa a tacape\n");
}
void jogadaDiana(){
	printf("Diana usa o bastao magico\n");
}
void jogadaSheila(){
	printf("Sheila usa a capa e ataca como um sniper\n");
}

void executaJogadaMeninos(int jogador){
	atualizaDados();
	int defendeu = (dadoMeninos < dadoTiamat);
	float pontos = pontosRetiradosDragao();
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
	}else{
		Vidas[_TIAMAT] -= pontos;
		printf("%s perdeu %.2f pontos de vida\n", Nomes[_TIAMAT], pontos);
		if(Vidas[_TIAMAT]<=0){
			Vidas[_TIAMAT] = 0;
			printf("%s foi derrotado\n", Nomes[_TIAMAT]);
		}
	}
}


void ataqueCabecaBranca(int jogador){
	printf("%s lanca raios congelantes contra %s\n",Nomes[_TIAMAT], Nomes[jogador] );
}
void ataqueCabecaVerde(int jogador){
	printf("%s lanca gas venenoso contra %s\n",Nomes[_TIAMAT], Nomes[jogador] );
}
void ataqueCabecaVermelha(int jogador){
	printf("%s lanca chamas contra %s\n",Nomes[_TIAMAT], Nomes[jogador] );
}
void ataqueCabecaAzul(int jogador){
	printf("%s lanca raios contra %s\n",Nomes[_TIAMAT], Nomes[jogador] );
}
void ataqueCabecaPreta(int jogador){
	printf("%s lanca acido contra %s\n",Nomes[_TIAMAT], Nomes[jogador] );
}


int selecionaJogadorAuvo(){
	if(numeroMeninosVivos <= 0)
		return -1;

	int jogador = rand()%6;
	if(Vidas[jogador] <= 0){
		while(Vidas[jogador]<=0){
			jogador = rand()%6;
		}
	}
	return jogador;
}

float pontosRetiradosMeninos(int jogador){
	int porcentagem = dadoMeninos - dadoTiamat;
	if(porcentagem < 0)porcentagem *=-1;
	return Vidas[jogador] * (porcentagem/100.0);
}

void executaJogadaTiamat(){
	atualizaDados();
	int defendeu = (dadoTiamat < dadoMeninos && Vidas[_ERICK] > 0);
	int cabeca = rand()%5;
	int jogadorAtingido = selecionaJogadorAuvo();
	float pontosRetirados = pontosRetiradosMeninos(jogadorAtingido);
	if(numeroMeninosVivos < 0){
		printf("Nao existe ninguem vivo mais!!!\n");
		exit(-1);
	}
	switch(cabeca){
		case 0:
			ataqueCabecaBranca(jogadorAtingido);
			break;
		case 1:
			ataqueCabecaVerde(jogadorAtingido);
			break;
		case 2:
			ataqueCabecaVermelha(jogadorAtingido);
			break;
		case 3:
			ataqueCabecaAzul(jogadorAtingido);
			break;
		case 4:
			ataqueCabecaPreta(jogadorAtingido);
			break;
	}
	if(defendeu)
		printf("Mas Herik conseguiu defender o ataque.\n");
	else{
		Vidas[jogadorAtingido] -= pontosRetirados;
		printf("%s perdeu %.2f pontos de vida\n",Nomes[jogadorAtingido], pontosRetirados);
		if(Vidas[jogadorAtingido] <= 0){
			Vidas[jogadorAtingido] = 0; numeroMeninosVivos--;
			printf("%s foi derrotado\n",Nomes[jogadorAtingido]);
		}
	}
}
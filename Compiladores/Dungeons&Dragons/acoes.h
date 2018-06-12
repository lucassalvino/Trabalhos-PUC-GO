#include <stdio.h>
#include <stdlib.h>

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
		printf("\tPersonagem: %s\t Vida: %.3f\n", Nomes[i], Vidas[i]);
	printf("\tDado Joagadores: [%d]\t\tDado Tiamat [%d]\n", dadoMeninos, dadoTiamat);
	printf("\n\n\n\n\n");
}

void atualizaDados(){
	dadoMeninos = D20();
	dadoTiamat = D10();
}

float pontosRetiradosDragao(int porcentagem){
	if(Vidas[_TIAMAT]<=0){
		printf("%s ja esta morto\n", Nomes[_TIAMAT]);
		exit(-1);
	}
	return Vidas[_TIAMAT] * (porcentagem/100.0);
}

int jogadaHank(){
	printf("Hank atira uma flecha\n");
	return 10;//porcentagem de dano de Hank
}
int jogadaPresto(){
	printf("Presto dispara um raio arcano\n");
	return 5;//porcentagem de dano de presto
}
int jogadaBobby(){
	printf("Bobby usa a tacape\n");
	return 15;//porcentagem de dano de Bobby
}
int jogadaDiana(){
	printf("Diana usa o bastao magico\n");
	return 7;//porcentagem de dano de Diana
}
int jogadaSheila(){
	printf("Sheila usa a capa e ataca como um sniper\n");
	return 9; //procentagem de dano de Sheila
}

void executaJogadaMeninos(int jogador){
	if(numeroMeninosVivos <= 0){
		printf("Não existe nenhum ninguem mais vivo\n");
		exit(-1);
	}
	atualizaDados();
	int defendeu = (dadoMeninos < dadoTiamat);
	int porcentagemDeDano = 0;
	switch(jogador){
		case _HANK:
			porcentagemDeDano = jogadaHank();
		break;
		case _PRESTO:
			porcentagemDeDano = jogadaPresto();
		break;
		case _BOBBY:
			porcentagemDeDano = jogadaBobby();
		break;
		case _DIANA:
			porcentagemDeDano = jogadaDiana();
		break;
		case _SHEILA:
			porcentagemDeDano = jogadaSheila();
		break;
	}

	if(defendeu){
		printf("Mas Tiamat conseguiu defender.\n");
	}else{
		float pontos = pontosRetiradosDragao(porcentagemDeDano);
		Vidas[_TIAMAT] -= pontos;
		printf("%s perdeu %.3f pontos de vida\n", Nomes[_TIAMAT], pontos);
		if(Vidas[_TIAMAT] <= 0.01){
			Vidas[_TIAMAT] = 0;
			printf("%s foi derrotado\n", Nomes[_TIAMAT]);
		}
	}
	imprimeDadoJogadores();
}


int ataqueCabecaBranca(int jogador){
	printf("%s lanca raios congelantes contra %s\n",Nomes[_TIAMAT], Nomes[jogador]);\
	return 15;
}

int ataqueCabecaVerde(int jogador){
	printf("%s lanca gas venenoso contra %s\n",Nomes[_TIAMAT], Nomes[jogador]);
	return 10;
}

int ataqueCabecaVermelha(int jogador){
	printf("%s lanca chamas contra %s\n",Nomes[_TIAMAT], Nomes[jogador]);
	return 20;
}

int ataqueCabecaAzul(int jogador){
	printf("%s lanca raios contra %s\n",Nomes[_TIAMAT], Nomes[jogador]);
	return 9;
}

int ataqueCabecaPreta(int jogador){
	printf("%s lanca acido contra %s\n",Nomes[_TIAMAT], Nomes[jogador]);
	return 7;
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

float pontosRetiradosMeninos(int jogador, int porcentagem){
	return Vidas[jogador] * (porcentagem/100.0);
}

void executaJogadaTiamat(){
	if(Vidas[_TIAMAT] <= 0.01){
		printf("Tiamat está morto\n");
		exit(-1);
	}

	atualizaDados();
	int defendeu = (dadoTiamat < dadoMeninos && Vidas[_ERICK] > 0);
	int cabeca = rand()%5;
	int jogadorAtingido = selecionaJogadorAuvo();
	int porcentagemDano = 0;
	if(numeroMeninosVivos <= 0 || jogadorAtingido == -1){
		printf("Nao existe ninguem vivo mais!!!\n");
		exit(-1);
	}
	switch(cabeca){
		case 0:
			porcentagemDano = ataqueCabecaBranca(jogadorAtingido);
			break;
		case 1:
			porcentagemDano = ataqueCabecaVerde(jogadorAtingido);
			break;
		case 2:
			porcentagemDano = ataqueCabecaVermelha(jogadorAtingido);
			break;
		case 3:
			porcentagemDano = ataqueCabecaAzul(jogadorAtingido);
			break;
		case 4:
			porcentagemDano = ataqueCabecaPreta(jogadorAtingido);
			break;
	}
	if(defendeu)
		printf("Mas Herik conseguiu defender o ataque.\n");
	else{
		float pontosRetirados = pontosRetiradosMeninos(jogadorAtingido, porcentagemDano);
		Vidas[jogadorAtingido] -= pontosRetirados;
		printf("%s perdeu %.3f pontos de vida\n",Nomes[jogadorAtingido], pontosRetirados);
		if(Vidas[jogadorAtingido] <= 0.01){
			Vidas[jogadorAtingido] = 0;
			numeroMeninosVivos--;
			printf("%s foi derrotado\n",Nomes[jogadorAtingido]);
		}
	}
	imprimeDadoJogadores();
}
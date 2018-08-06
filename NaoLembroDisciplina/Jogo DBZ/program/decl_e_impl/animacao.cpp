//implementação
#include "animacao.h"
animacao::animacao(string nome,int kame){
	string_to_char(nome,pasta);
	for(i=0;i<NUM_ANIMA;i++){
		k=0;aux=nome.size();
		while(pasta[k]!='\0'){caminho_imagens[i][k]=pasta[k];k++;}//copiando caminho para o objeto
		caminho_imagens[i][k]='/';k++;j=0;//copiando caminho para o objeto
		while(nome_imagens[i][j]!='x'&&j!=15){caminho_imagens[i][k]=nome_imagens[i][j];j++;k++;}//copiando caminho para o objeto
		caminho_imagens[i][k]='x';k++;//copiando caminho para o objeto
		while(k!=200){caminho_imagens[i][k]='\0';k++;}//copiando caminho para o objeto
		posi_seque[i]=posi_cont[i]+aux+1;//copiando caminho para o objeto
		caminho_imagens[i][posi_seque[i]]++;
	}
	for(i=0;i<MAX_IMAGENS;i++)num_IMAGENS[i]=0;
	carrega_imagens();
	nome+="/";
	nome+="FACE.pcx";
	string_to_char(nome,pasta);
	FACE=load_bitmap(pasta,NULL);
	char pasta[]="program/img/esferas/1_estrela.pcx";
	for(i=0;i<NUM_ESFERAS_DRAGAO;i++){
		ESFERAS[i]=load_bitmap(pasta,NULL);
		pasta[20]++;
	}
	char pasta_a[]="program/img/power/kame_00_1.pcx";
	for(i=0;i<kame;i++)
		pasta_a[24]++;
	for(i=0;i<3;i++){
		KAME_POWER[i]=load_bitmap(pasta_a,NULL);
		pasta_a[26]++;
	}
}
void animacao::carrega_seque_sprites(int movimento){
	for(i=0;i<MAX_IMAGENS;i++){
		IMAGENS[movimento][i]=load_bitmap(caminho_imagens[movimento],NULL);
		caminho_imagens[movimento][posi_seque[movimento]]++;//passando para a proxima imagem
		if(!IMAGENS[movimento][i])break;//acabou as imagens
		else num_IMAGENS[movimento]++;
	}
}
void animacao::carrega_imagens(){
	for(int cont=0;cont<NUM_ANIMA;cont++)
		carrega_seque_sprites(cont);
}

BITMAP* animacao::acesso_sprite(int movimento,int sequen){
	return IMAGENS[movimento][sequen];
}
BITMAP* animacao::acesso_face(){
	return FACE;
}

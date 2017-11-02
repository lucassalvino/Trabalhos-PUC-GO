#include "mapa.h"

Mapa*  Mapa::__mapa=0;

Mapa::Mapa(){
    mapa = 0;
    n = m = 0;
}

Mapa::~Mapa()
{
    apagarMapa();
    delete __mapa;
}

void Mapa::inicializaMapa(int n, int m){
//realiza a inicialização do mapa
    if (__mapa == 0)__mapa=new Mapa();
    if(n<=0||m<=0)throw string("O Tamanho do mapa deve ser maior do que Zero");
    __mapa->n = n;
    __mapa->m = m;

    __mapa->mapa = new int*[__mapa->n];
    if (__mapa->mapa == 0)assert("IMPOSSIVEL CONTINUAR, MEMORIA INSUFICIENTE");
    for(int i=0;i<__mapa->n;i++){
        __mapa->mapa[i] = new int[__mapa->m];
        if (__mapa->mapa[i] == 0)assert("IMPOSSIVEL CONTINUAR, MEMORIA INSUFICIENTE");
    }

    __mapa->limparMapa();//O mapa começa vazio || não é necessário realizar o preenchimento para caminho vazio
}

void Mapa::setItemPosicaoMapa(int item, int i, int j)
{
    if (__mapa ==0 || __mapa->mapa==0)MAPA_NAO_INICIALIZADA;
    if(i<0||i>=__mapa->n)throw string("POSICAO DE LINHA INVALIDA");
    if(j<0||j>=__mapa->m)throw string("POSICAO DE COLUNA INVALIDA");
    __mapa->mapa[i][j]=item;
}

int Mapa::getItemPosicaoMapa(int i, int j){//retorna o elemento na posicao i j do mapa
    if (__mapa ==0 || __mapa->mapa==0)MAPA_NAO_INICIALIZADA;
    if(i<0||i>=__mapa->n)throw string("POSICAO DE LINHA INVALIDA");
    if(j<0||j>=__mapa->m)throw string("POSICAO DE COLUNA INVALIDA");
    return __mapa->mapa[i][j];
}

void Mapa::limparMapa(){
    //coloca todas as posicoes do mapa para CAMINHO_CHAO
    if (__mapa ==0 || __mapa->mapa==0)MAPA_NAO_INICIALIZADA;
    if(__mapa->n<=0||__mapa->m<=0)return;
    for(int i=0;i<__mapa->n;i++)
        for(int j=0;j<__mapa->m;j++)
            __mapa->mapa[i][j] = CAMINHO_CHAO;
}

void Mapa::apagarMapa(){
    //desaloca o mapa
    if(__mapa ==0 || __mapa->mapa==0)return;
    for(int i =0;i<__mapa->n;i++)
        delete [] __mapa->mapa[i];
    delete [] __mapa->mapa;

    __mapa->mapa = 0;
    __mapa->n = __mapa->m = 0;
}

int Mapa::getN(){//retorna a quantidade de linhas do mapa
    if (__mapa == 0)MAPA_NAO_INICIALIZADA;
    return __mapa->n;
}

int Mapa::getM(){//retorna a qauntidade de coluna do  mapa
    if (__mapa == 0)MAPA_NAO_INICIALIZADA;
    return __mapa->m;
}

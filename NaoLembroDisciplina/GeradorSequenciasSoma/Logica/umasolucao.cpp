#include "umasolucao.h"

UmaSolucao::UmaSolucao(){}

vector<int> UmaSolucao::getSolucao(){
    return this->solucao;
}

int UmaSolucao::getQuantidadeElementos(){
    return solucao.size();
}

int UmaSolucao::getElementoSolucaoAt(int posicao){
    if(posicao<0){
        throw string("[ERRO][getElementoSolucaoAt]Valor de [posicao] é inválido");
    }
    return solucao[posicao];
}

int UmaSolucao::getSomaElementosSolucao(){
    int soma = 0,n=getQuantidadeElementos();
    for(int i=0;i<n;i++){
        soma+=solucao[i];
    }
    return soma;
}

void UmaSolucao::setElementoSolucao(int elemento, int index){
    if(!validaPosicaoDentroSolucao(index)){
        throw string("[ERRO][setElementoSolucao]Valor de [index] é invalida");
    }
    solucao[index] = elemento;
}

void UmaSolucao::addElementoSolucao(int elemento){
    solucao.push_back(elemento);
}

void UmaSolucao::clear(){
    solucao.clear();
}

bool UmaSolucao::validaPosicaoDentroSolucao(int posicao){
    if(posicao<0 || posicao>=getQuantidadeElementos())return false;
    return true;
}

#include "itemmovel.h"

ItemMovel::ItemMovel(){
    x = y = direcao = 0;//posicao canto superior e movendo para direita
}

int ItemMovel::getX(){
    return x;
}

int ItemMovel::getY(){
    return y;
}

int ItemMovel::getDirecao(){
    return direcao;
}

//considerações para funções set de X e Y
//itensMoveis não sabem o tamanho do mapa. portanto é validado somente se os valores são menores que zero
void ItemMovel::setX(int a){
    if(a<0)throw string("Uma coordenada X não pode ser negativa");
    x = a;
}

void ItemMovel::setY(int b){
    if(b<0)throw string("Uma coordenada Y não pode ser negativa");
    y = b;
}

void ItemMovel::setDirecao(int dire){
    //um item movel pode se locomover somente nas posições CIMA, BAIXO, ESQUERDA e DIREITA
    if(dire<DIREITA || dire>BAIXO)throw string("Direção inválida");
    direcao = dire;
}

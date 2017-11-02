#ifndef ITEMMOVEL_H
#define ITEMMOVEL_H
#include <iostream>

using namespace std;
//direcao de movimentacao para cada item
#define DIREITA 0
#define ESQUERDA 1
#define CIMA 2
#define BAIXO 3

class ItemMovel{//Representa um item que pode se locomover no mapa//itens moveis são movidos por uma entidade

public:
    ItemMovel();
    int getX();
    int getY();
    int getDirecao();
    void setX(int a);
    void setY(int b);
    void setDirecao(int dire);
protected:
    //x e y representam a linha e coluna que um emelento movel esteja
    int x,y;
    int direcao;
};

#endif // ITEMMOVEL_H

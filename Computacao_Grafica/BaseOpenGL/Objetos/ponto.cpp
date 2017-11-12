#include "ponto.h"

Ponto::Ponto(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    pointSize = 5;
    name = std::string("Ponto");
}

Ponto::Ponto()
{
    pointSize = 5;
    x = y = z = 0;
    name = std::string("Ponto");
}

void Ponto::printObjeto()
{
    if(color!=0)
        (*color)();
    else
        printf("[ALERTA] NAO FOI DEFINIDA UMA FUNCAO PARA SETAR A COR DE UM OBJETO DO TIPO: [%s]\n", name.c_str());
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    glVertex3f(x,y,z);
}

void Ponto::setX(double value)
{
    x = value;
}

void Ponto::setY(double value)
{
    y = value;
}

void Ponto::setZ(double value)
{
    z = value;
}

void Ponto::setPointSize(int value)
{
    if(value <= 0)throw std::string("O tamanho de um objeto nao pode ser menor ou igual a zero");
    pointSize = value;
}

double Ponto::getX()
{
    return x;
}

double Ponto::getY()
{
    return y;
}

double Ponto::getZ()
{
    return z;
}

int Ponto::getPointSize()
{
    return pointSize;
}

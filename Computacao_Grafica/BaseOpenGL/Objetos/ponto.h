#ifndef PONTO_H
#define PONTO_H
#include "templateobjeto.h"
#include <stdio.h>
class Ponto : public TemplateObjeto
{
public:
    Ponto(double x,double y,double z);
    Ponto();
    void printObjeto() override;

    void setX(double value);
    void setY(double value);
    void setZ(double value);
    void setPointSize(int value);

    double getX();
    double getY();
    double getZ();
    int getPointSize();

private:
    double x,y,z;
    int pointSize;
};

#endif // PONTO_H

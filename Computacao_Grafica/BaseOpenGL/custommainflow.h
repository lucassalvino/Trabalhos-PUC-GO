#ifndef CUSTOMMAINFLOW_H
#define CUSTOMMAINFLOW_H
#include <GL/glut.h>
#include "Objetos/ponto.h"
#define PRINTCOLUNA(C1, C2, AL)glPushMatrix();glTranslatef(C1,0,C2);Paralelo(AL,1,1);glPopMatrix();
using namespace std;
class CustomMainFlow
{
public:
    static void execute();
private:
    static void defaultPrinObjeto(TemplateObjeto* objeto);
    static void Paralelo(float comp, float lar, float alt);
};

#endif // CUSTOMMAINFLOW_H

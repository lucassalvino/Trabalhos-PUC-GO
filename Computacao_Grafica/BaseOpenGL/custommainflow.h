#ifndef CUSTOMMAINFLOW_H
#define CUSTOMMAINFLOW_H
#include <GL/glut.h>
#include "Objetos/ponto.h"
using namespace std;
class CustomMainFlow
{
public:
    static void execute();
private:
    static void defaultPrinObjeto(TemplateObjeto* objeto);
};

#endif // CUSTOMMAINFLOW_H

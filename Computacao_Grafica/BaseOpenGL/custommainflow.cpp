#include "custommainflow.h"

void CustomMainFlow::execute()
{
    Ponto a;
    a.setColor(_DEFINECOLOR::DEFINECOLOR::RED);
    defaultPrinObjeto(&a);
    Ponto b(1,1,1);
    b.setColor(_DEFINECOLOR::DEFINECOLOR::GREEN);
    defaultPrinObjeto(&a);

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(10.0, 10.0);
        glVertex2f(10.0, 0.0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(10.0, 10.0);
        glVertex2f(10.0, 20.0);
        glVertex2f(20.0, 20.0);
        glVertex2f(20.0, 10.0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.5, 0.5, 0.0);
        glTranslatef(-15.0,10.0,0.0);
        glRotatef (45.0, 0.0, 0.0, 1.0);
        glutSolidCube(4);
    glPopMatrix();
}

void CustomMainFlow::defaultPrinObjeto(TemplateObjeto *objeto)
{
    if(objeto == 0)throw string("O Objeto utilizado em [%s] nao foi incializado",__FUNCTION__);
    glPushMatrix();
    objeto->printObjeto();
    glEnd();
    glPopMatrix();
}

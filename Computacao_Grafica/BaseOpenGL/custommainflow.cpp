#include "custommainflow.h"

void CustomMainFlow::execute()
{
    using namespace _DEFINECOLOR;
    //glTranslatef(0.0,ALTURA,0.0);
    int tamanhoArena = 200; //tamanho da base do predio
    int ladoPredio = 8; //cumprimento do lado do predio
    int alturaPredio = 40; //altura do predio
    int numeroAndares = 20; //numero de andares
    float alturaAndar = (float)alturaPredio/(float)numeroAndares;
    /*CHAO*/
    glPushMatrix();
        DEFINECOLOR::BLACK();
        glTranslatef(tamanhoArena/2*-1,0,tamanhoArena/2*-1);
        glRotatef (0.0, 0.0, 0.0, 1.0);
        Paralelo(0.25,tamanhoArena,tamanhoArena);
    glPopMatrix();
    /*Colunas Principais*/
    DEFINECOLOR::YELLOW();
    PRINTCOLUNA(ladoPredio,ladoPredio, alturaPredio);
    PRINTCOLUNA(-1*ladoPredio,ladoPredio, alturaPredio);
    PRINTCOLUNA(ladoPredio,-1*ladoPredio, alturaPredio);
    PRINTCOLUNA(-1*ladoPredio,-1*ladoPredio, alturaPredio);
    /*ANDARES*/
    float baseAndar = alturaAndar;
    for(int i = 0; i<numeroAndares; i++, baseAndar+=alturaAndar){
        DEFINECOLOR::GRAY();
        glPushMatrix();
                glTranslated(ladoPredio+0.5,0,ladoPredio);
                Paralelo(baseAndar,(ladoPredio*-2),0.25);
        glPopMatrix();
        glPushMatrix();
                glTranslated((ladoPredio+0.5),0,0.75+(-1*ladoPredio));
                Paralelo(baseAndar,(ladoPredio*-2),0.25);
        glPopMatrix();
        glPushMatrix();
                glTranslated(ladoPredio+0.5,0,ladoPredio);
                glRotated(270,0,1,0);
                Paralelo(baseAndar,(ladoPredio*-2),0.25);
        glPopMatrix();
        glPushMatrix();
                glTranslated(-1*ladoPredio+0.5,0,0.75+ladoPredio);
                glRotated(270,0,1,0);
                Paralelo(baseAndar,(ladoPredio*-2),0.25);
        glPopMatrix();
    }
}

void CustomMainFlow::defaultPrinObjeto(TemplateObjeto *objeto)
{
    if(objeto == 0)throw string("O Objeto utilizado em [%s] nao foi incializado",__FUNCTION__);
    glPushMatrix();
    objeto->printObjeto();
    glEnd();
    glPopMatrix();
}

void CustomMainFlow::Paralelo(float comp, float lar, float alt)
{
    glBegin(GL_QUADS);
    glNormal3f(0,0,-1);
    glVertex3f(00, 0.0, 0.0);  glVertex3f(lar, 0.0, 0.0);
    glVertex3f(lar, comp, 0.0); glVertex3f(0.0, comp, 0.0);
    glNormal3f(0,0,1);
    glVertex3f(0.0, 0.0, alt);  glVertex3f(lar, 0.0, alt);
    glVertex3f(lar, comp, alt); glVertex3f(0.0, comp, alt);
    glNormal3f(-1,0,0);
    glVertex3f(0.0, 0.0, 0.0);  glVertex3f(0.0, 0.0, alt);
    glVertex3f(0.0, comp, alt); glVertex3f(0.0, comp, 0.0);
    glNormal3f(0,-1,0);
    glVertex3f(0.0, 0.0, 0.0);  glVertex3f(0.0, 0.0, alt);
    glVertex3f(lar, 0.0, alt);  glVertex3f(lar, 0.0, 0.0);
    glNormal3f(1,0,0);
    glVertex3f(lar, 0.0, 0.0);  glVertex3f(lar, 0.0, alt);
    glVertex3f(lar, comp, alt); glVertex3f(lar, comp, 0.0);
    glNormal3f(0,1,0);
    glVertex3f(0.0, comp, 0.0); glVertex3f(0.0, comp, alt);
    glVertex3f(lar, comp, alt); glVertex3f(lar, comp, 0.0);
    glEnd();
}

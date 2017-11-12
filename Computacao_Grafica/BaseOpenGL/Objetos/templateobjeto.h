#ifndef TEMPLATEOBJETO_H
#define TEMPLATEOBJETO_H
#include <iostream>
#include <GL/glut.h>
#include "../definecolor.h"
class TemplateObjeto
{
public:
    TemplateObjeto(){
        color = 0;
    }
    virtual void printObjeto(){throw std::string("DEFINICAO DE IMPRESSAO AINDA NAO FOI INICIALIZADA");}
    std::string getName(){
        return name;
    }
    void setColor(void (*colord)()){
        if(colord == 0)throw std::string("he necessario iniciar uma cor valida");
        color = colord;
    }
protected:
    std::string name;
    void (*color)();
};

#endif // TEMPLATEOBJETO_H

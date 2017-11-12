#ifndef CUSTOMDEFAULTSOPENGL_H
#define CUSTOMDEFAULTSOPENGL_H
#include<GL/glut.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include "custommainflow.h"
#include "BasisForDeveloping/config.h"
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
using namespace BaseDeveloping;
namespace CustomOpenGLDefault {
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a cÃ¢mera para essas variÃ¡veis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a cÃ¢mera para essas coordenadas*/
    glRotatef(rotY,0,1,0);
}

void Init(void){
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
    GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//FUNDO PRETO
    glShadeModel(GL_SMOOTH);//colorização de Gouraud
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    ANGULO = Config::getConfigFloat("ANGULO");
    rotX = rotY = 0;
    obsX = obsY = 0;
    obsZ = 60;
    escalaX = escalaY = escalaZ = 1;
}

void custonPrints(){
    CustomMainFlow::execute();
}

void glutDisplayFunc(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    custonPrints();
    glutSwapBuffers();
}

void resizeWindow(GLsizei w, GLsizei h){
    if (!h) h = 1;
    glViewport(0, 0, w, h);
    ASPECTO = (GLfloat)w/(GLfloat)h;
    EspecificaParametrosVisualizacao();
}
void glutIdleFunc(void){

}

void glutMouseFunc(int button, int state, int x, int y){
    if(state == GLUT_DOWN){
        x_ini = x;
        y_ini = y;
        obsX_ini = obsX;
        obsY_ini = obsY;
        obsZ_ini = obsZ;
        rotX_ini = rotX;
        rotY_ini = rotY;
        bot = button;
        printf("Button %s At %d %d\n", (state == GLUT_DOWN) ? "Down" : "Up", x, y);
    }else bot = -1;
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}
void glutKeyboardFunc(unsigned char key, int x, int y){
    key = toupper(key);
    switch (key) {
    case 27:
        exit(0);
        printf("[TECLA] ESC");
        break;
    case 'A':
        printf("[TECLA] A");
        break;
    case 'S':
        printf("[TECLA] S");
        break;
    case 'D':
        printf("[TECLA] D");
        break;
    case 'W':
        printf("[TECLA] W");
        break;
    case 'Q':
        printf("[TECLA] Q");
        break;
    case 'E':
        printf("[TECLA] E");
        break;
    default:
        printf("[TECLA] NAO MAPEADO [%c]",key);
        break;
    }
    printf("\t[%d][%d]\n",x,y);
}

void glutSpecialFunc(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_UP:
        printf("[TECLA] seta para cima");
        break;
    case GLUT_KEY_DOWN:
        printf("[TECLA] seta para baixo");
        break;
    case GLUT_KEY_LEFT:
        printf("[TECLA] seta para esquerda");
        break;
    case GLUT_KEY_RIGHT:
        printf("[TECLA] seta para direita");
        break;
    case GLUT_KEY_F1:
        printf("[TECLA] F1");
        break;
    case GLUT_KEY_F2:
        printf("[TECLA] F2");
        break;
    case GLUT_KEY_F3:
        printf("[TECLA] F3");
        break;
    case GLUT_KEY_F4:
        printf("[TECLA] F4");
        break;
    case GLUT_KEY_F5:
        printf("[TECLA] F5");
        break;
    case GLUT_KEY_F6:
        printf("[TECLA] F6");
        break;
    case GLUT_KEY_F7:
        printf("[TECLA] F7");
        break;
    case GLUT_KEY_F8:
        printf("[TECLA] F8");
        break;
    case GLUT_KEY_F9:
        printf("[TECLA] F9");
        break;
    case GLUT_KEY_F10:
        printf("[TECLA] F10");
        break;
    case GLUT_KEY_F11:
        printf("[TECLA] F11");
        break;
    case GLUT_KEY_F12:
        printf("[TECLA] F12");
        break;
    default:
        printf("[TECLA] NAO MAPEADO");
        break;
    }
    printf("\t[%d][%d]\n",x,y);
}

void glutMotionFunc(int x, int y){
    if(bot == GLUT_LEFT_BUTTON){//RotaÃ§Ã£o
        int deltaX = x_ini - x;
        int deltaY = y_ini - y;
        rotX = rotX_ini - deltaY/ SENS_ROT;
        rotY = rotY_ini - deltaX/ SENS_ROT;
    }
    else if (bot == GLUT_RIGHT_BUTTON){//Zoom
        int deltaZ = y_ini - y;
        obsZ = obsZ_ini + deltaZ/ SENS_OBS;
    }
    else if (bot == GLUT_MIDDLE_BUTTON){//Correr
        int deltaX = x_ini - x;
        int deltaY = y_ini - y;
        obsX = obsX_ini + deltaX/ SENS_TRANS;
        obsY = obsY_ini + deltaY/ SENS_TRANS;
    }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}
}
#endif // CUSTOMDEFAULTSOPENGL_H

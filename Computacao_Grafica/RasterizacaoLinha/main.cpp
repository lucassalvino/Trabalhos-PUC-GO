#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <ctime>

inline void mySleep(clock_t sec) // clock_t is a like typedef unsigned int clock_t. Use clock_t instead of integer in this context
{
    clock_t start_time = clock();
    clock_t end_time = sec * 1000 + start_time;
            while(clock() != end_time);
}
using namespace std;
#define X 800
#define Y 600
#define LIMITEXSUPERIOR 10
#define LIMITEXINFERIOR -10
#define LIMITEYSUPERIOR 10
#define LIMITEYINFERIOR -10
class retangulo{
public:
    float x0,x1,y0,y1;
};
float distanciaLinhas = 1;
int pontosCLick = 0;


list<retangulo> retangulos;
list<retangulo> desenharTela;


void desenhaLinha(float x1,float y1, float x2, float y2);
float xMouseToCoordinate(float x){
    return (x * ((float)LIMITEXSUPERIOR - (float)LIMITEXINFERIOR) / (float)X + (float)LIMITEXINFERIOR);
}
float yMouseToCoordinate(float y){
    return (((float)Y - y) * ((float)LIMITEYSUPERIOR - (float)LIMITEYINFERIOR) / (float)Y + LIMITEYINFERIOR);
}
void adicionaPintar(retangulo* add, bool soma){
    if(add == 0)return;
    if(pontosCLick < 3){
        desenharTela.push_back(*add);
        if (soma)
            pontosCLick++;
        if(pontosCLick == 2 && soma){
            list<retangulo>::iterator it = desenharTela.begin();
            float a,b,c,d;
            a = it->x0;
            b = it->y0;
            it++;
            c = it->x0;
            d = it->y0;
            desenhaLinha(a,b,c,d);
        }
    }
    else{
        desenharTela.clear();
        pontosCLick = 0;
        //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
}

void pintaQuadrado(retangulo* coo){
    if(coo == 0)return;
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);//vermelho
    glVertex2f(coo->x0,coo->y0);
    glVertex2f(coo->x0,coo->y1);
    glVertex2f(coo->x1,coo->y0);
    glVertex2f(coo->x1,coo->y1);
    glEnd();
}
void pintaPonto(int a, int b){
    glColor3f(1.0f, 0.0f, 0.0f);//vermelho
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2f(a,b);
    glEnd();
}

void pintarAlemDaGrade(){
    for(list<retangulo>::iterator it = desenharTela.begin();it!=desenharTela.end();it++){
        pintaQuadrado(&(*it));
    }
}

void calculaRetandulos(){
    retangulos.clear();
    float x = -9;
    for (int i = 0; x<=9 ;i++, x+=distanciaLinhas){
        float y = 9;
        for(int j = 0 ;y>=-9;j++,y-=distanciaLinhas){
            retangulo add;
            add.x0 = x;
            add.x1 = x + distanciaLinhas;
            add.y0 = y;
            add.y1 = y - distanciaLinhas;
            retangulos.push_back(add);
        }
    }
}

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    if (((abs(x) >= abs(x0)) && (abs(x) <= abs(x1))) && ((abs(y) >= abs(y0)) && (abs(y) <= abs(y1)))){
        return 1;
    }else{
        return 0;
    }
}

retangulo* click(float x,float y){
    retangulo * a = new retangulo();
    x = floor(x);
    y = floor(y);
    a->x0 = x;
    a->x1 = x+distanciaLinhas;
    a->y0 = y;
    a->y1 = y+distanciaLinhas;
    return a;
}
void desenhaGrade()
{
    glColor3f(0.8f,0.8f,0.8f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    float x = LIMITEXINFERIOR;
    for(;x<=LIMITEXSUPERIOR; x+=distanciaLinhas)
    {
        glVertex2f(LIMITEXINFERIOR,x);
        glVertex2f(LIMITEXSUPERIOR,x);
        glVertex2f(x,LIMITEYINFERIOR);
        glVertex2f(x,LIMITEYSUPERIOR);
    }
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(LIMITEXINFERIOR,0);
    glVertex2f(LIMITEXSUPERIOR,0);
    glVertex2f(0,LIMITEYINFERIOR);
    glVertex2f(0,LIMITEYSUPERIOR);
    glEnd();
}

void DesenhaNaTela(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaGrade();
    pintarAlemDaGrade();
    glutSwapBuffers();
}

void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    calculaRetandulos();
    gluOrtho2D(LIMITEXINFERIOR,LIMITEXSUPERIOR,LIMITEYINFERIOR,LIMITEYSUPERIOR);
    glMatrixMode(GL_MODELVIEW);
}

void TeclaEspeciais(int key, int x, int y){
    if(key == GLUT_KEY_UP) {
        distanciaLinhas += 0.5;
        if(distanciaLinhas <= 0) distanciaLinhas = 0.5;
        printf("[INFO] Distancia entre as linhas de [%.2f]\n",distanciaLinhas);
        printf("[%d][%d]\n",x,y);
    }
    if(key == GLUT_KEY_DOWN) {
        distanciaLinhas -=  0.5;
        if(distanciaLinhas <= 0) distanciaLinhas = 0.5;
        printf("[INFO] Distancia entre as linhas de [%.2f]\n",distanciaLinhas);
        printf("[%d][%d]\n",x,y);
    }
}

void CliqueMouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            glMatrixMode(GL_PROJECTION);
            printf("Botão esquerdo [%i][%i]\t[%.2f][%.2f]\n",x,y, xMouseToCoordinate(x), yMouseToCoordinate(y));
            adicionaPintar(click(xMouseToCoordinate(x), yMouseToCoordinate(y)),true);
        }else
            if (state == GLUT_UP){
                printf("Botão esquerdo livre\n");
            }
    }else if(button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN){
            printf("Botão direito [%i][%i]\n",x,y);
        }else
            if(state == GLUT_UP){
                printf("Botão direito livre\n");
            }
    }else if (button == GLUT_MIDDLE_BUTTON){
        if(state == GLUT_DOWN){
            printf("Botão do meio [%i][%i]\n",x,y);
        }else
            if(state == GLUT_UP){
                printf("Botão do meio livre\n");
            }
    }
}
float xMedio(float x0, float x1){
    return (x0+x1)/2.0;
}
float yMedio(float y0, float y1){
    return (y0+y1)/2.0;
}
float distanciaEntrePontos(float x1,float y1, float x2, float y2){
    return pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ,0.5);
}

void desenhaLinha(float x1,float y1, float x2, float y2){
    if(distanciaEntrePontos(x1,y1,x2,y2)>distanciaLinhas){
        float xm = xMedio(x1,x2);
        float ym = yMedio(y1,y2);
        adicionaPintar(click(xm,ym),false);
        desenhaLinha(x1,y1,xm,ym);
        desenhaLinha(xm,ym,x2,y2);
    }else{
        return;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(X,Y);
    glutCreateWindow("Rasterizacao");
    glutDisplayFunc(DesenhaNaTela);
    glutIdleFunc(DesenhaNaTela);
    glutMouseFunc(CliqueMouse);
    glutSpecialFunc(TeclaEspeciais);
    Inicializa();
    glutMainLoop();
}

// Iluminacao.c - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualização
// de objetos 3D com a inserção de uma fonte de luz.
// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;

GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;

#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0

// Enumera as ações do humanoide
//  Angulos de visualização do observador
float obsteta = 0.79, obsfi = 1.5, distancia = 800.0;
// Ângulo do tronco
float TR = 0;
// Ângulos do ombro, cotovelo, mão, pé, perna, perna1, joelho, tornozelo esquerdo
float OE = 0.0, CE = 0.0, ME = 0.0, PE = 0.0, PE1 = 0.0, JE = 0.0, TE = 0.0;
float OE1 =0;
// Ângulos do ombro, cotovelo, mão, pé, perna, perna1, joelho, tornozelo direito
float OD = 0.0, CD = 0.0, MD = 0.0, PD = 0.0, PD1 = 0.0, JD = 0.0, TD = 0.0;
float OD1 =0;

//quadril FRENTE, quadril lado
float AQF = 0, AQL = 0, CA = 0, CA1 = 0, QU = 0;

char ultimo = 'r';


void updateRotacao(char letra, bool voltar){
    if (letra == 'w' || letra == 'W'){
        if(voltar){
            CE-=2;
        }
        else{
            CE+=2;
        }
        return;
    }
    if (letra == 'e' || letra == 'E'){
        if(voltar){
            OE-=2;
        }
        else{
            OE+=2;
        }
        return;
    }
    if (letra == 's' || letra == 'S'){
        if(voltar){
            CD-=2;
        }
        else{
            CD+=2;
        }
        return;
    }
    if (letra == 'q' || letra == 'Q'){
        if(voltar){
            OD-=2;
        }
        else{
            OD+=2;
        }
        return;
    }
    if (letra == 'r' || letra == 'R'){
        if(voltar){
            JE-=2;
        }
        else{
            JE+=2;
        }
        return;
    }
    if (letra == 't' || letra == 'T'){
        if(voltar){
            PD-=2;
        }
        else{
            PD+=2;
        }
        return;
    }
    if (letra == 'f' || letra == 'F'){
        if(voltar){
            JD-=2;
        }
        else{
            JD+=2;
        }
        return;
    }
    if (letra == 'g' || letra == 'G'){
        if(voltar){
            PE-=2;
        }
        else{
            PE+=2;
        }
        return;
    }
    if (letra == 'c' || letra == 'C'){
        if(voltar){
            CA-=2;
        }
        else{
            CA+=2;
        }
        return;
    }
    if (letra == 'x' || letra == 'X'){
        if(voltar){
            CA1-=2;
        }
        else{
            CA1+=2;
        }
        return;
    }
    if (letra == 'y' || letra == 'Y'){
        if(voltar){
            PE1-=2;
        }
        else{
            PE1+=2;
        }
        return;
    }
    if (letra == 'h' || letra == 'H'){
        if(voltar){
            PD1-=2;
        }
        else{
            PD1+=2;
        }
        return;
    }
    if (letra == 'n' || letra == 'N'){
        if(voltar){
            OE1-=2;
        }
        else{
            OE1+=2;
        }
        return;
    }
    if (letra == 'm' || letra == 'M'){
        if(voltar){
            OD1-=2;
        }
        else{
            OD1+=2;
        }
        return;
    }
}

void Teclado(unsigned char tecla, int x, int y){
    x = y;
    if(tecla == 27){
        exit(0);
    }
    ultimo = tecla;
    updateRotacao(tecla, tecla>90);
    glutPostRedisplay();
}
void mouseWheel()
{
    updateRotacao(ultimo, ultimo>90);
    return;
}


// Cria Paralelepípedos
void Paralelo(float comp, float lar, float alt)
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

void Humanoide(void)
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(AQF, 0.0, 1.0, 0.0);
    Paralelo(25.0, 15.0, 25.0); //     Tronco

    glPopMatrix();
    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glRotatef(AQF, 0.0, 1.0, 0.0);
    glTranslatef(7.0, 12.5, -6.0);

    glPushMatrix();
    glutSolidSphere(7.0,  20,  20);  //  Colo

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(0.0, 6, -8.0);
    glRotatef(PE, 0.0, 1.0, 0.0);
    glRotatef(PE1, 1.0, 0.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Articulação da Perna Esquerda

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -28.0);
    Paralelo(8.0, 8.0, 25.0);          //  Perna Esquerda


    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -3.0);
    glRotatef(JE, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Joelho


    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -28.0);
    Paralelo(8.0, 8.0, 25.0);   //  Canela

    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -3.0);
    glRotatef(TE, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Tornozelo

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-6.0, -5.0, -8.0);
    Paralelo(10.0, 18.0, 5.0);  //  Pé

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(0.0, -6.0, -8.0);
    glRotatef(PD, 0.0, 1.0, 0.0);
    glRotatef(PD1, 1.0, 0.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0); //  Articulação da Perna direita

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -28.0);
    Paralelo(8.0, 8.0, 25.0);          //  Perna Direita

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -3.0);
    glRotatef(JD, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Joelho Direito

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -28.0);
    Paralelo(8.0, 8.0, 25.0);       //  Canela

    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -3.0);
    glRotatef(TD, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Tornozelo

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-6.0, -5.0, -8.0);
    Paralelo(10.0, 18.0, 5.0);      //  Pé

    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(0.0, -17.0, 27.0);
    glRotatef(OD, 0.0, 1.0, 0.0);
    glRotatef(OD1, 1.0, 0.0, 0.0);
    glutSolidSphere(5.0,  20.0,  20.0);    //Ombro Direito

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -20.0);
    Paralelo(7.0, 7.0, 16);     //  Anti-braço

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO;
    glTranslatef(4.0, 3.0, -3.0);
    glRotatef(CD, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Cotovelo

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -19.0);
    Paralelo(8.0, 8.0, 16.0);        //  Braço

    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -2.0);
    glRotatef(MD, 0.0, 1.0, 0.0);
    glutSolidSphere(3.0, 20.0, 20.0);  //  Monheca

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -2.0, -12.0);
    Paralelo(4.0, 8.0, 10.0);       //  Mão

    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(0.0, 17.0, 27.0);
    glRotatef(OE, 0.0, 1.0, 0.0);
    glRotatef(OE1, 1.0, 0.0, 0.0);
    glutSolidSphere(5.0,  20.0,  20.0);    //Ombro Esquerdo

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -3.0, -20.0);
    Paralelo(7.0, 7.0, 16.0);       //  Anti-braço

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(4.0, 4.0, -3.0);
    glRotatef(CE, 0.0, 1.0, 0.0);
    glutSolidSphere(4.0,  20.0,  20.0);  //  Cotovelo

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -4.0, -19.0);
    Paralelo(8.0, 8.0, 16.0);       //  Braço

    glColor3f(255.0, 255.0, 0.0); // AMARELO;
    glTranslatef(4.0, 4.0, -2.0);
    glRotatef(ME, 0.0, 1.0, 0.0);
    glutSolidSphere(3.0,  20.0,  20.0);  //  Monheca

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-4.0, -2.0, -12.0);
    Paralelo(4.0, 8.0, 10.0);     //  Mão
    glPopMatrix();
    glPopMatrix();

    glColor3f(255.0, 255.0, 0.0); // AMARELO
    glTranslatef(0.0, 0.0, 33.0);
    glRotatef(CA,0,0,1);
    glRotatef(CA1,0,1,0);
    glutSolidSphere(4.0,  20.0,  20.0);    //Pescoço

    glColor3f(0.0, 0.0, 0.0);     // PRETO
    glTranslatef(-6.0, -6.0, 3.0);
    Paralelo(12.0, 12.0, 12.0);      //  Cabeça
    glColor3f(255.0, 255.0, 0.0);
    glTranslatef(0.5, 2, 8);
    glutSolidSphere(2.0,  20,  20);
    glTranslatef(0.5, 4, 2);
    glutSolidSphere(2.0,  20,  20);
    glPopMatrix();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
    GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;

    // Especifica que a cor de fundo da janela será preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT1);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

    //angle=45;
    ANGULO = 45;
    rotX = 0;
    rotY = 0;
    obsX = 0;
    obsY = 0;
    obsZ = 60;//Voltar para 10
    escalaX = escalaY = escalaZ = 2;


}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();

    // Especifica posição do observador e do alvo
    gluLookAt(0,0,80,0,0,0, 0,1,0);
    gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,1);
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a cÃ¢mera para essas variÃ¡veis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a cÃ¢mera para essas coordenadas*/
    glRotatef(rotY,0,0,1);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;

    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto
    //fAspect = (GLfloat)w/(GLfloat)h;
    ASPECTO = (GLfloat)w/(GLfloat)h;

    EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    /*if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {  // Zoom-in
            if (angle >= 10) angle -= 5;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) {  // Zoom-out
            if (angle <= 130) angle += 5;
        }*/

    if ((button == 3) || (button == 4)) // It's a wheel event
    {
        // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
        if (state == GLUT_UP) mouseWheel(); // Disregard redundant GLUT_UP events
    }else{  // normal button event
        if(state == GLUT_DOWN){
            x_ini = x;
            y_ini = y;
            obsX_ini = obsX;
            obsY_ini = obsY;
            obsZ_ini = obsZ;
            rotX_ini = rotX;
            rotY_ini = rotY;
            bot = button;
        }
        else bot = -1;
    }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void motion(int x, int y){
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


void desenhaTudo(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/*Relacionada ao buffer de renderização*/
    Humanoide();
    glutSwapBuffers();
}

// Programa Principal
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    //glutInitWindowPosition(150, 50);
    glutCreateWindow("HUMANOIDE");
    glutDisplayFunc(desenhaTudo);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(Teclado);
    glutMouseFunc(GerenciaMouse);
    glutMotionFunc(motion);
    Inicializa();
    glutMainLoop();
}


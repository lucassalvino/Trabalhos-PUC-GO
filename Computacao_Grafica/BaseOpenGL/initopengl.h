#ifndef INITOPENGL_H
#define INITOPENGL_H
#include "BasisForDeveloping/config.h"
#include "customdefaultsopengl.h"
#include "custommainflow.h"
#include <GL/glut.h>

using namespace BaseDeveloping;
void initOpenGLFromConfigFile(int argc, char** argv ){
    Config::loadConfigFromFile();
    if(Config::getNumConfig()==0)
        throw new std::string("Nao he possivel carregar as configuracoes a partir do arquivos de Configuracoes :"+Config::getPathFile());
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(Config::getConfigInt("X"),Config::getConfigInt("Y"));
    glutCreateWindow(Config::getConfig("Title").c_str());
    glutDisplayFunc(CustomOpenGLDefault::glutDisplayFunc);
    glutIdleFunc(CustomOpenGLDefault::glutIdleFunc);
    glutReshapeFunc(CustomOpenGLDefault::resizeWindow);
    glutMouseFunc(CustomOpenGLDefault::glutMouseFunc);
    glutMotionFunc(CustomOpenGLDefault::glutMotionFunc);
    glutSpecialFunc(CustomOpenGLDefault::glutSpecialFunc);
    glutKeyboardFunc(CustomOpenGLDefault::glutKeyboardFunc);
    CustomOpenGLDefault::Init();
}
#endif // INITOPENGL_H

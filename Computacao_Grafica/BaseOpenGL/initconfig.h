#ifndef INITCONFIG_H
#define INITCONFIG_H
#include "BasisForDeveloping/config.h"
#include <GL/glut.h>
using namespace BaseDeveloping;
void initConfig(){
    Config::verifyFileConfig();
    Config::loadConfigFromFile();
    if(!Config::getNumConfig()){
        Config::setConfig("X",800);
        Config::setConfig("Y",600);
        Config::setConfigUl("DisplayMode", GLUT_SINGLE | GLUT_RGB);
        Config::setConfig("Title","OPENGL");
        Config::setConfig("ANGULO",45);
    }
    Config::saveConfig();
}
#endif // INITCONFIG_H

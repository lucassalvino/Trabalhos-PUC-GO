#include <iostream>
#include <stdio.h>
#include "BasisForDeveloping/config.h" //https://github.com/lucassalvino/myLibraries/tree/master/BasisForDeveloping
#include "initconfig.h"
#include "initopengl.h"
using namespace BaseDeveloping;
using namespace std;

int main(int argc, char *argv[])
{
    initConfig();
    initOpenGLFromConfigFile(argc,argv);
    glutMainLoop();
    return 0;
}

#include "utilidades.h"

char Utilidades::getch()//retorna o primeiro caractere do bufferm sem a necessidade de realizar a leitura do ENTER
{
    char buf=0;
    struct termios old;//{0}
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}


void Utilidades::pausa (float delay1) {//pausa o jogo pelo delay em segundos

    if (delay1<0.001) return; // delay menores que 0.001 segundos são iguinorados.

    float inst1=0, inst2=0;

    inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

    while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

    return;

}

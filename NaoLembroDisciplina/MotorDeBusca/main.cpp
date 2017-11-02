#include "janelaprincipal.h"
#include <QApplication>
#include <cstdio>
#include "excecaonaotratada.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JanelaPrincipal w;
    inicio:
    try{
        w.show();
    }
    catch(string a){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(a);
        oi->show();
    }
    catch(...){
        printf("\nerro inesperado em main()\n");
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada("erro inesperado em main()");
        oi->show();
        goto inicio;

    }

    return a.exec();

}

/*
 * codigos tratamento de excessoes:
 * 00 tabela hash cheia
 * 01 item não existe na tabela
 * 10 arquivo não existe
*/
/*bug com ifen para resolver*/

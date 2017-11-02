#ifndef GERADORSEQUENCIA_H
#define GERADORSEQUENCIA_H
#include "dados.h"
#include <stdlib.h>
#include <time.h>

class GeradorSequencia{
public:
    static void gerarSequencias();
private:
    static bool verificaElementoParaAdiconar(int &tentandoAdicionara, UmaSolucao& at);
    static bool jaExisteNaSolucao(int elemento, UmaSolucao&at);
    static int getNumero(int somatorioAt, int faltam);
    static void verificaQuantidadeNumero(UmaSolucao& at);
    static void verificaSomaSolucao(UmaSolucao& at);
};

#endif // GERADORSEQUENCIA_H

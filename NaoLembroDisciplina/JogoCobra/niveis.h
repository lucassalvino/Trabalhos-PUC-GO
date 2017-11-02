#ifndef NIVEIS_H
#define NIVEIS_H
#include "mapa.h"
#include "data.h"
#include "modotexto.h"

/*representar niveis de dificuldade para o jogo*/
#define ARQ_NIVEIS "Config/0.txt"//nome padrao dos arquivos de niveis
#define POS_ADD 7
class Niveis
{
public:
    static void proxNivel();
    static int getNivelAtual();
    static string getCaminho();
private:
    static int nivelAtual;
    static string caminho;

    static void _atualizaMapa();
    static void _atualizaJogador();
};

#endif // NIVEIS_H

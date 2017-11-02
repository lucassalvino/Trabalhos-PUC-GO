#include "avancarnivel.h"
int AvancarNivel::fatorNivel = 250;
bool AvancarNivel::analisaDados()
{
    if(Data::jogador.getPontuacao() >= (Niveis::getNivelAtual()*fatorNivel)){
        Niveis::proxNivel();
        return true;
    }
    return false;
}

int AvancarNivel::getFatorNivel()
{
    return fatorNivel;
}

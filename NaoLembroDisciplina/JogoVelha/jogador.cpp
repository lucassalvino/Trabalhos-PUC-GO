#include "jogador.h"

Jogador::Jogador()
{

}

int Jogador::getPontosGanhos() const
{
    return pontosGanhos;
}

void Jogador::setPontosGanhos(int value)
{
    pontosGanhos = value;
}

string Jogador::getNome() const
{
    return nome;
}

void Jogador::setNome(const string &value)
{
    nome = value;
}

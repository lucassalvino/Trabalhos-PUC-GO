#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
using namespace std;

class Jogador
{
public:
    Jogador();
    int getPontosGanhos() const;
    void setPontosGanhos(int value);

    string getNome() const;
    void setNome(const string &value);

private:
    string nome;
    int pontosGanhos;
};

#endif // JOGADOR_H

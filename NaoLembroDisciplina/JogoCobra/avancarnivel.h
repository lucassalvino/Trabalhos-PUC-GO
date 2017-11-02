#ifndef AVANCARNIVEL_H
#define AVANCARNIVEL_H
#include "data.h"
#include "utilidades.h"
#include "niveis.h"
class AvancarNivel
{
public:
    static bool analisaDados();
    static int getFatorNivel();

private:
    static int fatorNivel;
};

#endif // AVANCARNIVEL_H

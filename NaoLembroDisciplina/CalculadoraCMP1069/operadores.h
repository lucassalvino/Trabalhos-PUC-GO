#ifndef OPERADORES_H
#define OPERADORES_H

#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;
//realisar include de operadores.hpp
/*definição das operações aceitas para a calculadora:
+
-
/
*
^
*/

#define TEMPLATE_CLASS_OPERADORES template<class TIPO>

TEMPLATE_CLASS_OPERADORES
class Operadores
{
    /*
     * classe opera somente com valores numericos
     *  int, float
     * caso utilize valores não numericos, implementar sobrecarga para
     *  adição -> +
     *  subtração -> -
     *  multiplicaçao -> *
     *  divisao -> /
     *  função pow
     *  comparação-> == !=
     */
public:
    static TIPO somar(TIPO a, TIPO b);
    static TIPO subtrair(TIPO a, TIPO b);
    static TIPO dividir(TIPO a,TIPO b);
    static double dividirRetornoPontoFlutuane(TIPO a,TIPO b);
    static TIPO multiplicar(TIPO a,TIPO b);
    static TIPO potencia(TIPO a,TIPO b);
};

#endif // OPERADORES_H

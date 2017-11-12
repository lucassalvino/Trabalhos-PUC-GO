// UPDATE VERSION IN https://github.com/lucassalvino/myLibraries/tree/master/BasisForDeveloping
#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <exception>

#define MAX(A,B) A>B?A:B
#define MIN(A,B) A>B?B:A
#define FOR_I(N) for(int i = 0; i<N; i++)
#define FOR_J(N) for(int j = 0; j<N; j++)
#define FOR_CONT(N) for(int cont = 0; cont<N; cont++)

#define __TOSTRING std::stringstream Resultado; Resultado << value; return Resultado.str()
#define __NUMBERTOSTRING(TypeRet) std::istringstream buffer(value); TypeRet ret; buffer >> ret; return ret
#define __TONUMBER(TypeRet) return (TypeRet)value

namespace BaseDeveloping {
class Utility
{
public:
    static double fRand(double fMin, double fMax);

    static int randomNumPossion(double lambida, double fminRand, double fmaxRand);

    class Convert{
    public:
        static std::string ToString(int value){__TOSTRING;}
        static std::string ToString(float value){__TOSTRING;}
        static std::string ToString(double value){__TOSTRING;}
        static std::string ToString(char value){__TOSTRING;}
        static std::string ToString(bool value){return value?std::string("true"):std::string("false");}
        static std::string ToString(unsigned int value){__TOSTRING;}
        static std::string ToString(long int value){__TOSTRING;}

        static int ToInt(std::string value){__NUMBERTOSTRING(int);}
        static int ToInt(float value){__TONUMBER(int);}
        static int ToInt(double value){__TONUMBER(int);}
        static int ToInt(char value){__TONUMBER(int);}
        static int ToInt(bool value){__TONUMBER(int);}

        static float ToFloat(std::string value){{__NUMBERTOSTRING(float);}}
        static double ToDouble(std::string value){{__NUMBERTOSTRING(double);}}
    };
};
}
#endif // UTILITY_H

#ifndef RETORNO_H
#define RETORNO_H
#include "palavradocumento.h"
#include "documento.h"

#include <iostream>
using namespace std;
class Retorno
{
public:
    Retorno();
    void setRelevancia(float);
    float getRelevancia();
    void setDocumentoRetorno(Documento*);
    Documento* getDocumentoRetorno();
private:
     Documento *documentoRetorno;
     float relevancia;
};

#endif // RETORNO_H

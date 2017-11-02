#include "retorno.h"

Retorno::Retorno()
{
    relevancia = 0;
}

void Retorno::setRelevancia(float a){
    relevancia  = a;
}

float Retorno::getRelevancia(){
    return relevancia;
}

void Retorno::setDocumentoRetorno(Documento* a){
    documentoRetorno = a;
}

Documento* Retorno::getDocumentoRetorno(){
    return documentoRetorno;
}

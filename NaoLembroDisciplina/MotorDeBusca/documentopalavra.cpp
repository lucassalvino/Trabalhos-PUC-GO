#include "documentopalavra.h"

DocumentoPalavra::DocumentoPalavra()
{
    this->numeroVezesPalavra=0;
}
Documento * DocumentoPalavra::getDocumento(){
    return this->documento;
}

int DocumentoPalavra::getNumeroVezesPalavra(){
    return this->numeroVezesPalavra;
}

void DocumentoPalavra::setDocumento(Documento* orig){
    this->documento = orig;
}

void DocumentoPalavra::setNumeroVezesPalavra(int num){
    this->numeroVezesPalavra = num;
}

void DocumentoPalavra::incrementaNumeroVezesPalavra(){
    this->numeroVezesPalavra++;
}

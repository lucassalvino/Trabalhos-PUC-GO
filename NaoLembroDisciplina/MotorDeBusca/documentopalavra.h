#ifndef DOCUMENTOPALAVRA_H
#define DOCUMENTOPALAVRA_H

#include "documento.h"
class DocumentoPalavra
{
public:
    DocumentoPalavra();
    Documento * getDocumento();
    int getNumeroVezesPalavra();
    void setDocumento(Documento*);
    void setNumeroVezesPalavra(int);
    void incrementaNumeroVezesPalavra();
private:
    Documento * documento;
    int numeroVezesPalavra;
};

#endif // DOCUMENTOPALAVRA_H

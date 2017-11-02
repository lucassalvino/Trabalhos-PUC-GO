#include "documento.h"
Documento::Documento(char  caminho[]){
    strcpy(this->caminho, caminho);
    this->palavrasDistintas = 0;
}

int Documento::getPalavrasDistintas(){
    return this->palavrasDistintas;
}

char * Documento::getCaminho(){
    return this->caminho;
}

void Documento::setPalavrasDistintas(int pal){
    this->palavrasDistintas = pal;
}

void Documento::incrementaPalavrasDistintas(){
    this->palavrasDistintas++;
}

#include "nodoc.h"

TEMPLATE_NODOC
NoDoc<KEY,GIVEN>::NoDoc(KEY ch,GIVEN dad){
    this->chave = ch;
    this->dado = dad;
}

TEMPLATE_NODOC
NoDoc<KEY,GIVEN>::NoDoc(KEY ch){
    this->chave = ch;
}

TEMPLATE_NODOC
NoDoc<KEY,GIVEN>::NoDoc(){
    return;
}

TEMPLATE_NODOC
KEY NoDoc<KEY,GIVEN>::getChave(){
    return this->chave;
}

TEMPLATE_NODOC
GIVEN NoDoc<KEY,GIVEN>::getDado(){
    return this->dado;
}

TEMPLATE_NODOC
void NoDoc<KEY,GIVEN>::setChave(KEY ch){
    this->chave = ch;
}

TEMPLATE_NODOC
void NoDoc<KEY,GIVEN>::setDado(GIVEN dad){
    this->dado = dad;
}

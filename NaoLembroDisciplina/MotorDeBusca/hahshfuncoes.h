#ifndef HAHSHFUNCOES_H
#define HAHSHFUNCOES_H

#include <cmath>
/* int */
int hash1(int chave,int n){
    return chave%n;
}
int hashChave(int chave){
    return chave * 5 + 1;
}

int hash2(int chave,int tentativa,int n){
    return (hash1(chave,n) + tentativa*tentativa*hashChave(chave) + tentativa*hash1(chave,n))%n;
}

/* string */
int hash1(char chave[],int n){
    long long soma=0;
    //fazer um polimonio
    for(int i=0;chave[i]!='\0';i++){
        soma+=((i+1)*pow(chave[i],i));
    }
    return soma%n;
}
int hashChave(char chave[]){
    int soma=0;
    for(int i=0;chave[i]!='\0';i++){
        soma+=chave[i];
    }
    return soma%11;
}
int hash2(char chave[],int tentativa,int n){
    int resulHash1=hash1(chave,n);
    return (resulHash1 + tentativa*tentativa*hashChave(chave) + tentativa*resulHash1)%n;
}

#endif // HAHSHFUNCOES_H

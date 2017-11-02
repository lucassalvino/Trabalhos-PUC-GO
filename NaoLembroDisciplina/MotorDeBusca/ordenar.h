#ifndef ORDENAR
#define ORDENAR
#include "retorno.h"
#define TEMPLATE template <class T>

TEMPLATE
void troca(T v[],int i,int j){
    T aux = v[i];
    v[i]=v[j];
    v[j]=aux;
}

TEMPLATE
void maxHeap(T v[], int n, int i,int(*compare)(T,T)){
    int p=i;
    int e=i+i+1;
    if(e<n){
        if((*compare)(v[p],v[e])<0){//aki/////primeiro maior que segundo retorna >0 v[p]<v[e]
            p = e;
        }
        int d = i+i+2;
        if(d<n){
            if((*compare)(v[p],v[d])<0){//aki//v[p]<v[d]
                p=d;
            }
        }
        if(p!=i){
            troca(v,p,i);
            maxHeap(v,n,p,compare);
        }
    }
}

TEMPLATE
void construirHeap(T v[],int n,int(*compare)(T,T)){
    for(int i=(n-2)/2;i>=0;i--){
        maxHeap(v,n,i,compare);
    }
}

TEMPLATE
void heapSort(T v[],int n,int(*compare)(T,T)){
    construirHeap(v,n,compare);
    for(int i=1;i<=n;i++){
        troca(v,0,n-i);
        maxHeap(v,n-i,0,compare);
    }
}
#endif // ORDENAR


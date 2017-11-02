#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "nodoc.hpp"

#define TEMPLATE_TABELA template <class KEY, class GIVEN>
#define EX_OCUPADO (NoDoc<KEY,GIVEN>*)-1
//(NoDoc<KEY,GIVEN>*)-1
TEMPLATE_TABELA
class Tabelahash
{
public:
    Tabelahash();
    Tabelahash(int);
    ~Tabelahash();
    void clean();
    void inicializarTabela(int);
    void setIten(KEY,GIVEN);
    GIVEN getIten(KEY);
    inline int getTamanhoTabela(){return n;}
    inline int size(){return elementos;}
    void setFuncoesHash(int (*hah1)(KEY));
    void setCompare(int (*comp)(KEY,KEY));
    bool itemExiste(KEY);
    GIVEN remove(KEY);
    KEY* getKeys();
    int cont;
    inline GIVEN operator [] (KEY ch){return getIten(ch);}
    //inline void operator [] (Tabelahash& tabe, KEY ch, GIVEN da){tabe.setIten(ch,da);}
    //Tabelahash& operator [] (Tabelahash& ta,KEY ch, GIVEN da){setIten(ch,da);return ta;}
private:
    int (*hash1)(KEY);
    int (*compare)(KEY,KEY);
    int hash2(KEY,int);
    int n,elementos;
    NoDoc<KEY,GIVEN> **tabela;
    bool ehPrimo(int);
    void proximoPrimo(int&);
    bool estaOcupado(int);
    int buscarItem(KEY);
    double multiplica;
    NoDoc<KEY,GIVEN>* INVAL;
};

#endif // TABELAHASH_H

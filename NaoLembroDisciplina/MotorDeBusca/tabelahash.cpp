#include "tabelahash.h"

template <class KEY>
int genericCompare(KEY a, KEY b){
    if(a>b)return 1;
    if(a<b)return -1;
    return 0;
}

template <class KEY>
int genericHash1(KEY chave){
    char *test = (char*)&chave;
    int cha=0;
    for(int i=0;i<(int)sizeof(KEY);i++){
        cha+= test[i] + test[i]*i;
    }
    cha*=3;
    return cha;
}

TEMPLATE_TABELA
int Tabelahash<KEY,GIVEN>::hash2(KEY chave, int tentativa){
    int resuChave = ((*hash1)(chave));
    resuChave = resuChave*CONSTANTE1_HASH;
    resuChave = ((resuChave%n) + CONSTANTE2_HASH*resuChave + resuChave*tentativa*tentativa )%n;
    if(resuChave<0)resuChave*=-1;
    return resuChave;
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::setIten(KEY chave,GIVEN dado){
    int posi = hash2(chave,0),i=1;
    if(this->itemExiste(chave)){
        posi = buscarItem(chave);
        delete tabela[posi];
        tabela[posi] = new NoDoc<KEY,GIVEN>(chave,dado);
        return;
    }
    while(estaOcupado(posi) && i < n){
        posi = hash2(chave,i++) ;
    }
    if(estaOcupado(posi)){
        throw(00);//tabela cheia
    }else{
        tabela[posi] = new NoDoc<KEY,GIVEN>(chave,dado);
        elementos++;
        cont+=i-1;
    }
}

TEMPLATE_TABELA
GIVEN Tabelahash<KEY,GIVEN>::getIten(KEY chave){
    if(size()== 0)throw(01);
    int posi = this->buscarItem(chave);
    if (posi>n||tabela[posi]==0 || tabela[posi] == EX_OCUPADO)
        throw(01);
    if((*compare)(chave , tabela[posi]->getChave()) != 0)
        throw(01);
    return tabela[posi]->getDado();
}

TEMPLATE_TABELA
GIVEN Tabelahash<KEY,GIVEN>::remove(KEY chave){
    if(size()== 0)throw(01);
    int posi = this->buscarItem(chave);
    if (posi>n||tabela[posi]== 0 || tabela[posi] == EX_OCUPADO)
        throw(01);
    if((*compare)(chave , tabela[posi]->getChave()) != 0)
        throw(01);

    GIVEN copia = tabela[posi]->getDado();
    delete tabela[posi];
    //corrigir erro na remoção aki doido erro
    tabela[posi] = EX_OCUPADO;
    this->elementos--;
    return copia;
}

TEMPLATE_TABELA
bool Tabelahash<KEY,GIVEN>::itemExiste(KEY chave){
    int posi = buscarItem(chave);
    if(posi >= n || tabela[posi]==0 || tabela[posi] == EX_OCUPADO)
        return false;
    if((*compare)(chave , tabela[posi]->getChave()) == 0)//a chave existe na tabela
        return true;
    return false;
}

TEMPLATE_TABELA
int Tabelahash<KEY,GIVEN>::buscarItem(KEY chave){
    int posi=hash2(chave,0),i=1;
    while(tabela[posi]!=0 && i<n){
        if(tabela[posi] == EX_OCUPADO){
            posi=hash2(chave,i++);
        }else{
            if((*compare)(tabela[posi]->getChave(),chave)==0){
                return posi;
            }else{
                posi=hash2(chave,i++);
            }
        }
    }
    return posi;
}

TEMPLATE_TABELA
bool Tabelahash<KEY,GIVEN>::estaOcupado(int posi){
    return !(tabela[posi]==0 || tabela[posi]==EX_OCUPADO);
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::setFuncoesHash(int (*hah1)(KEY)){
    hash1 = hah1;
    /*(*hash1)(KEY);
*/
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::setCompare(int (*comp)(KEY,KEY)){
    compare = comp;
}

TEMPLATE_TABELA
Tabelahash<KEY,GIVEN>::~Tabelahash(){
    clean();
}

TEMPLATE_TABELA
Tabelahash<KEY,GIVEN>::Tabelahash(){
    tabela=0;
    hash1 = 0;
    compare = 0;
    inicializarTabela(DEFAULT_TABELA_HASH);
}

TEMPLATE_TABELA
Tabelahash<KEY,GIVEN>::Tabelahash(int m){
    tabela=0;
    hash1 = 0;
    compare = 0;
    proximoPrimo(m);
    inicializarTabela(m);
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::clean(){
    if(this->size()==0)return;
    for(int i=0;i<n;i++){
        delete tabela[i];
    }
    delete tabela;
    tabela=0;
    elementos=0;
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::inicializarTabela(int n){
    double randIracional[5]={3.14159265358 , 1.414213562 , 1.732050808 ,4.123105626 , 3.16227766};
    clean();
    elementos=0;
    srand(time(0));
    this->n = n;
    tabela = new NoDoc<KEY,GIVEN>*[this->n];
    for(int i=0;i<this->n;i++){
       tabela[i]=0;
    }
    if(hash1 == 0){
        setFuncoesHash(genericHash1);
    }
    if(compare == 0){
        setCompare(genericCompare);
    }
    multiplica = randIracional[rand()%5];
    cont=0;
}

TEMPLATE_TABELA
bool Tabelahash<KEY,GIVEN>::ehPrimo(int num){
    if(num == 1) return false;
    int raiz = (int)(sqrt(num));
    for(int i = 2; i <= raiz; i++)if(num%i == 0)return false;
    return true;
}

TEMPLATE_TABELA
void Tabelahash<KEY,GIVEN>::proximoPrimo(int& m){
    while(!ehPrimo(m)){
        m++;
    }
    return;
}

TEMPLATE_TABELA
KEY* Tabelahash<KEY,GIVEN>::getKeys(){
    KEY *chaves = new KEY[elementos];
    for(int i=0;i<n;i++){
        if(tabela[i]!=0 && tabela[i]!=EX_OCUPADO)
            chaves[i]=tabela[i]->getChave();
    }
    return chaves;
}

#include "dados.h"

Dados* Dados::_dados = 0;

Dados::~Dados(){
    if(_dados!=0)
        delete _dados;
}

int Dados::getNumeroSolucoes(){
    verificaInstancia();
    return _dados->solucoes.size();
}

list<UmaSolucao> Dados::getSolucao(){
    verificaInstancia();
    return _dados->solucoes;
}

void Dados::setSolucao(list<UmaSolucao> valor){
    verificaInstancia();
    _dados->solucoes = valor;
}

void Dados::addSolucao(UmaSolucao soluca){
    verificaInstancia();
    _dados->solucoes.push_back(soluca);
}

Dados::Dados(){
    _dados=0;
}

int Dados::getNumSolucoes()
{
    verificaInstancia();
    return _dados->numSolucoes;
}

void Dados::setNumSolucoes(int value)
{
    verificaInstancia();
    _dados->numSolucoes = value;
}

void Dados::saveSolucoesArquivo(string caminho){
    verificaInstancia();
    FILE* arq = fopen(caminho.c_str(),"w");
    if(arq==0)throw(string("Arquivo ["+caminho+"] nao esta disponivel"));
    fprintf(arq,"N[%d] K[%d] SOMA[%d] NUMERO_SOLUCOES[%d]\n",Dados::getN(),Dados::getQuantidadeElementosPorSolucao(),Dados::getValorTotalSomatorio(),Dados::getNumSolucoes());
    list<UmaSolucao>::iterator it = _dados->solucoes.begin();
    for(;it!=_dados->solucoes.end();it++){
        vector<int> atual = it->getSolucao();
        for(int i=0;i<atual.size();i++)
            fprintf(arq,"%d ",atual[i]);
        fprintf(arq,"\n");
    }
    fclose(arq);
}

void Dados::setN(int value){
    if(value<=0)throw string("[ERRO][setN] value deve ser maior do que zero");
    verificaInstancia();
    _dados->n = value;
}

int Dados::getN(){
    verificaInstancia();
    return _dados->n;
}

int Dados::getValorTotalSomatorio(){
    verificaInstancia();
    return _dados->valorTotalSomatorio;
}

void Dados::setValorTotalSomatorio(int value){
    if(value<=0)throw string("[ERRO][setValorTotalSomatorio] value deve ser maior do que zero");
    verificaInstancia();
    _dados->valorTotalSomatorio = value;
}

void Dados::limparDados(){
    verificaInstancia();
    _dados->solucoes.clear();
}

int Dados::getQuantidadeElementosPorSolucao(){
    verificaInstancia();
    return _dados->quantidadeElementosPorSolucao;
}

void Dados::setQuantidadeElementosPorSolucao(int value){
    if(value<=0)throw string("[ERRO][setQuantidadeElementosPorSolucao] value deve ser maior do que zero");
    verificaInstancia();
    _dados->quantidadeElementosPorSolucao = value;
}

void Dados::verificaInstancia(){
    if(_dados==0){
        _dados = new Dados();
        if(_dados==0)throw string("[FATAL][verificaInstancia]Memoria insuficiente");
    }
}

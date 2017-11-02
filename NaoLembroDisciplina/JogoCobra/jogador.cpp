#include "jogador.h"

Jogador::Jogador(string nome){
    numeroMortes=0;
    inicializaJogador(nome);
}

Jogador::Jogador(){
    numeroMortes = 0;
    recorde = 0;
    inicializaJogador(string("JogadorPadrao"));
}

list<ItemMovel> Jogador::getCobrina(){
    return cobrinha;
}

void Jogador::setCobrinha(list<ItemMovel> cobra)
{
    cobrinha = cobra;
}

void Jogador::addNoCobrinha(ItemMovel add){
    //adiciona um no add ao final do corpo da cobra
    cobrinha.push_back(add);
}

void Jogador::addNoCobrinha(){
    list<ItemMovel>::iterator it= cobrinha.end();
    int x = it->getX();
    int y = it->getY();
    switch (it->getDirecao()) {
    case DIREITA:
        y = it->getY()-1;
        break;
    case ESQUERDA:
        y = it->getY()+1;
        break;
    case CIMA:
        x = it->getX()+1;
        break;
    case BAIXO:
        x = it->getX()-1;
        break;
    }
    if(x<0)x=0;
    if(y<0)y=0;
    it->setX(x);
    it->setY(y);
    addNoCobrinha(*(it));
    tamanho++;
}

void Jogador::morteJogador(){
    if(pontuacao>recorde)recorde = pontuacao;
    inicializaJogador(nome);
    numeroMortes++;
}

string Jogador::getNome(){
    //retorna o nome do jogador
    return this->nome;
}

int Jogador::getPontuacao(){
    //retorna a pontuação do jogador
    return pontuacao;
}

void Jogador::carregarJogadorArquivoTexto(){
    //carregar jogador a partir de arquivo
    //arquivo deve estar no formato:
    /*
 nome
 pontuacao
 numeroMortes
 recorde
*/
    FILE* arq = fopen(CAMINHO_ARQUIVO,"r");
    if(arq==0)throw string("Arquivo do jogador não existe.");
    char nome_pla[90];
    int pontua,numMortes,recorde;
    fscanf(arq," %[^\n]",nome_pla);
    fscanf(arq,"%d\n%d\n%d",&pontua,&numMortes,&recorde);
    this->nome = string(nome_pla);
    this->pontuacao = pontua;
    this->numeroMortes = numMortes;
    this->recorde = recorde;
    fclose(arq);
}

void Jogador::salvarJogadorArquivoTexto(){
    FILE* arq = fopen(CAMINHO_ARQUIVO,"w");
    if(arq==0)throw string("Pasta CONFIG não existe.");
    fprintf(arq,"%s\n%d\n%d\n%d",nome.c_str(),pontuacao,numeroMortes,recorde);
    fclose(arq);
}

void Jogador::salvaJogadorArquivo(){
    //salva os dados do jogador no arquivo
    /*
     nome
     pontuacao
     numeroMortes
    */
    FILE* arq = fopen(CAMINHO_ARQUIVO,"w");
    if(arq==0)throw string("Pasta Config não foi encontrada.");
    fprintf(arq,"%s\n%d\n%d\n%d",nome.c_str(),0,numeroMortes,pontuacao>recorde?pontuacao:recorde);
    fclose(arq);
}

void Jogador::inicializaJogador(string nome){
    this->nome = nome;
    tamanho = 0;
    pontuacao = 0;
    cobrinha.clear();
    ItemMovel a;//cabeça da cobra, primeiro item da lista
    a.setX(11);a.setY(8);a.setDirecao(DIREITA);
    cobrinha.push_back(a);
}

int Jogador::getNumeroMortes() const
{
    return numeroMortes;
}

void Jogador::setNumeroMortes(int value)
{
    numeroMortes = value;
}

ItemMovel *Jogador::getCabecaCobra(){
    return &(*this->cobrinha.begin());
}

int Jogador::getRecorde() const
{
    return recorde;
}

int Jogador::getTamanho() const
{
    return tamanho;
}

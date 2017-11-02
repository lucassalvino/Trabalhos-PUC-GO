#include "geradorsequencia.h"
#include <QDebug>
void GeradorSequencia::gerarSequencias(){
    int i=Dados::getNumSolucoes()+1;
    while(i--,i){
        int somatorioAt = 0;
        UmaSolucao add;
        qDebug()<<"[INFO] Iniciando o calculo da solucao "<<i;
        for(int j=0;j<Dados::getQuantidadeElementosPorSolucao();j++){
            int tentarAdicionar = getNumero(somatorioAt,(Dados::getQuantidadeElementosPorSolucao()-j));
            if(verificaElementoParaAdiconar(tentarAdicionar,add)){
                somatorioAt += tentarAdicionar;
            }else{
                qDebug()<<"[WARNING] Impossivel adicionar o valor ["<<tentarAdicionar<<"]";
            }
        }
        verificaQuantidadeNumero(add);
        verificaSomaSolucao(add);
        Dados::addSolucao(add);
    }
}

bool GeradorSequencia::verificaElementoParaAdiconar(int& tentandoAdicionara, UmaSolucao &at){
    if(!jaExisteNaSolucao(tentandoAdicionara,at)){
        at.addElementoSolucao(tentandoAdicionara);
        return true;
    }else{
        tentandoAdicionara = getNumero(at.getSomaElementosSolucao(),Dados::getQuantidadeElementosPorSolucao()-at.getQuantidadeElementos());
        if(!jaExisteNaSolucao(tentandoAdicionara,at)){
            at.addElementoSolucao(tentandoAdicionara);
            return true;
        }
    }
    return false;
}

bool GeradorSequencia::jaExisteNaSolucao(int elemento, UmaSolucao &at){
    for(int i=0;i<at.getQuantidadeElementos();i++){
        if(elemento == at.getElementoSolucaoAt(i)){
            return true;
        }
    }
    return false;
}

int GeradorSequencia::getNumero(int somatorioAt,int faltam){
    int reto;
    int max= Dados::getValorTotalSomatorio();
    int n = Dados::getN();
    int fator = max-somatorioAt;
    if(fator>n)fator = n;
    fator/=faltam;
    reto = rand()%fator;
    if(faltam==0){
        reto = Dados::getValorTotalSomatorio()-somatorioAt;
        if(reto>Dados::getN())reto = Dados::getN();
    }
    return reto;
}

void GeradorSequencia::verificaQuantidadeNumero(UmaSolucao &at){
    if(at.getQuantidadeElementos() < Dados::getQuantidadeElementosPorSolucao()){
        while(at.getQuantidadeElementos()!=Dados::getQuantidadeElementosPorSolucao()){
            at.addElementoSolucao(getNumero(at.getSomaElementosSolucao(),Dados::getQuantidadeElementosPorSolucao()-at.getQuantidadeElementos()));
        }
    }
}

void GeradorSequencia::verificaSomaSolucao(UmaSolucao &at){
    while(at.getSomaElementosSolucao()!=Dados::getValorTotalSomatorio()){
        int i = rand()%at.getQuantidadeElementos();
        int add = at.getElementoSolucaoAt(i)+1;
        if(!jaExisteNaSolucao(add,at))
            at.setElementoSolucao(add,i);
    }
}

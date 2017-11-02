#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QMessageBox>
#include "Logica/geradorsequencia.h"
#include <QStringListModel>
#include <QFileDialog>
#include <QDateTime>

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    ui->resultadosList->setModel(model);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_Calcular_clicked(){
    try{
        validateParameters();//valida os parametros digitados
        saveParameters();//salva os parametros em Dados
        GeradorSequencia::gerarSequencias();
        updateListView();
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",erro.c_str());
    }
}

void JanelaPrincipal::clearItemsGraphics(){
    ui->valorK->clear();
    ui->valorN->clear();
    ui->valorSoma->clear();
}

void JanelaPrincipal::updateRowsListView(){
    QStringList list;
    QModelIndex a;
}

void JanelaPrincipal::validateParameters(){
    int n = ui->valorN->text().toInt();
    int k = ui->valorK->text().toInt();
    int soma = ui->valorSoma->text().toInt();
    int numSolucoes = ui->numSolucoes->text().toInt();
    string iniExce = "[ERRO][ValidateParameters] ";
    if(soma <= 0){
        throw iniExce + string("Valor Soma deve ser maior do que zero");
    }else{
        if(k <= 0){
            throw iniExce + string("Valor de K deve ser maior do que zero");
        }else{
            if(n <=0 ){
                throw iniExce + string("O valor de N deve ser maior do que zero");
            }else{
                if(numSolucoes<=0){
                    throw iniExce + string("O valor de Número de Soluções deve ser maior do que zero");
                }
            }
        }
    }
}

void JanelaPrincipal::saveParameters(){
    int n = ui->valorN->text().toInt();
    int k = ui->valorK->text().toInt();
    int soma = ui->valorSoma->text().toInt();
    int numSolucoes = ui->numSolucoes->text().toInt();
    Dados::setN(n);
    Dados::setQuantidadeElementosPorSolucao(k);
    Dados::setValorTotalSomatorio(soma);
    Dados::setNumSolucoes(numSolucoes);
    qDebug()<<"[INFO] N:["<<Dados::getN()<<"] K:["<<Dados::getQuantidadeElementosPorSolucao()<<"] Soma["<<Dados::getValorTotalSomatorio()<<"].";
}

void JanelaPrincipal::updateListView(){
    list<UmaSolucao> solucAt = Dados::getSolucao();
    list<UmaSolucao>::iterator it = solucAt.begin();
    QStringList lista;
    for(;it!=solucAt.end();it++){
        QString li = "";
        for(int i=0;i < it->getQuantidadeElementos();i++){
            li+=QString::number(it->getElementoSolucaoAt(i));
            li+=" ";
        }
        lista<<li;
    }
    model->setStringList(lista);
    ui->resultadosList->setModel(model);
}

void JanelaPrincipal::updateDataCalculateListView(){
    QStringList lista;
    QString add="";
    add += "Calculando valores para N = ["+QString::number(Dados::getN())+"] ";
    add += "K = ["+QString::number(Dados::getQuantidadeElementosPorSolucao())+"] ";
    add += "Soma = ["+QString::number(Dados::getValorTotalSomatorio())+"]";
    lista<<add;
    model->setStringList(lista);
    ui->resultadosList->setModel(model);
}

void JanelaPrincipal::updateParametersListView(){

}

void JanelaPrincipal::clearLineEdit(){
    ui->valorK->clear();
    ui->valorN->clear();
    ui->valorSoma->clear();
}

void JanelaPrincipal::clearListView(){
    model = new QStringListModel(this);
    model->setStringList(QStringList{});
    ui->resultadosList->setModel(model);
}

void JanelaPrincipal::on_Salvar_clicked(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Abrir Pasta"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    qDebug()<<"[INFO] Selecionada pasta ["<<dir<<"]";
    string caminh = dir.toStdString();
    caminh+="/Save_"+QDateTime::currentDateTime().toString().toStdString();
    caminh+=".txt";
    for(int i=0;i<caminh.size();i++){
        if(caminh[i]==':')caminh[i]='_';
    }
    qDebug()<<"Salvando em "<<caminh.c_str();
    Dados::saveSolucoesArquivo(caminh);
}

void JanelaPrincipal::on_action_Ajuda_triggered(){
    QMessageBox::information(this,"Ajuda","[N]-> delimita os valores possíveis para uma solucação, cada solucção terá valores entre [0,N)\n"
                                          "[K]-> Quantidade de elementos por solução.\n"
                                          "[SOMA]-> Valor da soma dos elementos para cada solução.\n"
                                          "[Número De soluções]-> Quantidade de soluções a ser geradas.\n"
                                          "[Obs.]-> Defina os valores com cuidado, dependendo dos valores informados não será possível gerar soluções corretas.\n"
                                          "[SALVAR]-> Caso queira salvar as soluções obtidas, clique em 'Salvar Arquivo' e navegue até a pasta de destino.");
}

void JanelaPrincipal::on_action_Sobre_triggered(){
    QMessageBox::information(this,"Sobre","Desenvolvido por:\n"
                                          "\tGildenor Sousa Calvacante (gildenorpuc@gmail.com)\n"
                                          "\tLucas Salvino de Deus (lucassalvino1@gmail.com)\n"
                                          "Repositorio GitHub: https://github.com/lucassalvino/GeradorSequenciasSoma");
}

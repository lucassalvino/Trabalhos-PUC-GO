#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QInputDialog>
#include <vector>
#include <iostream>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
    modelSaida = 0;
    ui->ProximoPasso->setEnabled(false);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_actionCarregar_Tabela_triggered()
{
    QString caminho = QInputDialog::getText(this, "Caminho arquivo Texto", "Digite o caminho do arquivo com a tabela:",QLineEdit::Normal, "C:/teste.txt");
    logica.CarregaTabela(caminho.toStdString());
    vector<string> titutos = logica.getTitulos();
    int n = logica.numeroLinhas();
    QStandardItemModel* model = new QStandardItemModel(n,(int)titutos.size(),this);
    for (int i = 0;  i < (int)titutos.size(); i++ ){
        model->setHorizontalHeaderItem(i, new QStandardItem(QString(titutos[i].c_str())));
     }
    for(int i = 0; i<n; i++){
        vector<string> linha = logica.getLinhaTabela(i);
        for(int j =0; j<(int)linha.size(); j++){
            model->setItem(i,j,new QStandardItem(QString(linha[j].c_str())));
        }
    }
    ui->TabelaCompi->setModel(model);
    ui->ProximoPasso->setEnabled(true);
}

void JanelaPrincipal::on_actionAjuda_triggered()
{
    string mensagem = "Sempre realizar a entrada utilizando o espaço como separação\nAo importar a tabela use o caracter ponto `.` para representar um espço vazio";
    QMessageBox::about(this, "Ajuda", mensagem.c_str());
}
void JanelaPrincipal::on_Submit_clicked(){}

void JanelaPrincipal::atualizaSaida(){
    modelSaida->setItem(contadorLinha,0,new QStandardItem(QString::number(contadorLinha)));
    modelSaida->setItem(contadorLinha,1,new QStandardItem(logica.GetPilhasAsStrin().c_str()));
    modelSaida->setItem(contadorLinha,2,new QStandardItem(logica.GetEntradaAsString().c_str()));
    modelSaida->setItem(contadorLinha,3,new QStandardItem(logica.GetAcao().c_str()));
    contadorLinha++;
}


void JanelaPrincipal::on_ProximoPasso_clicked()
{
    string input = ui->palavraTeste->text().toStdString();
    ui->palavraTeste->setText("");
    char input_str[((int)input.size())+1];
    strcpy(input_str, input.c_str());
    if(input != ""){
        logica.LimpaPilhas();
        vector<string> input_vec;
        char *prin = strtok(input_str, " ");
        while (prin != 0) {
            input_vec.push_back(string(prin));
            prin = strtok(NULL, " ");
        }
        for(int i = (int)(input_vec.size())-1; i>=0; i--)
            logica.adicionaEntrada(input_vec[i]);

        if(modelSaida == 0){
            contadorLinha = 0;
            modelSaida = new QStandardItemModel(this);
            modelSaida->setHorizontalHeaderItem(0, new QStandardItem("Passo"));
            modelSaida->setHorizontalHeaderItem(1, new QStandardItem("Pilha"));
            modelSaida->setHorizontalHeaderItem(2, new QStandardItem("Entrada"));
            modelSaida->setHorizontalHeaderItem(3, new QStandardItem("Ação"));
            ui->tabeSaida->setModel(modelSaida);
        }
    }else{
        try{
            bool process = logica.calculaProximoPasso();
            if(process)
               QMessageBox::about(this,"Sucesso", "A palavra é valida!!!!");
        }
        catch(string erro){
            QMessageBox::warning(this, "Erro", string(string("A palavra é inválida ") + erro).c_str());
        }
    }
    atualizaSaida();
}

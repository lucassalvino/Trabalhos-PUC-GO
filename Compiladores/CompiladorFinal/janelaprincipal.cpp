#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QInputDialog>
#include <QStandardItemModel>
#include <vector>
#include <iostream>
#include <QMessageBox>

using namespace std;

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_actionCarregar_Tabela_triggered()
{
    QString caminho = QInputDialog::getText(this, "Caminho arquivo Texto", "Digite o caminho do arquivo com a tabela:");    
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
}

void JanelaPrincipal::on_actionAjuda_triggered()
{
    string mensagem = "Sempre realizar a entrada utilizando o espaço como separação\nAo importar a tabela use o caracter ponto `.` para representar um espço vazio";
    QMessageBox::about(this, "Ajuda", mensagem.c_str());
}

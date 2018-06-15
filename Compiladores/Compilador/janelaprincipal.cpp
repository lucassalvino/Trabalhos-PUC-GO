#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QInputDialog>

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
}

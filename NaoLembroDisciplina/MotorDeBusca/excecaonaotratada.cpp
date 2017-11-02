#include "excecaonaotratada.h"
#include "ui_excecaonaotratada.h"

ExcecaoNaoTratada::ExcecaoNaoTratada(int a) :
    QWidget(0),
    ui(new Ui::ExcecaoNaoTratada)
{
    ui->setupUi(this);
    ui->label->setText("Erro inesperado: "+QString::number(a)+"\nOlhe menu ajuda");
}

ExcecaoNaoTratada::ExcecaoNaoTratada(string a):QWidget(0),ui(new Ui::ExcecaoNaoTratada){
    ui->setupUi(this);
    ui->label->setText("Erro inesperado: "+QString::fromStdString(a)+"\nOlhe menu ajuda");
}

ExcecaoNaoTratada::~ExcecaoNaoTratada()
{
    delete ui;
}

void ExcecaoNaoTratada::on_pushButton_clicked()
{
    close();
}

#include "ajuda.h"
#include "ui_ajuda.h"
#include <iostream>
using namespace std;
Ajuda::Ajuda(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ajuda)
{
    string a="Caso tenha recebido um erro, veja as possiveis causas abaixo:\n"
             "erro 00: tabela hash cheia\nerro 01: item não existe na tabela\nerro 10: arquivo não existe\n";
    ui->setupUi(this);
    ui->textBrowser->setText(QString::fromStdString(a));
}

Ajuda::~Ajuda()
{
    delete ui;
}

void Ajuda::on_pushButton_clicked()
{
    close();
}

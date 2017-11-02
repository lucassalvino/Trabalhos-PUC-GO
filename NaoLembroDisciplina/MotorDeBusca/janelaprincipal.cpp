#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <cstdlib>
JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
    ui->radioButton_2->click();
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
    Interface::finalizar();
}

void JanelaPrincipal::on_action_Sair_triggered()
{
    close();
}

void JanelaPrincipal::on_action_Atualizar_triggered()
{
    Atualizar *janelaAtualizar= new Atualizar;
    janelaAtualizar->show();
}

void JanelaPrincipal::on_pushButton_clicked()
{
    string a = ui->lineEdit->text().toStdString();
    bool op;
    op = ui->radioButton_2->isChecked();
    try{
        ui->textBrowser->setText(QString::fromStdString(Interface::buscarTermo(a,op)));
    }
    catch(string a){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(a);
        oi->show();
    }
    catch(...){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada("Erro não indexado!!!");
        oi->show();
    }
}

void JanelaPrincipal::on_action_Ajuda_triggered()
{
    Ajuda *ajudar = new Ajuda;
    ajudar->show();
}

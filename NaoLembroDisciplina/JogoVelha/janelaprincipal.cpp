#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QMessageBox>

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
    botoes = new  QPushButton ** [N];
    for(int i=0;i<N;i++)
        botoes[i] = new QPushButton * [N];
    botoes[0][0] = ui->A1;
    botoes[0][1] = ui->B1;
    botoes[0][2] = ui->C1;
    botoes[1][0] = ui->A1_2;
    botoes[1][1] = ui->B1_2;
    botoes[1][2] = ui->C1_2;
    botoes[2][0] = ui->A1_3;
    botoes[2][1] = ui->B1_3;
    botoes[2][2] = ui->C1_3;
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_actionReiniciar_triggered()
{
    try{
        Acoes::recomecarJogo();
        throw string("Jogo Reiniciado");
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::atualizarTela()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            switch(Acoes::getItemPosicao(i,j)){
            case JOGADOR1:
                botoes[i][j]->setText("X");
                break;
            case JOGADOR2:
                botoes[i][j]->setText("O");
                break;
            case VAZIO:
                botoes[i][j]->setText(" ");
                break;
            }
        }
    }
}

void JanelaPrincipal::on_A1_clicked()
{
    try{
        Acoes::realizarJogada(0,0);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_B1_clicked()
{
    try{
        Acoes::realizarJogada(0,1);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_C1_clicked()
{
    try{
        Acoes::realizarJogada(0,2);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_A1_2_clicked()
{
    try{
        Acoes::realizarJogada(1,0);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_B1_2_clicked()
{
    try{
        Acoes::realizarJogada(1,1);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_C1_2_clicked()
{
    try{
        Acoes::realizarJogada(1,2);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_A1_3_clicked()
{
    try{
        Acoes::realizarJogada(2,0);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_B1_3_clicked()
{
    try{
        Acoes::realizarJogada(2,1);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

void JanelaPrincipal::on_C1_3_clicked()
{
    try{
        Acoes::realizarJogada(2,2);
    }
    catch(string erro){
        QMessageBox::warning(this,"Erro",QString::fromStdString(erro));
    }
    atualizarTela();
}

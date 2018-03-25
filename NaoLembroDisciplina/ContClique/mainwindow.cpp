#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setpathfile.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnClique_clicked()
{
    try
    {
        control.ClickAcao();
    }
    catch(string erro)
    {
        QMessageBox::warning(this,"Erro", erro.c_str());
    }
    catch(const char * erro)
    {
        QMessageBox::warning(this,"Erro", erro);
    }
}

void MainWindow::on_actionSelecionar_Arquivo_triggered()
{
    try{
        SetPathFile run;
        run.save = &control;
        run.setModal(false);
        run.exec();
    }
    catch(const char * erro)
    {
        QMessageBox::warning(this,"Erro", erro);
    }
}

void MainWindow::on_actionSobre_triggered()
{
    QMessageBox::about(this, "Sobre","Criado por Lucas Salvino de Deus\n Qualquer problema, bug, dúvida ou sujestão entre em contato:\n \t\tlucassalvino1@gmail.com\n \t\thttps://github.com/lucassalvino");
}

void MainWindow::on_actionAjuda_triggered()
{
    QMessageBox::about(this, "Ajuda",
                       "É gravada a data e hora que o  botão 'clique' é precionado.\n As informações podem ser salvar em um caminho especificado em 'Selecionar Arquivo' (neste caso especifique o caminho e o nome do arquivo com sua extenção)\nou em caso de não ter sido setado, as informações serão salvas na mesma pasta de execução do aplicativo.");
}

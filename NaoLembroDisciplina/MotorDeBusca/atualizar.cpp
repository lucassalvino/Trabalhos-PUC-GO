#include "atualizar.h"
#include "ui_atualizar.h"

Atualizar::Atualizar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Atualizar)
{
    ui->setupUi(this);
}

Atualizar::~Atualizar()
{
    delete ui;
}

void Atualizar::on_pushButton_clicked()
{
    string caminho = ui->lineEdit->text().toStdString();
    ui->lineEdit->setText("");
    try{
        Interface::indexar(caminho);
    }
    catch(int a){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(a);
        oi->show();
    }
    catch(string a){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada(a);
        oi->show();
    }
    catch(...){
        ExcecaoNaoTratada *oi= new ExcecaoNaoTratada("Erro não indexado!!!");
        oi->show();
    }
    close();
}

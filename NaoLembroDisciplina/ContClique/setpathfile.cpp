#include "setpathfile.h"
#include "ui_setpathfile.h"
#include <QMessageBox>

SetPathFile::SetPathFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPathFile)
{
    ui->setupUi(this);
}

SetPathFile::~SetPathFile()
{
    delete ui;
}

void SetPathFile::on_buttonBox_accepted()
{
    try{
        if(this->save == 0)throw "Varialvel de configuracao nao setada";
        save->SetSavePath(ui->lineEdit->text().toStdString());
    }
    catch(const char * erro)
    {
        QMessageBox::warning(this,"Erro", erro);
    }
}

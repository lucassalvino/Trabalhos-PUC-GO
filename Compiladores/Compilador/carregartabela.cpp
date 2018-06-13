#include "carregartabela.h"
#include "ui_carregartabela.h"

CarregarTabela::CarregarTabela(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarregarTabela)
{
    ui->setupUi(this);
}

CarregarTabela::~CarregarTabela()
{
    delete ui;
}

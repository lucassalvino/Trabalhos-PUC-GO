#ifndef CARREGARTABELA_H
#define CARREGARTABELA_H
#include <iostream>
using namespace std;

#include <QWidget>

namespace Ui {
class CarregarTabela;
}

class CarregarTabela : public QWidget
{
    Q_OBJECT

public:

    explicit CarregarTabela(QWidget *parent = 0);
    ~CarregarTabela();
    string* path;
private:
    Ui::CarregarTabela *ui;
};

#endif // CARREGARTABELA_H

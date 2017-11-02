#ifndef ATUALIZAR_H
#define ATUALIZAR_H

#include <QWidget>
#include "interface.h"
#include "excecaonaotratada.h"
namespace Ui {
class Atualizar;
}

class Atualizar : public QWidget
{
    Q_OBJECT

public:
    explicit Atualizar(QWidget *parent = 0);
    ~Atualizar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Atualizar *ui;
};

#endif // ATUALIZAR_H

#ifndef EXCECAONAOTRATADA_H
#define EXCECAONAOTRATADA_H

#include <QWidget>
#include <iostream>
using namespace std;
namespace Ui {
class ExcecaoNaoTratada;
}

class ExcecaoNaoTratada : public QWidget
{
    Q_OBJECT

public:
     ExcecaoNaoTratada(int);//explicit
     ExcecaoNaoTratada(string);
    ~ExcecaoNaoTratada();
private slots:
    void on_pushButton_clicked();

private:
    Ui::ExcecaoNaoTratada *ui;
};

#endif // EXCECAONAOTRATADA_H

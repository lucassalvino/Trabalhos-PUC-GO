#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <atualizar.h>
#include "nodoc.h"
#include "interface.h"
#include "excecaonaotratada.h"
#include "ajuda.h"
namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

private slots:
    void on_action_Sair_triggered();

    void on_action_Atualizar_triggered();

    void on_pushButton_clicked();

    void on_action_Ajuda_triggered();

private:
    Ui::JanelaPrincipal *ui;
};

#endif // JANELAPRINCIPAL_H

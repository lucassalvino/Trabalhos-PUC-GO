#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <QPushButton>
#include "acoes.h"
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
    void on_actionReiniciar_triggered();

    void on_A1_clicked();

    void on_B1_clicked();

    void on_C1_clicked();

    void on_A1_2_clicked();

    void on_B1_2_clicked();

    void on_C1_2_clicked();

    void on_A1_3_clicked();

    void on_B1_3_clicked();

    void on_C1_3_clicked();

private:
    Ui::JanelaPrincipal *ui;
    void atualizarTela();
    QPushButton *** botoes;
};

#endif // JANELAPRINCIPAL_H

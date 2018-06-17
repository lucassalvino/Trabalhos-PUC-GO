#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include "logica.h"

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();
    Logica logica;

private slots:
    void on_actionCarregar_Tabela_triggered();

    void on_actionAjuda_triggered();

private:
    Ui::JanelaPrincipal *ui;
};

#endif // JANELAPRINCIPAL_H

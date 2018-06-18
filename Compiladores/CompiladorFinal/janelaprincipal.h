#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include "logica.h"
#include <QStandardItemModel>

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
    QStandardItemModel* modelSaida;

    void atualizaSaida();

private slots:
    void on_actionCarregar_Tabela_triggered();

    void on_actionAjuda_triggered();

    void on_Submit_clicked();

    void on_ProximoPasso_clicked();
private:
    Ui::JanelaPrincipal *ui;
    int contadorLinha;
};

#endif // JANELAPRINCIPAL_H

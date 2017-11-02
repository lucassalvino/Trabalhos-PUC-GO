#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <QDebug>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>

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
    void on_Calcular_clicked();

    void on_Salvar_clicked();

    void on_action_Ajuda_triggered();

    void on_action_Sobre_triggered();

private:
    Ui::JanelaPrincipal *ui;
    void clearItemsGraphics();
    void updateRowsListView();
    void validateParameters();
    void saveParameters();
    void updateListView();
    void updateDataCalculateListView();

    void updateParametersListView();
    void clearLineEdit();
    void clearListView();


    QStringListModel *model;
};

#endif // JANELAPRINCIPAL_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Base/controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnClique_clicked();

    void on_actionSelecionar_Arquivo_triggered();

    void on_actionSobre_triggered();

    void on_actionAjuda_triggered();

private:
    Ui::MainWindow *ui;
    Controller control;
};

#endif // MAINWINDOW_H

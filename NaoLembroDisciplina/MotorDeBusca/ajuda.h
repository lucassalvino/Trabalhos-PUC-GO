#ifndef AJUDA_H
#define AJUDA_H

#include <QWidget>

namespace Ui {
class Ajuda;
}

class Ajuda : public QWidget
{
    Q_OBJECT

public:
    explicit Ajuda(QWidget *parent = 0);
    ~Ajuda();   

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ajuda *ui;
};

#endif // AJUDA_H

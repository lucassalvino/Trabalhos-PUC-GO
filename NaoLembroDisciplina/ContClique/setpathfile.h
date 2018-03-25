#ifndef SETPATHFILE_H
#define SETPATHFILE_H

#include <QDialog>
#include "Base/controller.h"
namespace Ui {
class SetPathFile;
}

class SetPathFile : public QDialog
{
    Q_OBJECT

public:
    explicit SetPathFile(QWidget *parent = 0);
    ~SetPathFile();
    Controller* save;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SetPathFile *ui;
};

#endif // SETPATHFILE_H

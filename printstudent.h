#ifndef PRINTSTUDENT_H
#define PRINTSTUDENT_H
#include <QDialog>
#include "binaries.h"

namespace Ui {
class printstudent;
}

class printstudent : public QDialog
{
    Q_OBJECT

public:
    explicit printstudent(QWidget *parent = 0);
    ~printstudent();
    binaries bin;
    void SetNumCuenta(QString numdecuenta);
    void ReadData(QString num);
    QString numcuenta;

private:
    Ui::printstudent *ui;
};

#endif // PRINTSTUDENT_H

#ifndef TAREA1_H
#define TAREA1_H

#include <QDialog>
#include "binaries.h"
namespace Ui {
class Tarea1;
}

class Tarea1 : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea1(QWidget *parent = 0);
    ~Tarea1();

    binaries bin;
private slots:
    void on_ImprimirBtn_clicked();

    void on_IngresarNombreBtn_clicked();

    void on_BuscarNombreBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::Tarea1 *ui;
};

#endif // TAREA1_H

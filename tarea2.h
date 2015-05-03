#ifndef TAREA2_H
#define TAREA2_H

#include "QString"
#include <QDebug>
#include <QDialog>

namespace Ui {
class tarea2;
}

class tarea2 : public QDialog
{
    Q_OBJECT

public:
    explicit tarea2(QWidget *parent = 0);
    ~tarea2();
    QList<QString> list;
    int sizeofint = 4;
    int actualpos;
    int cuenta;
    int age;
    QList<QString> fields;
    void Write();
    void Read(int numdecuenta);
    void Search(int datapos);
    void Print();

private slots:
    void on_savebtn_clicked();

    void on_printBtn_clicked();

    void on_buscarbtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::tarea2 *ui;
};

#endif // TAREA2_H

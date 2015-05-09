#ifndef TAREA3_H
#define TAREA3_H
#include <QDialog>
#include <iostream>
#include <fstream>
#include <ostream>
namespace Ui {
class Tarea3;
}

class Tarea3 : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea3(QWidget *parent = 0);
    ~Tarea3();

    int number;
    void TurnOnOffBit(int position);
    void ShowInBinary(int number);
    void UpdateNumber(int num);
    void toBinary(int num, int bits);
    void Save();
    void Load();
private slots:
    void on_SetNumberBtn_clicked();

    void on_TurnOnOffBtn_clicked();

    void on_SaveBtn_clicked();

    void on_LoadBtn_clicked();

private:
    Ui::Tarea3 *ui;
};

#endif // TAREA3_H

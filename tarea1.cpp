#include "tarea1.h"
#include "ui_tarea1.h"
#include "dialog.h"
#include "printstudents.h"
#include "QMessageBox"
Tarea1::Tarea1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea1)
{
    ui->setupUi(this);
}

Tarea1::~Tarea1()
{
    delete ui;
}

void Tarea1::on_ImprimirBtn_clicked()
{

    printstudents win;
    win.setModal(true);
    win.exec();
}

void Tarea1::on_IngresarNombreBtn_clicked()
{
    Dialog win;
    win.setModal(true);
    win.exec();
}

void Tarea1::on_BuscarNombreBtn_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        return;

    QMessageBox msg;
    msg.setText(bin.Read(ui->lineEdit->text().toInt()));
    msg.exec();


}

void Tarea1::on_closeBtn_clicked()
{
    close();
}

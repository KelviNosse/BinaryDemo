#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tarea1.h"
#include "tarea2.h"
#include "tarea3.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Org. de Archivos - Tareas");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_tarea1Btn_clicked()
{
    Tarea1 win;
    win.setModal(true);
    win.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.setText("This is a Binary Demo for Org. De Archivos | 2015\n\n\tKelvin Nose :^)");
    msg.exec();


}

void MainWindow::on_tarea2Btn_clicked()
{
    tarea2 *win = new tarea2();
    win->setModal(true);
    win->exec();


}

void MainWindow::on_tarea3Btn_clicked()
{
    Tarea3 *win = new Tarea3();
    win->setModal(true);
    win->exec();
}

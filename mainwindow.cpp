#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tarea1.h"

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

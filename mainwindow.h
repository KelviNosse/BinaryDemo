#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binaries.h"

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

    void on_tarea1Btn_clicked();

    void on_actionAbout_triggered();

    void on_tarea2Btn_clicked();

    void on_tarea3Btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

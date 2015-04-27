#include "mainwindow.h"
#include <QApplication>
#include "QString"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Crear registros y pasarlos a binarios




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();



}

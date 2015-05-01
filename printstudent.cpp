#include "printstudent.h"
#include "ui_printstudent.h"
#include "QMessageBox"
#include "binaries.h"
#define INVALIDCHAR '|'

printstudent::printstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printstudent)
{
    ui->setupUi(this);


}

printstudent::~printstudent()
{
    delete ui;
}

void printstudent::SetNumCuenta(QString numdecuenta)
{
    this->numcuenta = numdecuenta;

}

void printstudent::ReadData(QString num)
{
    QMessageBox msg;

    ifstream *data = new ifstream("info.data", ios::binary | ios::ate);

    if(!data){
        msg.setText("ERROR DE ARCHIVO");
        msg.exec();
        ui->plainTextEdit->insertPlainText("EL ARCHIVO NO EXISTE, O ESTA CORRUPTO!");
        return;

    }
    qDebug()<<num;
    int datapos = bin.GetPosData(num);


    if(datapos == -1){
        data->close();
        msg.setText("EL REGISTRO NO FUE ENCONTRADO!");
        msg.exec();
        ui->plainTextEdit->insertPlainText("REGISTRO NO ENCONTRADO, INTENTA DE NUEVO!");
        return;

    }

    data->seekg(datapos);
    int currentindex = 0;
    QString info;
    ui->plainTextEdit->insertPlainText(binaries::campos[0]);
    while(true){
        char content;
        data->get(content);

        if(content == INVALIDCHAR){

            ui->plainTextEdit->insertPlainText("\n\n");

            currentindex++;
            if(currentindex == 5)
                break;

            ui->plainTextEdit->insertPlainText(binaries::campos[currentindex]);


        }else{

            qDebug()<<content;
            QString c;
            c = content;


            ui->plainTextEdit->insertPlainText(c);


        }

    }

    data->close();
}

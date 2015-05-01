#include "printstudents.h"
#include "ui_printstudents.h"
#include "QMessageBox"
#include "binaries.h"
#define INVALIDCHAR '|'
printstudents::printstudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printstudents)
{
    ui->setupUi(this);
    ifstream data("info.data",ios::binary);
    ui->plainTextEdit->insertPlainText("--REGISTROS EN ARCHIVO--\n");

    if(!data.is_open()){
                    QMessageBox msg;
                    msg.setText("ERROR DE ARCHIVO!");
                    msg.exec();
                    ui->plainTextEdit->insertPlainText("ERROR AL TRATAR DE LEER!");
                    return;
        }else{



    data.seekg(0, data.end);
    int size = data.tellg();
    data.seekg(0);

    cout<<"FILE SIZE: "<<size<<endl;

    int index = 0;
    qDebug()<<binaries::campos[index];
    ui->plainTextEdit->insertPlainText(binaries::campos[index]);


    for(int i = 0; i<size-1; i++){

                    char content;
                    data.get(content);
                    if(content == INVALIDCHAR){
                    index++;
                    if(index == 5){
                    index = 0;
                    ui->plainTextEdit->insertPlainText("\n");

        }

                    qDebug()<<binaries::campos[index];
                    ui->plainTextEdit->insertPlainText("\n");
                    ui->plainTextEdit->insertPlainText(binaries::campos[index]);

        }
        else{
            qDebug()<<content;
            QString c;
            c = content;
            ui->plainTextEdit->insertPlainText(c);

        }

        }

            ui->plainTextEdit->insertPlainText("\n\n");

            data.close();

        }
}

printstudents::~printstudents()
{
    delete ui;
}

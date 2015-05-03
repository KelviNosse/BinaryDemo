#include "tarea2.h"
#include "ui_tarea2.h"
#include "fstream"
#include "iostream"
#include <ostream>
#include <string>
#include "QString"
#include <QDebug>
#include "QMessageBox"
using namespace std;

tarea2::tarea2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarea2)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->fields.append("Numero de Cuenta: ");
    this->fields.append("Nombre: ");
    this->fields.append("Edad: ");
    this->fields.append("Direccion: ");
    this->fields.append("Universidad: ");


}

tarea2::~tarea2()
{
    delete ui;
}

void tarea2::Write()
{
   QMessageBox msj;
   ifstream data("data.chip", ios::binary | ios::ate);
   int pos = data.tellg();
   data.close();

   ofstream file1("data.chip" , ios::binary | ios::app);
   ifstream file2("indexes.chip" , ios::binary);
   ofstream out;
   int zero =0;
   if(!file2.is_open()){
       qDebug()<<"Indexes files doesn't exist, gonna create it";
       file2.close();
       out.open("indexes.chip", ios::binary | ios::app);
       out.write((char*)&zero, 4);



   }else{
       qDebug()<<"Indexes files already exist";
       file2.close();
       out.open("indexes.chip", ios::binary | ios::app);

       out.write((char*)&pos, 4);
       qDebug()<<"Start position: "+pos;

   }

   if(file1.is_open()){

       int name = ui->nombreline->text().length() + 1;
       int direccion = ui->direccionline->text().length() + 1;
       int uni = ui->universidadline->text().length() + 1;
       int age = ui->edadline->text().toInt();
       int cuenta = ui->cuentaline->text().toInt();
       char names[name];
       char dir[direccion];
       char univ[uni];
       strcpy(names, ui->nombreline->text().toStdString().c_str());
       strcpy(dir, ui->direccionline->text().toStdString().c_str());
       strcpy(univ, ui->universidadline->text().toStdString().c_str());

       file1.write((char*)&sizeofint, 4);
       file1.write((char*)&cuenta, 4);
       file1.write((char*)&name, sizeof(name));
       file1.write(names, name);
       file1.write((char*)&sizeofint, 4);
       file1.write((char*)&age , 4);
       file1.write((char*)&direccion, sizeof(direccion));
       file1.write(dir, direccion);
       file1.write((char*)&uni, sizeof(uni));
       file1.write(univ, uni);


        qDebug()<<"Data Saved!";
        msj.setText("INFORMACION GUARDADA EXITOSAMENTE!");
        msj.exec();
        ui->plainTextEdit->clear();
        ui->cuentaline->clear();
        ui->searchline->clear();
        ui->direccionline->clear();
        ui->edadline->clear();
        ui->nombreline->clear();
        ui->universidadline->clear();
   }
    file1.close();

    out.close();

}

void tarea2::Read(int numdecuenta)
{
    ifstream data("data.chip", ios::binary);
    ifstream indexes("indexes.chip", ios::binary | ios::ate);
    int size = indexes.tellg();
    indexes.seekg(0,ios::beg);
    int cuenta, position;
    bool flag = false;

    while(indexes.tellg() < size){
        int length;
        indexes.read((char*)&position, 4);
        data.seekg(position);
        data.read((char*)&length, 4);
        data.read((char*)&cuenta, length);
        if(cuenta == numdecuenta){
            qDebug()<<"Element with "<<cuenta<<"was founded!\nProcessing...";
            flag = true;
            this->Search(position);
            break;
        }


    }

    if(flag == false){
        QMessageBox msg;
        msg.setText("El registro no fue encontrado o no existe!\nIntenta de nuevo!");
        msg.exec();
    }

    indexes.close();
    data.close();


}

void tarea2::Search(int datapos)
{
    ui->plainTextEdit->clear();
    ifstream file("data.chip", ios::binary);
    int index = 0;
    int sizeofname, sizedir, sizeuni;

    if(file.is_open()){
        file.seekg(datapos);
        file.read((char*)&sizeofint, 4);
        file.read((char*)&cuenta, 4);
        file.read((char*)&sizeofname, 4);
        char names[sizeofname];
        file.read(names, sizeof(names));
        file.read((char*)&sizeofint, 4);
        file.read((char*)&age, 4);
        file.read((char*)&sizedir, 4);
        char dirs[sizedir];
        file.read(dirs, sizeof(dirs));
        file.read((char*)&sizeuni, 4);
        char univs[sizeuni];
        file.read(univs, sizeof(univs));

        this->list.clear();
        this->list<<QString::number(cuenta);
        this->list<<names;
        this->list<<QString::number(age);
        this->list<<dirs;
        this->list<<univs;
        ui->plainTextEdit->insertPlainText("---REGISTRO ENCONTRADO---\n");
        while(!list.isEmpty()){
            ui->plainTextEdit->insertPlainText(fields.at(index));
            ui->plainTextEdit->insertPlainText(list.takeFirst());
            ui->plainTextEdit->insertPlainText("\n");
            index++;

            if(index == 5)
                index = 0;
        }
    }
    qDebug()<<"Element founded successfully!";

    file.close();
}

void tarea2::Print()
{
    ui->plainTextEdit->clear();
    ifstream data("data.chip", ios::binary | ios::ate);
    int size = data.tellg();
    data.seekg(0, ios::beg);
    int index = 0;
    int d = 0;
    int sizeofname, sizedir, sizeuni;

    while(data.tellg() < size){
        data.read((char*)&sizeofint, 4);
        data.read((char*)&cuenta, 4);
        data.read((char*)&sizeofname, 4);
        char names[sizeofname];
        data.read(names, sizeof(names));
        data.read((char*)&sizeofint, 4);
        data.read((char*)&age, 4);
        data.read((char*)&sizedir, 4);
        char dirs[sizedir];
        data.read(dirs, sizeof(dirs));
        data.read((char*)&sizeuni, 4);
        char univs[sizeuni];
        data.read(univs, sizeof(univs));

        this->list<<QString::number(cuenta);
        this->list<<names;
        this->list<<QString::number(age);
        this->list<<dirs;
        this->list<<univs;

        ui->plainTextEdit->insertPlainText("---------");
        ui->plainTextEdit->insertPlainText("Registro #");
        ui->plainTextEdit->insertPlainText(QString::number(d+1));
       ui->plainTextEdit->insertPlainText("---------\n");
        while(!this->list.isEmpty()){

            ui->plainTextEdit->insertPlainText(fields.at(index));
            ui->plainTextEdit->insertPlainText(list.takeFirst());
            ui->plainTextEdit->insertPlainText("\n");
            index++;

            if(index == 5)
                index = 0;
        }
        d++;
    }
    data.close();
}


void tarea2::on_savebtn_clicked()
{

    if(ui->nombreline->text().isEmpty() || ui->cuentaline->text().isEmpty() || ui->direccionline->text().isEmpty() || ui->universidadline->text().isEmpty() || ui->edadline->text().isEmpty()){
        QMessageBox msg;
        msg.setText("POR FAVOR LLENA TODOS LOS CAMPOS!");
        msg.exec();
        return;
    }else
        this->Write();
}

void tarea2::on_printBtn_clicked()
{
    this->Print();

}

void tarea2::on_buscarbtn_clicked()
{
   if(ui->searchline->text().isEmpty()){
       QMessageBox msg;
       msg.setText("EL CAMPO DE BUSQUEDA ESTA VACIO!");
       msg.exec();
   }else
   this->Read(ui->searchline->text().toInt());

}

void tarea2::on_clearBtn_clicked()
{

    QMessageBox::StandardButton resp;
    resp = QMessageBox::question(this, "Clear Data", "Estas seguro de borrar todo?"
                          ,QMessageBox::Yes | QMessageBox::No);

    if(resp == QMessageBox::Yes){
    ui->plainTextEdit->clear();
    ui->cuentaline->clear();
    ui->searchline->clear();
    ui->direccionline->clear();
    ui->edadline->clear();
    ui->nombreline->clear();
    ui->universidadline->clear();
    ofstream out;
    ofstream ind;
    out.open("data.chip", ios::binary | ios::trunc);
    ind.open("indexes.chip", ios::binary | ios::trunc);
    out.close();
    ind.close();

    }else{
        return;
    }

}

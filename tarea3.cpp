#include "tarea3.h"
#include "ui_tarea3.h"
#include <QDebug>
#include "QMessageBox"
//Bitwise operators
using namespace std;
Tarea3::Tarea3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea3)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);


}

Tarea3::~Tarea3()
{
    delete ui;
}

void Tarea3::TurnOnOffBit(int position)
{

    //XOR operator
    number = number ^ 1 << position;
    this->UpdateNumber(number);
    qDebug()<<number;
    this->ShowInBinary(number);
    
}

void Tarea3::ShowInBinary(int number)
{

    if(number<=255){
        this->toBinary(number, 8);
    }else if(number<=65536){
        this->toBinary(number, 16);
    }else if(number<=16777215){
        this->toBinary(number, 24);
    }else if(number<=4294967295){
        this->toBinary(number, 32);
    }else{
        QMessageBox msg;
        msg.setText("INTEGER OUT OF BOUNDS!");
        msg.exec();
        return;
    }



}

void Tarea3::UpdateNumber(int num)
{
    this->number =  num;
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(QString::number(num));
}

void Tarea3::toBinary(int num, int bits)
{
    QString binary("");
    int maxnumber = 1 <<bits-1;
    for(int i = 0; i<bits; i++){
        if((number & maxnumber) == 0)
            binary.append("0");
        else
            binary.append("1");

        maxnumber >>= 1;

    }

    ui->plaintextbinary->clear();
    ui->plaintextbinary->insertPlainText(binary);
    binary.clear();
}

void Tarea3::Save()
{
    ofstream data("numbers.chip" , ios::binary);
    if(data.is_open()){
        data.write((char*)&this->number, 4);
        QMessageBox msg;
        msg.setText("DATA WAS SAVED CORRECTLY!");
        msg.exec();
    }

    data.close();
}

void Tarea3::Load()
{
    ifstream data("numbers.chip", ios::binary);
    data.seekg(0, ios::beg);
    if(!data.is_open()){
        QMessageBox msg;
        msg.setText("LOADING ERROR IN FILE!");
        msg.exec();
        return;
    }
    int value;
    data.read((char*)&value, 4);
    data.close();
    number = value;
    ui->plainTextEdit->clear();
    ui->linenumber->clear();
    ui->lineposition->clear();
    ui->plainTextEdit->insertPlainText(QString::number(number));
    this->ShowInBinary(number);



}

void Tarea3::on_SetNumberBtn_clicked()
{
    if(ui->linenumber->text().isEmpty()){
        QMessageBox msg;
        msg.setText("No number was entered!");
        msg.exec();
        return;

    }
    number = ui->linenumber->text().toInt();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(ui->linenumber->text());
    this->ShowInBinary(number);

}

void Tarea3::on_TurnOnOffBtn_clicked()
{
    if(ui->lineposition->text().isEmpty()){
        QMessageBox msg;
        msg.setText("No position was entered!");
        msg.exec();
        return;
    }

    this->TurnOnOffBit(ui->lineposition->text().toInt());

}

void Tarea3::on_SaveBtn_clicked()
{
    if(ui->linenumber->text().isEmpty()){
        return;
    }
    this->Save();
}

void Tarea3::on_LoadBtn_clicked()
{
    this->Load();
}

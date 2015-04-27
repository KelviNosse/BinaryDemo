#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Data Info");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if(ui->lineEdit->text().contains('|') || ui->lineEdit_2->text().contains('|') || ui->lineEdit_3->text().contains('|') || ui->lineEdit_4->text().contains('|') || ui->lineEdit_5->text().contains('|')){
        QMessageBox msg;
        msg.setText("INVALID CHARACTER");
        msg.exec();
        return;
    }

    bin.Write(ui->lineEdit->text(),ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text(), ui->lineEdit_4->text(),ui->lineEdit_5->text());


}

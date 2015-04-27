#include "binaries.h"
#include "QMessageBox"
#define INVALIDCHAR '|'

QString binaries::campos[5] = {"Numero de Cuenta: ", "Nombre: ", "Carrera: ", "Fecha de Nacimiento: ", "Universidad: "};

binaries::binaries()
{
}


bool binaries::ContainsProhibitedChar(QString data){
    string dat = data.toStdString();
    return dat.find(INVALIDCHAR, 0) != -1;

}

int binaries::GetPosData(QString numdecuenta)
{
    ifstream arch("info.data", ios::binary);
    int currentpos = 0;
    int posdata = 0;
    arch.seekg(0, ios::end);
    int size = arch.tellg();
    string placeof("");
    bool flag = true;
    arch.seekg(0, ios::beg);

    for(int i = 0; i< size-1; i++){
        char data;
        arch.get(data);
        if(data == INVALIDCHAR){

            if(placeof.compare(numdecuenta.toLatin1().data()) == 0)
                return posdata;

            if(!placeof.empty())
                placeof.clear();

            currentpos++;

            if(currentpos == 5){
                currentpos  = 0;
                flag = true;
            }

            continue;
        }

        if(currentpos == 0){
            if(flag){
                posdata = arch.tellg()-1;
                flag = false;
                placeof.append(data+"");
            }
        }

    }

    return -1;

}


void binaries::Write(QString name, int numdecuenta, QString carrera, QString fecha, QString uni)
{
    QString namedat = name;
    QByteArray bytes = namedat.toUtf8();
    QByteArray bytes2 = carrera.toUtf8();
    QByteArray bytes3 = fecha.toUtf8();
    QByteArray bytes4 = uni.toUtf8();
    QByteArray bytes5 = (QString::number(numdecuenta)).toUtf8();

    int length = bytes.size();
    int length2 = bytes2.size();
    int length3 = bytes3.size();
    int length4 = bytes4.size();
    int length5 = bytes5.size();

    char nameof[length+1];
    char account[length5+1];
    char carreer[length2+1];
    char date[length3+1];
    char universidad[length4+1];

    ofstream archive("info.data", ios::out | ios::binary | ios::app);
    name.append(INVALIDCHAR);
    QString numberaccount = QString::number(numdecuenta);
    numberaccount.append(INVALIDCHAR);
    carrera.append(INVALIDCHAR);
    fecha.append(INVALIDCHAR);
    uni.append(INVALIDCHAR);
    strcpy(nameof,name.toLatin1().data());
    strcpy(account, numberaccount.toLatin1().data());
    strcpy(carreer,carrera.toLatin1().data());
    strcpy(date, fecha.toLatin1().data());
    strcpy(universidad, uni.toLatin1().data());
    archive.write(account, sizeof(account));
    archive.write(nameof,sizeof(nameof));
    archive.write(carreer, sizeof(carreer));
    archive.write(date, sizeof(date));
    archive.write(universidad,sizeof(universidad));
    archive.close();



}

QString binaries::Read(int numdecuenta)
{
    ifstream *data = new ifstream("info.data", ios::binary | ios::ate);
    if(!data){

       return "ERROR DE ARCHIVO!";
    }
    int datapos = this->GetPosData(QString::number(numdecuenta));

    if(datapos == -1){
        data->close();
        return "REGISTRO NO ENCONTRADO";

    }

    data->seekg(datapos);
    int currentindex = 0;
    QString info;
    while(true){
        char content;
        data->get(content);

        if(content == INVALIDCHAR){
            currentindex++;
            if(currentindex == 5)
                break;

        }else{
            qDebug()<<content;
        }

    }
    qDebug()<<endl;

    data->close();

    return "";



}

void binaries::Print()
{
    ifstream data("info.data",ios::binary);
    if(!data.is_open()){
                    QMessageBox msg;
                    msg.setText("ERROR DE ARCHIVO!");
                    msg.exec();
                    return;
        }else{

    data.seekg(0, data.end);
    int size = data.tellg();
    data.seekg(0);

    cout<<"FILE SIZE: "<<size<<endl;
    int index = 0;
    qDebug()<<binaries::campos[index];

    for(int i = 0; i<size-1; i++){

                    char content;
                    data.get(content);
                    if(content == INVALIDCHAR){
                    index++;
                    if(index == 5){
                    index = 0;

        }

                    qDebug()<<binaries::campos[index];

        }
        else{
            qDebug()<<content;
        }
        }
            qDebug()<<endl;


            data.close();

        }


}



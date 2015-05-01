#ifndef BINARIES_H
#define BINARIES_H
#include "fstream"
#include "iostream"
#include <ostream>
#include <string>
#include "QString"
#include <QDebug>

using namespace std;

class binaries
{
public:
    binaries();
    int filelength = 0;
    static QString campos[5];
    void Write(QString name, int numdecuenta, QString carrera, QString fecha, QString uni);
    QString Read(int numdecuenta);
    void Print();
    void SetLength(int len);
    bool ContainsProhibitedChar(QString data);
    int GetPosData(QString numdecuenta);




};

#endif // BINARIES_H

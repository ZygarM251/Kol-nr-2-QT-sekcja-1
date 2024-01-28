#ifndef KLIENT_H
#define KLIENT_H

#include <QString>

class Klient
{
private:
    QString nazwa;
    QString adres;
    double wartosc;
    double rabat;
public:
    Klient();
    Klient(QString nazwa,QString adres,double wartosc);
    QString getNazwa(){return nazwa;}
    QString getAdres(){return adres;}
    double getWartosc(){return wartosc;}
    double getRabat(){return rabat;}
};

#endif // KLIENT_H

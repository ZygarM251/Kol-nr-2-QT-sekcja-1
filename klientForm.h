#ifndef KLIENTFORM_H
#define KLIENTFORM_H

#include <QDialog>

namespace Ui {
class Klient;
}

class Klient : public QDialog
{
    Q_OBJECT
signals:
    void dodajKlienta(QString nazwa,QString adres,double wartosc);
public:
    explicit Klient(QWidget *parent = nullptr);
    ~Klient();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Klient *ui;
};

#endif // KLIENTFORM_H

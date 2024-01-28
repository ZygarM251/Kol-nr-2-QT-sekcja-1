#include "klientForm.h"
#include "ui_klientForm.h"

Klient::Klient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Klient)
{
    ui->setupUi(this);
    ui->Rabat->setMinimum(0);
    ui->Rabat->setMaximum(100);
}

Klient::~Klient()
{
    delete ui;
}

void Klient::on_buttonBox_accepted()
{
    QString nazwa = ui->Nazwa->toPlainText();
    QString adres = ui->Adres->toPlainText();
    double wartosc= ui->Wartosc->value();

    emit dodajKlienta(nazwa,adres,wartosc);
}


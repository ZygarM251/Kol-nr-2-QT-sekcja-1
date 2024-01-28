#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->Rabat->setMinimum(1);
    ui->Rabat->setMaximum(100);

    ui->Wartosc->setMinimum(1);
    ui->Wartosc->setMaximum(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QString nazwa = ui->Nazwa->toPlainText();
    QString adres = ui->Adres->toPlainText();
    double wartosc = ui->Wartosc->value();
    double rabat = ui->Rabat->value();


    emit dodajKlienta(nazwa,adres,wartosc,rabat);
}


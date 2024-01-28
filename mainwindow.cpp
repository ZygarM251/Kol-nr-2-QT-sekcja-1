#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap zdjecie("M:/Mariusz Zywar/Ja/Chorwacja 2021/jezyk.jpg");
    ui->label->setPixmap(zdjecie.scaled(400,400,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dodajKlienta(QString nazwa, QString adres, double wartosc, double rabat)
{
    double wartoscPoRabacie = wartosc - (wartosc * rabat / 100.0);
    listaKlientow.append(Klient(nazwa, adres, wartoscPoRabacie));

    int rowPosition = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowPosition);
    // Wprowadzanie danych
    ui->tableWidget->setItem(rowPosition, 0, new QTableWidgetItem(nazwa));
    ui->tableWidget->setItem(rowPosition, 1, new QTableWidgetItem(adres));
    ui->tableWidget->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(wartoscPoRabacie)));
    ui->tableWidget->sortItems(2, Qt::DescendingOrder);
}

void MainWindow::on_Dodaj_clicked()
{
    Dialog* Formularz = new Dialog(this);
    Formularz->show();

    connect(Formularz, SIGNAL(dodajKlienta(QString,QString ,double, double)), this, SLOT(dodajKlienta(QString,QString ,double, double)));
}

void MainWindow::suma()
{
    if (listaKlientow.isEmpty())
    {
        ui->textSuma->setText("Nie podano żadnych danych.");
            return;
    }
    int rozmiarListy = listaKlientow.size();
    double Suma=0.0;
    for (int nrKlienta = 0; nrKlienta < rozmiarListy; ++nrKlienta)
    {
        Suma+=listaKlientow[nrKlienta].getWartosc();
    }
    ui->textSuma->append(QString("<b>Suma Zamowienia wynosi:</b> %1").arg(Suma));

}

void MainWindow::on_Suma_clicked()
{
    suma();
}


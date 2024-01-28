#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QPixmap>
#include "klient.h"
#include"dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Dodaj_clicked();
    void dodajKlienta(QString nazwa,QString adres,double wartosc,double rabat);

    void on_Suma_clicked();
    void suma();

private:
    Ui::MainWindow *ui;
    QList<Klient> listaKlientow;
    QDialog* okno;
};
#endif // MAINWINDOW_H

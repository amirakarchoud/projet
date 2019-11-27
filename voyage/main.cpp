#include "mainwindow.h"
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    c.ouvrirConnexion();

    MainWindow w;
    w.show();

    return a.exec();
}

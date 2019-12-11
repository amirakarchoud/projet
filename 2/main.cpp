#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connexion c;
    MainWindow w;
        if (c.ouvrirConnexion())
        {
        w.show();
}
    return a.exec();}

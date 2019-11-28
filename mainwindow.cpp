#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
//#include "fiche.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tableView_3->setModel(tmpreclamation.afficher());
//ui->tableView_2->setModel(tmpfiche.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int num = ui->lineEdit->text().toInt();
    QString objet= ui->lineEdit_2->text();
    QString description = ui->lineEdit_3->text();
    QString lieu = ui->lineEdit_4->text();
    QString date = ui->lineEdit_5->text();
  reclamation e(num,objet,description,lieu,date);
  bool test=e.ajouter();
  if(test)
{ui->tableView_3->setModel(tmpreclamation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                  QObject::tr("ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    int num = ui->lineEdit->text().toInt();
    QString objet= ui->lineEdit_2->text();
    QString description = ui->lineEdit_3->text();
    QString lieu = ui->lineEdit_4->text();
    QString date = ui->lineEdit_5->text();

  reclamation e(num,objet,description,lieu,date);
  bool test=e.supprimer(num);

if(test)
{ui->tableView_3->setModel(tmpreclamation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer "),
                QObject::tr("Supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer "),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);//


}

/*void MainWindow::on_pb_ajouterf_clicked()
{
    int ref = ui->lineEdit_6->text().toInt();
    QString etat= ui->lineEdit_7->text();
    QString date = ui->lineEdit_8->text();
  fiche e(ref,etat,date);
  bool test=e.ajouter();
  if(test)
{ui->tableView_2->setModel(tmpfiche.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                  QObject::tr("ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer2_clicked()
{
    //int ref = ui->lineEdit_17->text().toInt();

  //fiche e(ref,etat,date);
  bool test=tmpfiche.supprimer();

if(test)
{ui->tableView_2->setModel(tmpfiche.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer "),
                QObject::tr("Supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer "),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);//


}*/



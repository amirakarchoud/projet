#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "fiche.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

//ui->stackedWidget_2->setCurrentIndex(2);

ui->tabb->setModel(tmpr.afficher());
ui->tableview->setModel(tmpc.afficher());
ui->tabb->setModel(tmpr.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;

}
/*
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);


}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}*/
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabb->setModel(tmpr.afficher());
}

void MainWindow::on_pb_ajouter_clicked()
{

    int num = ui->line->text().toInt();
    QString objet = ui->lineEdit_objet->text();
    QString description= ui->lineEdit_description->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString datee= ui->lineEdit_date->text();

      reclamation e(num,objet,description,lieu,datee);
      bool test=e.ajouter();
      if(test)
    {ui->tabb->setModel(tmpr.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un reclamation"),
                      QObject::tr("reclamation ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une reclamation"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}
void MainWindow::on_pb_supprimer_clicked()
{


    int num= ui->lineEdit_id_2->text().toInt();
    bool test=tmpr.supprimer(num);

if(test)
{ui->tabb->setModel(tmpr.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                QObject::tr("reclamation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("supprimer une reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);//


}


void MainWindow::on_pushButton_9_clicked()
{
    int num = ui->lineEdit_9->text().toInt();
    QString objet = ui->lineEdit_10->text();
    QString description= ui->lineEdit_11->text();
    QString lieu= ui->lineEdit_14->text();
    QString datee= ui->lineEdit_15->text();
    reclamation r;
    if(r.rech(num)){
        bool test = r.Modifier(num,objet,description,lieu,datee);
        if(test){
            ui->tabb->setModel(tmpr.afficher());
            QMessageBox::information(nullptr,QObject::tr("reclamation modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}
 void MainWindow::on_pushButton_3_clicked()
{
    int ref = ui->lineEdit->text().toInt();
    QString etat= ui->lineEdit_3->text();
    QString date= ui->lineEdit_2->text();
  fiche f(ref,etat,date);
  bool test=f.ajouter();
  if(test)
{ui->tableview->setModel(tmpc.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une fiche"),
                  QObject::tr("fiche ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une fiche"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  void MainWindow::on_pushButton_4_clicked()
  {


      int ref = ui->lineEdit_5->text().toInt();
      bool test=tmpc.supprimer(ref);

  if(test)
  {ui->tableview->setModel(tmpc.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Supprimer une fiche"),
                  QObject::tr("fiche supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("supprimer une fiche"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);//


  }

 void MainWindow::on_pushButton_6_clicked()
  {
     int ref = ui->lineEdit_7->text().toInt();
     QString etat= ui->lineEdit_8->text();
     QString date= ui->lineEdit_12->text();
      fiche f;
      if(f.rech(ref)){
          bool test = f.Modifier(ref,etat,date);
          if(test){
              ui->tableview->setModel(tmpc.afficher());
              QMessageBox::information(nullptr,QObject::tr("commande modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
      }}



void MainWindow::on_trie_clicked()
{
    reclamation c;

         if(c.trier()){

                 ui->tab_12->setModel(tmpr.trier());
                 QMessageBox::information(nullptr, QObject::tr("trier les reclamation"),
                             QObject::tr("reclamation triées.\n"
                                         "Voulez-vous enregistrer les modifications ?"),
                                    QMessageBox::Save
                                    | QMessageBox::Cancel,
                                   QMessageBox::Save);

             }
             else
                 QMessageBox::critical(nullptr, QObject::tr("trier les reclamation"),
                             QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_actualiser_clicked()
{
    ui->tabb->setModel(tmpr.afficher());
}





void MainWindow::on_act_clicked()
{
    ui->tableview->setModel(tmpc.afficher());
}

void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
    QString etat = arg1;
    ui->tableview->setModel(tmpc.rech_fiches(etat));
}

#include "malek.h"
#include "ui_malek.h"
#include "reclamation.h"
#include "fiche.h"
#include <QMessageBox>
#include "med.h"
#include "rouaa.h"
#include "amira.h"
#include "adhir.h"
#include "nadhir.h"

malek::malek(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::malek)
{
ui->setupUi(this);


ui->tabb->setModel(tmpr.afficher());
ui->tableview->setModel(tmpc.afficher());

}

malek::~malek()
{
    delete ui;
}

void malek::on_tabWidget_currentChanged(int index)
{
    ui->tabb->setModel(tmpr.afficher());
}

void malek::on_pb_ajouter_clicked()
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
void malek::on_pb_supprimer_clicked()
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

void malek::on_trierfournisseur_clicked()
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
void malek::on_pushButton_9_clicked()
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
 void malek::on_pushButton_3_clicked()
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
  void malek::on_pushButton_4_clicked()
  {


      int ref = ui->lineEdit_3->text().toInt();
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

 void malek::on_pushButton_6_clicked()
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



void malek::on_pushButton_5_clicked()
{
    rouaa a;
    hide();
    a.exec();
}

void malek::on_pushButton_14_clicked()
{
    adhir a;
    hide();
    a.exec();
}

void malek::on_pushButton_15_clicked()
{
    amira a;
    hide();
    a.exec();
}

void malek::on_pushButton_16_clicked()
{
    med a;
    hide();
    a.exec();
}

void malek::on_pushButton_17_clicked()
{
    nadhir a;
    hide();
    a.exec();
}

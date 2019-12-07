#include "nadhir.h"
#include "ui_nadhir.h"
#include "ligne.h"
#include "station.h"
#include <QMessageBox>
nadhir::nadhir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nadhir)
{
ui->setupUi(this);
ui->tabligne->setModel(tmpLigne.afficher());
ui->tabstation->setModel(tmpstation.afficher());

}

nadhir::~nadhir()
{
    delete ui;
}

void nadhir::on_pb_ajouter_clicked()
{
    int refligne = ui->lineEdit_refligne->text().toInt();
    QString statdep= ui->lineEdit_statdep->text();
    QString statarr= ui->lineEdit_statarr->text();
    int distance= ui->lineEdit_distance->text().toInt();
  Ligne e(refligne,statdep,statarr,distance);
  if( e.controleidentique(statdep,statarr) && e.ControleNumeroString(statdep) && e.controleNumber(refligne) && !e.recherche(refligne) && e.ControleNumeroString(statarr) && e.controleNumber(distance))
{  e.ajouter();
      tmpLigne.soundcorrect();

      ui->tabligne->setModel(tmpLigne.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une ligne"),
                  QObject::tr("ligne ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      tmpLigne.sounderreur();

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une ligne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}


}

void nadhir::on_pb_supprimer_clicked()
{
int refligne = ui->ref_delete->text().toInt();
bool test=tmpLigne.supprimer(refligne);
if(test)
{      tmpLigne.soundcorrect();

    ui->tabligne->setModel(tmpLigne.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une ligne"),
                QObject::tr("ligne supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une ligne"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void nadhir::on_pb_modifier_clicked()
{
    int refligne = ui->lineEdit_id_modif->text().toInt();
    QString statdep= ui->lineEdit_nom_modif->text();
    QString statarr= ui->lineEdit_etats_modif->text();
    int distance= ui->lineEdit_number_modif->text().toInt();
    Ligne e(refligne,statdep,statarr,distance);
    bool test=tmpLigne.modifier(refligne,statdep,statarr,distance);
    if(test)
    {      tmpLigne.soundcorrect();

        ui->tabligne->setModel(tmpLigne.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier une ligne"),
                    QObject::tr("ligne modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une ligne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void nadhir::on_pushButton_recherche_clicked()
{

            QString refligne = ui->lineEdit_recheche->text();
            ui->tabligne->setModel(tmpLigne.recherche(refligne));//refresh
}

void nadhir::on_pushButton_trie_clicked()
{
    int refligne = ui->lineEdit_recheche->text().toInt();

    ui->tabligne->setModel(tmpLigne.trie(refligne));//refresh

}
void nadhir::on_pb_ajouter_2_clicked()
{
    int numstation = ui->lineEdit_numstation_ajout->text().toInt();
    QString locstation= ui->lineEdit_locstation_ajout->text();
  station s(numstation,locstation);

      if(s.ControleNumeroString(locstation) && s.controleNumber(numstation)&& !s.recherche(numstation))
{  s.ajouter();
          tmpstation.soundcorrect();

          ui->tabstation->setModel(tmpstation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une station"),
                  QObject::tr("station ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else{
          tmpstation.sounderreur();

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une station"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}


}

void nadhir::on_pb_supprimer_2_clicked()
{
    int numstation = ui->lineEdit_numstation_supp->text().toInt();
    bool test=tmpstation.supprimer(numstation);
    if(test)
    {ui->tabstation->setModel(tmpstation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une station"),
                    QObject::tr("station supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une staion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void nadhir::on_pushButton_recherche2_clicked()
{

    QString numstation = ui->lineEdit_recherche2->text();
    ui->tabstation->setModel(tmpstation.recherche(numstation));//refresh
}


void nadhir::on_pb_modifier__clicked()
{
    int numstation = ui->lineEdit_numstation_modifer->text().toInt();
    QString locstation= ui->lineEdit_locstation_modifier->text();

    station s(numstation,locstation);
    bool test=tmpstation.modifier(numstation,locstation);
    if(test)
    {ui->tabstation->setModel(tmpstation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier une station"),
                    QObject::tr("station modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une station"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void nadhir::on_pushButton_statistique_clicked()
{
   QString locstation= ui->lineEdit_stat->text();
   double tmp=tmpstation.stat(locstation);
   QString res=QString::number(tmp);
   ui->lineEdit_statistique->setText(res);

}

void nadhir::on_pushButton_clicked()
{
    QString tmp=tmpLigne.min();
    ui->lineEdit_min->setText(tmp);
    QString tmp2=tmpLigne.max();
    ui->lineEdit_max->setText(tmp2);
}
void nadhir::on_locstation_clicked()
{
    ui->tabstation->setModel(tmpstation.trie2());

}
void nadhir::on_numstation_clicked()
{
    ui->tabstation->setModel(tmpstation.trie());

}

void nadhir::on_pushButton_2_clicked()
{
    int refligne = ui->lineEdit_refligne->text().toInt();
    int numstation = ui->lineEdit_2->text().toInt();
    tmpLigne.affecter(refligne,numstation);
    ui->tableViewaffecter->setModel(tmpLigne.AfficherAffecter());
}

#include "adhir.h"
#include "ui_adhir.h"
#include "vehicule.h"
#include "panne.h"
#include <QMessageBox>
#include <QString>
#include <QIntValidator>
#include "smtp.h"
#include "med.h"
#include "rouaa.h"
#include "amira.h"
#include "nadhir.h"
#include "malek.h"


adhir::adhir(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adhir)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));

    ui->tabvehicule->setModel(tmpvehicule.afficher());
     ui->tabpanne->setModel(tmppanne.afficher());
    ui->id_vehicule->setValidator(new QIntValidator(0,9999,this));


         ui->con_vehicule->setValidator(new QIntValidator(0,9999,this));
         ui->chau_vehicule->setValidator(new QIntValidator(0,9999,this));
        // ui->    id_vehicule_panne->setValidator(new QIntValidator(0,9999,this));
         ui->    chauf_panne->setValidator(new QIntValidator(0,9999,this));

         QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select id from vehicule");
         ui->comboBox_3->setModel(model);

}

adhir::~adhir()
{
    delete ui;
}


void adhir::on_pushButton_clicked()
{
    int id = ui->id_vehicule->text().toInt();
    int chau= ui->chau_vehicule->text().toInt();
    int con= ui->con_vehicule->text().toInt();
    QString type= ui->comboBox->currentText();
  vehicule v(id,chau,con ,type);
  bool test=v.ajouter();
  if(test)
{ui->tabvehicule->setModel(tmpvehicule.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un vehicule"),
                  QObject::tr("vehicule ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vehicule"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void adhir::on_pushButton_3_clicked()
{
    int idvehicule = ui->comboBox_3->currentText().toInt();
    int chauvehicule= ui->chauf_panne->text().toInt();
     QString typepanne= ui->comboBox_2->currentText();
  panne p (idvehicule,chauvehicule ,typepanne);
  bool test=p.ajouter();
  if(test)
{ui->tabpanne->setModel(tmppanne.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une panne"),
                  QObject::tr("panneajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un panne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void adhir::on_pushButton_2_clicked()
{
    long id=ui->id_vehicule->text().toLong();
    bool test=tmpvehicule.supprimer(id);
    if(test)
    {ui->tabvehicule->setModel(tmpvehicule.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un vehicule"),
                    QObject::tr("vehicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un vehicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void adhir::on_pushButton_4_clicked()
{
    long idvehicule=ui->id1_vehicule_panne->text().toLong();
    bool test=tmppanne.supprimer(idvehicule);
    if(test)
    {ui->tabpanne->setModel(tmppanne.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une panne"),
                    QObject::tr("panne supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une panne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}







void adhir::on_pushButton_6_clicked()
{

    QString type = ui->lineEdit->text();
       ui->tabvehicule_2->setModel(tmpvehicule.cherch_type(type));
}


void adhir::on_pushButton_7_clicked()
{ ui->tabvehicule_3->setModel(tmpvehicule.afficher_tri_chau());

}

void adhir::on_pushButton_8_clicked()
{int idvehicule = ui->id123->text().toInt();
      QString typepanne = ui->panne123->text();



        bool test=tmppanne.modifier(idvehicule,typepanne);
        if(test)
        {ui->tabpanne->setModel(tmppanne.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier une panne"),
                        QObject::tr("panne modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier une"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
   }

void adhir::on_pushButton_9_clicked()
{
    QString typepanne = ui->cher1->text();
       ui->tabpanne_2->setModel(tmppanne.cherch_type_panne(typepanne));
}

void adhir::on_pushButton_10_clicked()
{
    ui->tabvehicule_3->setModel(tmpvehicule.afficher_tri_type());
}

void adhir::on_pushButton_11_clicked()
{
     ui->tabpanne_3->setModel(tmppanne.afficher_tri_id());
}

void adhir::on_pushButton_12_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.afficher_tri_type_panne());
}

void adhir::on_pushButton_13_clicked()
{
    {int id = ui->id2_vehicule->text().toInt();
       int chau = ui->chau2_vehicule->text().toInt();


            bool test=tmpvehicule.modifier(id,chau);
            if(test)
            {ui->tabvehicule->setModel(tmpvehicule.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("modifier un vehicule"),
                            QObject::tr("vehicule modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modifier un vehicule"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}}

//email

void adhir::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void adhir::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void adhir::on_pushButton_5_clicked()
{
    rouaa a;
    hide();
    a.exec();
}

void adhir::on_pushButton_15_clicked()
{
    amira a;
    hide();
    a.exec();
}

void adhir::on_pushButton_16_clicked()
{
    med a;
    hide();
    a.exec();
}

void adhir::on_pushButton_17_clicked()
{
    nadhir a;
    hide();
    a.exec();
}

void adhir::on_pushButton_18_clicked()
{
    malek a;
    hide();
    a.exec();
}

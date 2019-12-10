#include "rouaa.h"
#include "ui_rouaa.h"
#include "employe.h"
#include "conge.h"
#include <QMessageBox>
#include <QIntValidator>
#include "smtp.h"
#include "med.h"
#include "amira.h"
#include "adhir.h"
#include "nadhir.h"
#include "malek.h"
rouaa::rouaa(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rouaa)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    Conge c;
    Employe e;

    ui->tabemp->setModel(tmpemploye.afficher());
    ui->tabcong->setModel(tmpconge.afficher());
     ui->lineEdit_cin->setValidator(new QIntValidator(0,99999,this));
      ui->lineEdit_id->setValidator(new QIntValidator(0,99999,this));
      ui->lineEdit_nom->setInputMask("aaaaaaaaaaaaaaaaa");
         ui->lineEdit_prenom->setInputMask("aaaaaaaaaaaaaaaa");
          //ui->lineEdit_grade->setInputMask("aaaaaaaaaaaaaaaaa");
           //ui->lineEdit_type->setInputMask("aaaaaaaaaaaaaaaa");
           ui->tabemp->setModel(tmpconge.afficher());
           ui->tabemp_5->setModel(c.trier(true,true));
           ui->tabemp_6->setModel(e.trier(true,true));

           QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select CIN from conge");
           ui->comboBoxconge->setModel(model);


}

rouaa::~rouaa()
{
    delete ui;
}


void rouaa::on_pb_ajouter_5_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
      QString grade= ui->comboBoxgrade->currentText();
     int cin = ui->lineEdit_cin->text().toInt();
     QString mdp= ui->mdp->text();
  Employe e(nom,prenom,grade,cin,mdp);
  bool test=e.ajouter();
  if(test)

 {ui->tabemp->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}








void rouaa::on_pb_ajouter_6_clicked()
{
    int cin = ui->lineEdit_cin_2->text().toInt();
        QString grade= ui->lineEdit_grade_2->text();

        bool test=tmpemploye.modifier(grade,cin);
        if(test)
        {ui->tabemp->setModel(tmpemploye.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                        QObject::tr("employe modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void rouaa::on_pb_ajouter_7_clicked()
{

    long cin=ui->lineEdit_id_19->text().toLong();
    bool test=tmpemploye.supprimer(cin);
    if(test)
    {ui->tabemp->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("employe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         }



void rouaa::on_ajoute_cong_clicked()
{

      QString type= ui->comboBoxtype->currentText();
     int id_conge = ui->lineEdit_id->text().toInt();
      int cin = ui->comboBoxconge->currentText().toInt();
  Conge c(type,id_conge,cin);
  bool test=c.ajouter();
  if(test)
{ui->tabcong->setModel(tmpconge.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                  QObject::tr("conge ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}




void rouaa::on_ajoute_cong_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
        QString type= ui->lineEdit_type_2->text();

        bool test=tmpconge.modifier(type,id);
        if(test)
        {ui->tabcong->setModel(tmpconge.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un conge"),
                        QObject::tr("conge modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un conge"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void rouaa::on_pb_ajouter_8_clicked()
{
    int id = ui->lineEdit_id_20->text().toInt();
    bool test=tmpconge.supprimer(id);
    if(test)
    {ui->tabcong->setModel(tmpconge.afficher());//refresh


        QMessageBox::information(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("conge supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         }




void rouaa::on_pb_ajouter_9_clicked()
{
    QString grade = ui->lineEdit_cin_3->text();
     ui->tabemp_2->setModel(tmpemploye.rechercher(grade));

         bool test=tmpemploye.rechercher(grade);
         if(test)
         {ui->tabemp_2->setModel(tmpemploye.rechercher(grade));//refresh
             QMessageBox::information(nullptr, QObject::tr("chercher employe"),
                         QObject::tr("employe trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un employe"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}




void rouaa::on_radioButton_23_toggled(bool checked)
{
    Conge c;
    ui->tabemp_5->setModel(c.trier(checked,ui->radioButton_22->isChecked()));
}

void rouaa::on_radioButton_24_toggled(bool checked)
{
    Conge c ;
    ui->tabemp_5->setModel(c.trier(ui->radioButton_21->isChecked(),checked));
}

void rouaa::on_radioButton_27_toggled(bool checked)
{
    Employe e;
    ui->tabemp_6->setModel(e.trier(checked,ui->radioButton_28->isChecked()));
}





void rouaa::on_radioButton_25_toggled(bool checked)
{
    Employe e;
    ui->tabemp_6->setModel(e.trier(checked,ui->radioButton_25->isChecked()));
}

void rouaa::on_pb_ajouter_10_clicked()
{
    QString type = ui->lineEdit_cin_4->text();
     ui->tabcong_2->setModel(tmpconge.rechercher(type));

         bool test=tmpconge.rechercher(type);
         if(test)
         {ui->tabcong_2->setModel(tmpconge.rechercher(type));//refresh
             QMessageBox::information(nullptr, QObject::tr("chercher un conge"),
                         QObject::tr("conge trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un conge"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void rouaa::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void rouaa::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}







void rouaa::on_pushButton_14_clicked()
{
    adhir a;
    hide();
    a.exec();
}

void rouaa::on_pushButton_15_clicked()
{
    amira a;
    hide();
    a.exec();
}

void rouaa::on_pushButton_16_clicked()
{
    med a;
    hide();
    a.exec();
}

void rouaa::on_pushButton_17_clicked()
{
    nadhir a;
    hide();
    a.exec();
}

void rouaa::on_pushButton_18_clicked()
{
    malek a;
    hide();
    a.exec();
}

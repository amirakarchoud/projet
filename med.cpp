#include "med.h"
#include "ui_med.h"
#include "abonne.h"
#include "abonnement.h"
#include "smtp.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QString>
#include <QRegExp>
#include "statistique.h"
//#define NOM_RX "^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$"
#define CARACTERE_EX "^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$"
#define EMAIL_RX "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$"

med::med(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::med)
{
ui->setupUi(this);
ui->tababonne->setModel(tmpabonne.afficher());
ui->tababonnement->setModel(tmpabonnement.afficher());

this->setWindowTitle("gestion des clients");//modifier le nom de l'application
//resize(870, 550);//modifier la taille de l'app
//pour valider cin
QIntValidator *cin =new QIntValidator(1,10000000);
ui->lineedit_cin->setValidator(cin);
//ui->lineedit_cin_2->setValidator(cin);

ui->comboBox->setModel(tmpabonnement.modelref());
//pour valider les nom
//QRegExp rxline_edit;
//QRegExpValidator *line_edit=new QRegExpValidator(rxline_edit,this);
//ui->lineEdit_nom->setValidator(line_edit);

//pour valider un email
//QRegExp rx_email(EMAIL_RX);
//QRegExpValidator *email =new QRegExpValidator(rx_email,this);
//ui->lineEdit_email->setValidator(email);


//email

connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));





}

med::~med()
{
    delete ui;
}

void med::on_pb_ajouter_clicked()
{
    int cin = ui->lineedit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int numero = ui->lineEdit_numero->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    QString sexe1=sexe;
    QString email= ui->lineEdit_email->text();




  Abonne a(cin,nom,prenom,numero,adresse,sexe1,email);
  bool test=a.ajouter();
  if(test)
{ui->tababonne->setModel(tmpabonne.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Client"),
                  QObject::tr("Client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void med::on_pb_supprimer_clicked()
{
    int cinn = ui->lineEdit_cin_2->text().toInt();
    bool test=tmpabonne.supprimer(cinn);
    if(test)
    {ui->tababonne->setModel(tmpabonne.afficher());//refresh
     ui->tababonnement->setModel(tmpabonnement.afficher());//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("clients supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void med::on_pb_ajouter_2_clicked()
{

    int cin = ui->comboBox->currentText().toInt();
    QString date= ui->lineEdit_nom_2->text();
    int id = ui->lineEdit_id->text().toInt();


    Abonnement aa(cin,id,date);
  bool test=aa.ajouter();
  if(test)
{ui->tababonnement->setModel(tmpabonnement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Abonnement"),
                  QObject::tr("Abonnement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void med::on_pb_supprimer_2_clicked()
{
    int cin = ui->lineedit_cin_3->text().toInt();
    bool test=tmpabonnement.supprimer(cin);
    if(test)
    {ui->tababonnement->setModel(tmpabonnement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Abonnement"),
                    QObject::tr("Abonnement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Abonnement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





void med::on_pb_modif_clicked()
{
    int cin = ui->cin_modif->text().toInt();
    int numero = ui->numero_modif->text().toInt();
    QString adresse = ui->adresse_modif->text();
    QString email = ui->email_modif->text();
    Abonne a;
    if(a.recherche_cin(cin)){
        bool test = a.modifier(cin,numero,adresse,email);
        if(test){
            ui->tababonne->setModel(tmpabonne.afficher());
            QMessageBox::information(nullptr,QObject::tr("client modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }

}

//rechercher nom ( verifier)
void med::on_pushButton_recherche_nom_clicked()
{
    QString nom = ui->recherche_nom->text();
    ui->tabrecherche->setModel(tmpabonne.cherch_nom(nom));
}

void med::on_tri_cin_clicked()
{
    ui->tababonne->setModel(tmpabonne.afficher_tri_cin());

}

void med::on_lineEdit_nom_textEdited(const QString &arg1)
{
    QString text=arg1;
    /*QString caractere_ex(CARACTERE_EX);
    for (int i=0;i<text.size();i++)
    {
        foreach(const QChar &y,caractere_ex)
            if(text.at(i)==y)
                text[i]=' ';
        ui->lineEdit_nom->setText(text);
    }*/
}

void med::on_pb_modif_abonnemnt_clicked()
{
    int cin = ui->modif_abonnement_cin->text().toInt();
    int id = ui->modif_abonnemnt_id->text().toInt();
    QString date = ui->modif_abonnemnt_date->text();

    Abonnement aa;
    if(aa.recherche_cin(cin)){
        bool test1 = aa.modifier(cin,date,id);
        if(test1){
            ui->tababonnement->setModel(tmpabonnement.afficher());
            QMessageBox::information(nullptr,QObject::tr("abonnement modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void med::on_tri_nom_clicked()
{
    ui->tababonne->setModel(tmpabonne.afficher_tri_nom());

}

//email

void med::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}


void med::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}





void med::on_radioButton_toggled(bool checked)
{
    if(checked)sexe="female";
}

void med::on_radioButton_2_toggled(bool checked)
{
    if(checked)sexe="male";
}

void med::on_statistique_clicked()
{
    statistique *a=new statistique();
    a->show();
}

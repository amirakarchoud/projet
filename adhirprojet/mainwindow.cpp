#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));

    ui->tabvehicule->setModel(tmpvehicule.afficher());
     ui->tabpanne->setModel(tmppanne.afficher());
    ui->id_vehicule->setValidator(new QIntValidator(0,9999,this));


         ui->con_vehicule->setValidator(new QIntValidator(0,9999,this));
         ui->chau_vehicule->setValidator(new QIntValidator(0,9999,this));
         ui->    id_vehicule_panne->setValidator(new QIntValidator(0,9999,this));
         ui->    chauf_panne->setValidator(new QIntValidator(0,9999,this));
         ui->type_panne->setInputMask("aaaaaaaaaaaaaaaaa");
         ui->type_vehicule->setInputMask("aaaaaaaaaaaaaaaaa");

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_vehicule_clicked()
{
    int id = ui->id_vehicule->text().toInt();
    int chau= ui->chau_vehicule->text().toInt();
    int con= ui->con_vehicule->text().toInt();
    QString type= ui->type_vehicule->text();
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

void MainWindow::on_supprimer_vehicule_clicked()
{
    int id = ui->id_vehicule->text().toInt();
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


void MainWindow::on_modifier_vehicule_clicked()
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
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_chercher_vehicule_clicked()
{
    QString type = ui->lineEdit->text();
       ui->tabvehicule_2->setModel(tmpvehicule.cherch_type(type));
}

void MainWindow::on_trier1_vehicule_clicked()
{
    ui->tabvehicule_3->setModel(tmpvehicule.afficher_tri_type());
}

void MainWindow::on_trier2_vehicule_clicked()
{
    ui->tabvehicule_3->setModel(tmpvehicule.afficher_tri_chau());
}

void MainWindow::on_ajouter_vehicule_2_clicked()
{
    int idvehicule = ui->id_vehicule_panne->text().toInt();
    int chauvehicule= ui->chauf_panne->text().toInt();
     QString typepanne= ui->type_panne->text();
          QString refpanne= ui->ref_panne->text();
  panne p (idvehicule,chauvehicule ,typepanne,refpanne);
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

void MainWindow::on_supprimer_panne_clicked()
{
    long idvehicule=ui->id_vehicule_panne->text().toLong();
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

void MainWindow::on_modifier_panne_clicked()
{
    int idvehicule = ui->id123->text().toInt();
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

void MainWindow::on_chercher_panne_clicked()
{
    QString typepanne = ui->cher1->text();
       ui->tabpanne_2->setModel(tmppanne.cherch_type_panne(typepanne));
}

void MainWindow::on_trier_panne1_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.afficher_tri_id());
}

void MainWindow::on_trier_panne2_clicked()
{
     ui->tabpanne_3->setModel(tmppanne.afficher_tri_type_panne());
}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

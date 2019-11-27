#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticket.h"
#include <QMessageBox>
#include "annonce.h"
#include <QDebug>
#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QAbstractButton>
#include <QSound>
#include <QSqlError>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    ui->taban->setModel(tmpannonce.afficher());
    ui->taban_2->setModel(tmpannonce.afficher());
     ui->tabanre->setModel(tmpannonce.afficher());
    ui->tabtic->setModel(tmpticket.afficher());
    ui->tabticrec->setModel(tmpticket.afficher());
    ui->tabticsup->setModel(tmpticket.afficher());
    ui->stationdep->setValidator(new QIntValidator(1, 1000, this));
    ui->stationar->setValidator(new QIntValidator(1, 1000, this));
    ui->cinp->setValidator(new QIntValidator(1, 99999999, this));
    ui->cinp->setMaxLength(8);
    ui->idan->setMaxLength(9);

    ui->lineEdit_id->setMaxLength(9);

    ui->lineEdit_5->setMaxLength(9);
    //this->setFixedSize(1000,1000);
   //this->centralWidget()->setFixedSize(10000,10000);
    //this->centralWidget()->resize(5000,5000);
    QSqlQueryModel * model= new QSqlQueryModel(),* model1= new QSqlQueryModel(),* model2= new QSqlQueryModel();

    model->setQuery("select id_a from Annonce");
    ui->comboBoxmodan->setModel(model);
    model1->setQuery("select id_ticket from ticket");
    ui->comboBoxtic->setModel(model1);
    model2->setQuery("select id_a from annonce");
    ui->idantic->setModel(model2);


     son=new QSound("C:/Users/Amira Karchoud/Desktop/button-29.wav");//location
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    QString id = ui->idan->text();
    QDate date= ui->date->date();//le type a confirmer et si kol haja wahdha ou ya9raha lkol mabaadhha normal
    QTime temps= ui->temps->time();//le type a confirmer
    int nums=ui->stationdep->text().toInt();
     int numa=ui->stationar->text().toInt();
     int nbr=ui->nbplace->text().toInt();
     int numv=ui->numveh->value();
     //ui->comboBoxsup->addItem(id);


  Annonce a(id,date,temps,nums,numa,nbr,numv);
  bool test=a.ajouter();
  if(test)
{ui->taban->setModel(tmpannonce.afficher());//refresh
      QStatusBar *statusBar = this->statusBar();
      statusBar->showMessage("annonce ajoutee !",5000);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une annonce"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->taban_2->setModel(tmpannonce.afficher());
   ui->tabanre->setModel(tmpannonce.afficher());
   QSqlQueryModel * model= new QSqlQueryModel(),* model2= new QSqlQueryModel();

   model->setQuery("select id_a from Annonce");
   ui->comboBoxmodan->setModel(model);
   model2->setQuery("select id_a from annonce");
   ui->idantic->setModel(model2);

}





void MainWindow::on_valdiersup_clicked()
{
    QString ch = ui->lineEdit_id->text();//changer en line edit ou lire check box..


    ui->taban->setModel(tmpannonce.afficher());//refresh
        QMessageBox msgBox;
          msgBox.setText("supprimer une annonce.");
          msgBox.setInformativeText("vous etes sur?");
          msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
          msgBox.setDefaultButton(QMessageBox::Yes);
          int ret = msgBox.exec();
        switch(ret)
        {
        case QMessageBox::Yes:
           tmpannonce.supprimer(ch);
           QStatusBar *statusBar = this->statusBar();
           statusBar->showMessage("annonce supprimee !",5000);
            ui->taban->setModel(tmpannonce.afficher());
            ui->taban_2->setModel(tmpannonce.afficher());
             ui->tabanre->setModel(tmpannonce.afficher());
            break;

        }


        QSqlQueryModel * model= new QSqlQueryModel(),* model2= new QSqlQueryModel();

        model->setQuery("select id_a from Annonce");
        ui->comboBoxmodan->setModel(model);
        model2->setQuery("select id_a from annonce");
        ui->idantic->setModel(model2);



}

void MainWindow::on_ajoutticket_clicked()
{
    QString id = ui->idantic->currentText();
    int c = ui->cinp->text().toInt();
    QString idt = ui->idt->text();

  Ticket t(idt,id,c);
  bool test=t.ajouter();
  if(test)
{ui->tabtic->setModel(tmpticket.afficher());//refresh
      QStatusBar *statusBar = this->statusBar();
      statusBar->showMessage("ticket ajoute !",5000);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  QSqlQueryModel * model1= new QSqlQueryModel();
  model1->setQuery("select id_ticket from ticket");
  ui->comboBoxtic->setModel(model1);
  ui->tabticrec->setModel(tmpticket.afficher());
  ui->tabticsup->setModel(tmpticket.afficher());

}

void MainWindow::on_pushButton_2_clicked()
{
    QString ch = ui->lineEdit_idt->text();

    QMessageBox msgBox;
      msgBox.setText("supprimer un ticket.");
      msgBox.setInformativeText("vous etes sur?");
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Yes);
      int ret = msgBox.exec();
    switch(ret)
    {
    case QMessageBox::Yes:
        tmpticket.supprimer(ch);
        QStatusBar *statusBar = this->statusBar();
        statusBar->showMessage("ticket supprime !",10000);
        ui->tabtic->setModel(tmpticket.afficher());

        ui->tabticrec->setModel(tmpticket.afficher());
        ui->tabticsup->setModel(tmpticket.afficher());
        break;

    }
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select id_ticket from ticket");
    ui->comboBoxtic->setModel(model1);


}

void MainWindow::on_appliquer_clicked()
{
    QString id = ui->comboBoxmodan->currentText();
    QTime t = ui->timeEditmod->time();
    QDate d=ui->datemod->date();
    int nbr=ui->nbplacemod->value();

    ui->taban->setModel(tmpannonce.afficher());//refresh
    QMessageBox msgBox;
      msgBox.setText("modifier une annonce.");
      msgBox.setInformativeText("vous etes sur?");
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Yes);
      int ret = msgBox.exec();
    switch(ret)
    {
    case QMessageBox::Yes:
         tmpannonce.modifier(id,t,d,nbr);
        ui->taban->setModel(tmpannonce.afficher());
        break;

    }

}


void MainWindow::on_pushButton_4_clicked()
{  //  ui->tabanre->clearSpans();
     QString id = ui->lineEdit_5->text();

    //bool test= tmpannonce.rechercher(id,st);
     ui->tabanre->setModel(tmpannonce.afficherrecherche(id));



}

void MainWindow::on_trier_clicked()
{  int x=0;
   if( ui->triidan->isChecked())
       x=1;
   else if( ui->tridate->isChecked())
       x=2;
   if (x!=0)
   ui->taban->setModel(tmpannonce.trier(x));
   else
   {
       QMessageBox msgBox;
         msgBox.setText("selectionner critere de tri !.");
         msgBox.setInformativeText("retour");
         msgBox.setStandardButtons(QMessageBox::Cancel);
         //msgBox.setDefaultButton(QMessageBox::Yes);
          msgBox.exec();
            QStatusBar *statusBar = this->statusBar();
            statusBar->showMessage("warning:selectionner critere de tri !",10000);
   }

}

void MainWindow::on_ajouter_pressed()
{   son->play();
    ui->ajouter->setStyleSheet("background-color: red;"
                               "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_ajouter_released()
{
     ui->ajouter->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);"
                                "border: 4px solid darkblue;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_appliquer_2_clicked()
{
    QString id = ui->comboBoxtic->currentText();
    QString idan = ui->idanmod->text();

    ui->tabtic->setModel(tmpticket.afficher());//refresh
    QMessageBox msgBox;
      msgBox.setText("modifier un ticket.");
      msgBox.setInformativeText("vous etes sur?");
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
      msgBox.setDefaultButton(QMessageBox::Yes);
      int ret = msgBox.exec();
    switch(ret)
    {
    case QMessageBox::Yes:
         tmpticket.modifier(id,idan);
        ui->tabtic->setModel(tmpticket.afficher());
        break;

    }
}

void MainWindow::on_trier_2_clicked()
{
    int x=0;
       if( ui->triticket->isChecked())
           x=1;
       else if( ui->triidant->isChecked())
           x=2;
       if (x!=0)
       ui->tabtic->setModel(tmpticket.trier(x));
       else
       {
           QMessageBox msgBox;
             msgBox.setText("selectionner critere de tri !.");
             msgBox.setInformativeText("retour");
             msgBox.setStandardButtons(QMessageBox::Cancel);
             //msgBox.setDefaultButton(QMessageBox::Yes);
              msgBox.exec();
       }


}

void MainWindow::on_consulterstatan_clicked()
{
    int x=0;
       if( ui->stastat->isChecked())
           x=1;
       else if( ui->datestat->isChecked())
           x=2;
       if (x!=0)
       ui->tabstatan->setModel(tmpannonce.stat(x));
       else
       {
           QMessageBox msgBox;
             msgBox.setText("selectionner critere !.");
             msgBox.setInformativeText("retour");
             msgBox.setStandardButtons(QMessageBox::Cancel);
             //msgBox.setDefaultButton(QMessageBox::Yes);
              msgBox.exec();
       }

}

void MainWindow::on_consulterstattic_clicked()
{
    int x=0;
       if( ui->clientstat->isChecked())
           x=1;
       else if( ui->annoncestat->isChecked())
           x=2;
       if (x!=0)
       ui->tabstattic->setModel(tmpticket.stat(x));
       else
       {
           QMessageBox msgBox;
             msgBox.setText("selectionner critere !.");
             msgBox.setInformativeText("retour");
             msgBox.setStandardButtons(QMessageBox::Cancel);
             //msgBox.setDefaultButton(QMessageBox::Yes);
              msgBox.exec();
       }

}

void MainWindow::on_valdiersup_released()
{
    ui->valdiersup->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_valdiersup_pressed()
{
    son->play();
       ui->valdiersup->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_appliquer_released()
{
      ui->appliquer->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;font: bold 10 px;");
}

void MainWindow::on_appliquer_pressed()
{
    son->play();
       ui->appliquer->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_consulterstatan_released()
{
      ui->consulterstatan->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_consulterstatan_pressed()
{

    son->play();
       ui->consulterstatan->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_4_released()
{
      ui->pushButton_4->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_4_pressed()
{
    son->play();
       ui->pushButton_4->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_trier_released()
{
     ui->trier->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_trier_pressed()
{
    son->play();
       ui->trier->setStyleSheet("background-color: red;font: bold 10 px;"
                                  "border: 2px solid darkgray;border-radius: 10px;");
}

void MainWindow::on_ajoutticket_released()
{
     ui->ajoutticket->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_ajoutticket_pressed()
{
    son->play();
       ui->ajoutticket->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_2_released()
{
     ui->pushButton_2->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_2_pressed()
{
    son->play();
       ui->pushButton_2->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_appliquer_2_released()
{
     ui->appliquer_2->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_appliquer_2_pressed()
{
    son->play();
       ui->appliquer_2->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_trier_2_released()
{ ui->trier_2->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");

}

void MainWindow::on_trier_2_pressed()
{
    son->play();
       ui->trier_2->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_6_released()
{
    ui->pushButton_6->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_pushButton_6_pressed()
{
    son->play();
       ui->pushButton_6->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_consulterstattic_released()
{
    ui->consulterstattic->setStyleSheet("background-color: rgb(0, 0, 255);background-color: rgb(145, 120, 255);border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_consulterstattic_pressed()
{
    son->play();
       ui->consulterstattic->setStyleSheet("background-color: red;"
                                  "border: 2px solid darkgray;border-radius: 10px;font: bold 10 px;");
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
   // QString id = ui->lineEdit_5->text();

   //bool test= tmpannonce.rechercher(id,st);
    ui->tabanre->setModel(tmpannonce.afficherrecherche(arg1));
}

void MainWindow::on_comboBoxmodan_currentIndexChanged(const QString &arg1)
{
   QString id=ui->comboBoxmodan->currentText();
   QSqlQuery query;

   query.prepare("select * from Annonce where ID_a = :id");
   query.bindValue(":id", id);
   if (query.exec())
   {
       while(query.next())
       {
           ui->timeEditmod_2->setTime(query.value(6).toTime());
           ui->datemod_2->setDate(query.value(4).toDate());
           ui->nbplacemod_2->setValue(query.value(5).toInt());
       }
   }
}

void MainWindow::on_taban_activated(const QModelIndex &index)
{

}

void MainWindow::on_taban_2_activated(const QModelIndex &index)
{
    QString id=ui->taban_2->model()->data(index).toString();
    ui->lineEdit_id->setText(id);
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    ui->tabticrec->setModel(tmpticket.afficherrecherche(arg1));
}

void MainWindow::on_tabticsup_activated(const QModelIndex &index)
{
    QString id=ui->tabticsup->model()->data(index).toString();
    ui->lineEdit_idt->setText(id);
}

void MainWindow::on_comboBoxtic_currentIndexChanged(const QString &arg1)
{
    QString id=ui->comboBoxtic->currentText();
    QSqlQuery query;

    query.prepare("select * from ticket where ID_ticket = :id");
    query.bindValue(":id", id);
    if (query.exec())
    {
        while(query.next())
        {
            ui->idanmod_2->setText(query.value(1).toString());
            ui->cinpmod_2->setText(query.value(2).toString());

        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tabticaff->setModel(tmpticket.affectation());
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

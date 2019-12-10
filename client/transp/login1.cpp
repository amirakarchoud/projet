#include "login1.h"
#include "ui_login1.h"
#include "med.h"
#include "rouaa.h"
#include "amira.h"
#include "adhir.h"
#include "nadhir.h"
#include "malek.h"
#include <QMessageBox>
#include <QMediaPlayer>
login1::login1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login1)
{
    ui->setupUi(this);
    this->setWindowTitle("transp");
    mohamed->setMedia(QUrl("C:/Users/myria/Downloads/153017_department64_welcome (online-audio-converter.com).mp3"));//music lien
}

login1::~login1()
{
    delete ui;
}

void login1::on_pushButton_clicked()
{
    QString id=ui->lineEdit->text();
    QString mdp=ui->lineEdit_2->text();
    mohamed->play();

    if(id=="mohamed"&&mdp=="mohamed"){

    med m;
    hide();
    m.exec();}
    else if(id=="roua"&&mdp=="roua"){
        rouaa a;
        hide();
        a.exec();
    }
    else if(id=="amira"&&mdp=="amira"){
        amira a;
        hide();
        a.exec();
    }
    else if(id=="adhir"&&mdp=="adhir"){
        adhir a;
        hide();
        a.exec();
    }
    else if(id=="nadhir"&&mdp=="nadhir"){
        nadhir a;
        hide();
        a.exec();
    }
    else if(id=="malek"&&mdp=="malek"){
        malek a;
        hide();
        a.exec();
    }
    QSqlQuery q;
    if (q.exec("select * from employe where cin='"+id+"' and mdp='"+mdp+"'"))
    {
        int count=0;
        while(q.next())
        {
            count++;
            if(count==1)
            {
                rouaa a;
                hide();
                a.exec();

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("cin ou mot de passe incorrecte"),
                            QObject::tr("cin ou mot de passe incorrecte.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
    }
}

#include "login1.h"
#include "ui_login1.h"
#include "med.h"
#include "rouaa.h"
#include "amira.h"
#include "adhir.h"
#include "nadhir.h"
#include "malek.h"
login1::login1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login1)
{
    ui->setupUi(this);
    this->setWindowTitle("transp");
}

login1::~login1()
{
    delete ui;
}

void login1::on_pushButton_clicked()
{
    QString id=ui->lineEdit->text();
    QString mdp=ui->lineEdit_2->text();
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
}

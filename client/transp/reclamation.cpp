#include "reclamation.h"
#include <QDebug>
reclamation::reclamation()
{
num=0;
objet="";
description="";
lieu="";
datee="";
}
reclamation::reclamation(int num,QString objet,QString description, QString lieu, QString datee)
{
  this->num=num;
  this->objet=objet;
  this->description=description;
  this->lieu=lieu;
  this->datee=datee;
}
int reclamation::get_num(){return num;}
QString reclamation::get_objet(){return  objet;}
QString reclamation::get_description(){return description;}
QString reclamation::get_lieu(){return  lieu;}
QString reclamation::get_datee(){return datee;}

bool reclamation::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);

query.prepare("INSERT INTO reclamation (NUM, OBJET, LIEU, DESCRIPTION, DATEE) "
                    "VALUES (:num, :objet,:lieu, :description,  :datee)");
query.bindValue(":num", res);
query.bindValue(":objet", objet);
query.bindValue(":description", description);
query.bindValue(":lieu", lieu);
query.bindValue(":datee", datee);

return    query.exec();
}

QSqlQueryModel * reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("objet"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee"));

    return model;
}

bool reclamation::supprimer(int numm)
{
    QSqlQuery query;
    QString res= QString::number(numm);

query.prepare("Delete from reclamation where NUM = :num ");
query.bindValue(":num", res);
return    query.exec();
}

bool reclamation::Modifier(int num,QString objet,QString description, QString lieu, QString datee){
    QSqlQuery query;
    QString res= QString::number(num);


    query.prepare("update RECLAMATION set ,OBJET=:objet ,DESCRIPTION=:description,LIEU=:lieu,DATEE=:DATE  where NUM=:num;");
    query.bindValue(":objet", objet);
    query.bindValue(":num", res);
    query.bindValue(":description", description);
    query.bindValue(":datee", datee);
    query.bindValue(":lieu", lieu);
    return query.exec();
}

bool reclamation::rech(int numm)
{
    QSqlQuery query;
    query.prepare("select * from RECLAMATION where NUM = :num;");
    query.bindValue(":num", numm);
    return query.exec();
}
QSqlQueryModel * reclamation::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATION ORDER BY NUM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
        return model;
}



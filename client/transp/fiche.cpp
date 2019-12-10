#include "fiche.h"
#include <QDebug>
#include <QSqlError>
fiche::fiche()
{
ref=0;
etat="";
date="";
}
fiche::fiche(int ref, QString etat,QString date)
{
  this->ref=ref;
  this->etat=etat;
  this->date=date;
}
int fiche::get_ref(){return  ref;}
QString fiche::get_etat(){return etat;}
QString fiche::get_date(){return  date;}

bool fiche::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);

query.prepare("INSERT INTO FICHES_TECHNIQUES (REF, ETAT, DATEE) "
                    "VALUES (:ref, :etat, :date)");
query.bindValue(":ref", res);
query.bindValue(":etat", etat);
query.bindValue(":date", date);
qDebug()<<query.lastError().text();
return    query.exec();
}

QSqlQueryModel * fiche::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FICHES_TECHNIQUES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
qDebug()<<model->lastError().text();
    return model;
}

bool fiche::supprimer(int ref)
{
QSqlQuery query;

query.prepare("Delete from FICHES_TECHNIQUES where REF = :ref ");
query.bindValue(":ref", ref);
return    query.exec();
}
bool fiche::Modifier(int ref,QString etat,QString date){
    QSqlQuery query;
    QString res= QString::number(ref);

    query.prepare("update FICHES_TECHNIQUES set  ETAT=:etat ,DATEE=:date  where REF = :ref;");
    query.bindValue(":ref", res);
    query.bindValue(":etat", etat);
    query.bindValue(":date",date);
    return query.exec();
}

bool fiche::rech(int ref)
{
    QSqlQuery query;
    query.prepare("select * from FICHES_TECHNIQUES where REF = :ref;");
    query.bindValue(":ref", ref);
    return query.exec();
}
QSqlQueryModel * fiche::trier(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FICHES_TECHNIQUES ORDER BY REF");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
        return model;
}


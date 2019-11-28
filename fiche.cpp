/*#include "fiche.h"
#include <QDebug>
fiche::fiche()
{
ref=0;
etat="";
date="";
}
fiche::fiche(int ref,QString etat, QString date)
{
  this->ref=ref;
  this->etat=etat;
  this->date=date;
}
int fiche::get_ref(){return ref;}
QString fiche::get_etat(){return  etat;}
QString fiche::get_date(){return date;}

bool fiche::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);

query.prepare("INSERT INTO fiche (REF, ETAT, DATE) "
                    "VALUES (:ref, :etat, :date)");
query.bindValue(":ref", res);
query.bindValue(":etat", etat);
query.bindValue(":date", date);

return    query.exec();
}

QSqlQueryModel * fiche::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fiche");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));

    return model;
}

bool fiche::supprimer()
{
QSqlQuery query;

query.prepare("Delete from fiche where ref = :ref ");
query.bindValue(":ref", ref);
return    query.exec();
}
bool fiche::Modifier(int reff)
{
    QSqlQuery query;
    query.prepare("update system.fiche set etat = ? where ref = ?");
    query.addBindValue(reff);
    query.addBindValue(ref);

    return query.exec();
}
*/

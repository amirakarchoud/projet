#include "abonnement.h"
#include <QDebug>
Abonnement::Abonnement()
{
cin=0;
date="";
id=0;
}
Abonnement::Abonnement(int cin,int id,QString date)
{
  this->cin=cin;
  this->date=date;
  this->id=id;

}
QString Abonnement::get_date(){return  date;}
int Abonnement::get_cin(){return  cin;}
int Abonnement::get_id(){return  id;}


bool Abonnement::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
QString res2= QString::number(id);



query.prepare("INSERT INTO abonnement (CIN,ID,DATE_EX) "
                    "VALUES (:cin,:id ,:date)");
query.bindValue(":cin", res);
query.bindValue(":date", date);
query.bindValue(":id", id);


return query.exec();
}

QSqlQueryModel * Abonnement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnement a, abonne b where (a.cin=b.cin)");
//afficher
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("profession"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));

    return model;
}

bool Abonnement::supprimer(int cinn)
{
QSqlQuery query;
QString res= QString::number(cinn);
query.prepare("Delete from abonnement where CIN = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool Abonnement::recherche_cin(int)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("select * from abonnement where CIN = :cin;");
    query.bindValue(":cin", res);
    return query.exec();
}
bool Abonnement::modifier(int cin, QString date ,int id)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    QString res1= QString::number(id);

    query.prepare("update abonnement set date_ex=:date_ex, id=:id  where cin =:cin;");

    query.bindValue(":cin", res);
    query.bindValue(":date_ex", date);
    query.bindValue(":id", res1);

    return query.exec();
}

QSqlQueryModel * Abonnement::modelref(){
    QSqlQuery *query = new QSqlQuery;
    QSqlQueryModel *model =new QSqlQueryModel();
    query->prepare("select cin from abonne");
    query->exec();
    model->setQuery(*query);
    return model;
}

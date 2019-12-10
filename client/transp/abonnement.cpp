#include "abonnement.h"
#include <QDebug>
#include <QDate>
Abonnement::Abonnement()
{
cin=0;

id=0;
}
Abonnement::Abonnement(int cin,int id,QDate date)
{
  this->cin=cin;
  this->date=date;
  this->id=id;

}
QDate Abonnement::get_date(){return  date;}
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
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prenom "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Email"));

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
bool Abonnement::modifier(int cin, QDate date ,int id)
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

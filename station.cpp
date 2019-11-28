#include "station.h"
#include <QDebug>
#include <QMessageBox>

station::station()
{
numstation=0;
locstation="";
}
station::station(int numstation,QString locstation)
{
  this->numstation=numstation;
  this->locstation=locstation;
}
int station::get_numstation(){return  numstation;}
QString station::get_locstation(){return locstation;}

bool station::ajouter()
{
QSqlQuery query;
QString res= QString::number(numstation);
query.prepare("INSERT INTO station (numstation,locstation) "
                    "VALUES (:numstation, :locstation)");
query.bindValue(":numstation", res);
query.bindValue(":locstation", locstation);

return    query.exec();
}

QSqlQueryModel * station::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from station");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numstation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("locstation "));
    return model;
}

bool station::supprimer(int numstation)
{
QSqlQuery query;
QString res= QString::number(numstation);
query.prepare("Delete from station where numstation = :numstation ");
query.bindValue(":numstation", res);
return    query.exec();
}
bool station::modifier(int numstation,QString locstation)
{
QSqlQuery query;
QString res= QString::number(numstation);
query.prepare("update station set locstation=:locstation where numstation=:numstation");
query.bindValue(":locstation", locstation);
query.bindValue(":numstation", numstation);

return    query.exec();
}
QSqlQueryModel * station::recherche(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from station where (numstation like '%"+a+"%' or locstation like '%"+a+"%' ) ");
    return    query;
}
QSqlQueryModel * station::trie()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from station order by numstation ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numstation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("locstation "));

    return model;
}
QSqlQueryModel * station::trie2()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from station order by locstation ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numstation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("locstation "));

    return model;
}
double station::stat(QString locstation)
{
    QSqlQuery query;
    query.prepare("select (sum(case when locstation =:locstation then 1 else 0 end )/count(*))*100 as perc from station");
    query.bindValue(":locstation", locstation);
    query.exec();
    query.first();
   return query.value(0).toDouble();
}


bool station::ControleNumeroString(QString chaine)
{
    int i=0;
    while(i<=9)
    {
        QString res=QString::number(i);
        if(chaine.contains(res))
            return false;
        i++;
    }return true;

}
bool station::controleNumber(int n)
{
    if (n>0){
        return true;
    }
    else{ QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("les entiers doivent êtres positifs \n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        return false;}
}

bool station::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from station where numstation=:numstation");
    query.bindValue(":numstation", res);
    query.exec();
    return query.first();
}

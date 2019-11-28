#include "ligne.h"
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
Ligne::Ligne()
{
refligne=0;
distance=0;
statdep="";
statarr="";
}
Ligne::Ligne(int refligne,QString statdep,QString statarr,int distance)
{
  this->refligne=refligne;
  this->statdep=statdep;
  this->statarr=statarr;
  this->distance=distance;
}
int Ligne::get_refligne(){return  refligne;}
QString Ligne::get_statdep(){return statdep;}
QString Ligne::get_statarr(){return statarr;}
int Ligne::get_distance(){return  distance;}

bool Ligne::ajouter()
{
QSqlQuery query;
QString res= QString::number(refligne);
QString res1= QString::number(distance);
query.prepare("INSERT INTO ligne (Refligne, Statdep, Statarr,Distance) "
                    "VALUES (:refligne, :statdep, :statarr,:distance)");
query.bindValue(":refligne", res);
query.bindValue(":statdep", statdep);
query.bindValue(":statarr", statarr);
query.bindValue(":distance", res1);


return    query.exec();
}

QSqlQueryModel * Ligne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ligne");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refligne"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("statdep "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("statarr"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("distance"));
    return model;
}

bool Ligne::supprimer(int refligne)
{
QSqlQuery query;
QString res= QString::number(refligne);
query.prepare("Delete from ligne where refligne = :refligne ");
query.bindValue(":refligne", res);
return    query.exec();
}
bool Ligne::modifier(int refligne,QString statdep,QString statarr,int distance)
{
QSqlQuery query;
QString res= QString::number(refligne);
QString res1= QString::number(distance);
query.prepare("update ligne set STATDEP=:statdep,statarr=:statarr,distance=:distance where REFLIGNE=:refligne");
query.bindValue(":refligne", res);
query.bindValue(":statdep", statdep);
query.bindValue(":statarr", statarr);
query.bindValue(":distance", res1);
return    query.exec();
}
QSqlQueryModel* Ligne::recherche(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from ligne where (refligne like '%"+a+"%' or statdep like '%"+a+"%' or statarr like '%"+a+"%' or distance like '%"+a+"%' ) ");
    return    query;
}
QSqlQueryModel * Ligne::trie(int)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ligne order by refligne");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refligne"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("statdep "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("statarr"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("distance"));
    return model;
}

 bool Ligne::affecter(int refligne,int numstation)
{
    QSqlQuery query;
    QString res= QString::number(refligne);
    QString res2= QString::number(numstation);
    query.prepare("UPDATE station set refligne=:ligne where numstation=:numstation");
    query.bindValue(":ligne", res);
    query.bindValue(":numstation", res2);
    return query.exec();
}
QSqlQueryModel * Ligne::AfficherAffecter()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from station JOIN ligne ON station.refligne = ligne.refligne");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("refligne"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("statdep"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("statarr "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("distance "));


        return model;
}
QString Ligne::min()
{
    QSqlQuery query;
    query.prepare("select min(distance) as perc from ligne");
    query.bindValue(":distance", distance);
    query.exec();
    query.first();
   return query.value(0).toString();
}
QString Ligne::max()
{
    QSqlQuery query;
    query.prepare("select max(distance) as perc from ligne");
    query.bindValue(":distance", distance);
    query.exec();
    query.first();
   return query.value(0).toString();
}
bool Ligne::controleidentique(QString string1,QString string2)
{
    if(QString::compare(string1,string2)==0)
    { QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                            QObject::tr("les champs doivent êtres uniques \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;}
    else
        return true;
}
bool Ligne::ControleNumeroString(QString chaine)
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
bool Ligne::controleNumber(int n)
{
    if (n>0){
        return true;
    }
    else{ QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                QObject::tr("les entiers doivent êtres positifs \n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        return false;}
}
bool Ligne::controleLength(QString val,int max)
{
    if(val.length()<max && !val.isEmpty())
    return true;
    else
   {    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                 QObject::tr("longeur de champs invalide \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    return false;
   }
}
bool Ligne::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from ligne where refligne=:refligne");
    query.bindValue(":refligne", res);
    query.exec();
    return query.first();
}
void Ligne::sounderreur()
{
   QMediaPlayer * music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/foghi.mp3"));
   music->play();
}
void Ligne::soundcorrect()
{
   QMediaPlayer * music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/Correct Answerldea Sound Effects.mp3"));
   music->play();
}

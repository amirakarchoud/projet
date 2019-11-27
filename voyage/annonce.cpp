#include "annonce.h"
#include <QDate>
#include "mainwindow.h"
#include <QTime>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
Annonce::Annonce()
{
     id_a="-";
         nb_pl=0;

}

Annonce::Annonce(QString id, QDate date,QTime temps,int nums,int numa,int x,int numv)
{
    id_a=id;
    dated=date;this->temps=temps;
        nb_pl=x;

        st_dep=nums;
        st_a=numa;
        vehicule=numv;

}
int Annonce::getV()
{
    return vehicule;
}
QString Annonce::getId(){return id_a;}
int Annonce::getStdep(){return st_dep;}
int Annonce::getSta(){return st_a;}
QDate Annonce::getDate(){return dated;}
int Annonce::getNbpl(){return nb_pl;}
QTime Annonce::getT(){return temps;}

 bool Annonce::ajouter()
 {
     QSqlQuery query;

     QString nbr= QString::number(nb_pl);
     query.prepare("INSERT INTO Annonce (ID_a, dated,temps,st_dep,st_ar,vehicule,nb_pl) "
                         "VALUES (:id, :date, :temps,:stdept,:star,:ve,:nbr)");
     query.bindValue(":id", id_a);
     query.bindValue(":date", dated);
     query.bindValue(":temps", temps);
     query.bindValue(":stdept", st_dep);//a changer en int ,a declarer juste ici?
     query.bindValue(":star", st_a);//meme
     query.bindValue(":ve", vehicule);//meme

     query.bindValue(":nbr", nb_pl);


     return    query.exec();
 }

 QSqlQueryModel * Annonce::afficher()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from Annonce");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("vehicule"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("station dep"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("station arrivee"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date "));

     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre de place"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("temps"));

         return model;

 }

 bool Annonce::supprimer(QString idd)
 {
     QSqlQuery query;
     //QString res= QString::number();
     query.prepare("Delete from Annonce where ID_a = :idd ");
     query.bindValue(":idd", idd);
     return    query.exec();



 }



 bool Annonce::rechercher(QString idd, int st)
 {
     QSqlQuery query;
     QString res= QString::number(st);
     query.prepare("select * from Annonce where ID_a like '%:idd%' ");
     query.bindValue(":idd", idd);
     query.bindValue(":st", res);

     return    query.exec();

 }


 QSqlQueryModel * Annonce::afficherrecherche(QString idd)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
    // QSqlQuery query;
    // QString res= QString::number(st);
     model->setQuery("select * from Annonce where ID_a like '%"+idd+"%' ");
     //model->query().bindValue(":idd",idd);
     //query.bindValue(":idd", idd);
    // query.bindValue(":st", res);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("vehicule"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("station dep"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("station arrivee"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date "));

     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre de place"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("temps"));
 //model->query().exec();
         return model;

 }




 bool Annonce::modifier(QString id ,QTime t ,QDate d,int nbrp)
 {
     QSqlQuery query;
     QString nbr= QString::number(nbrp);
     query.prepare("update Annonce set temps = :t,dated=:d,nb_pl = :nbrp where ID_a = :id");
     query.bindValue(":id", id);
     query.bindValue(":t", t);
     query.bindValue(":nbrp", nbr);
     query.bindValue(":d", d);


     return query.exec();
 }


 QSqlQueryModel * Annonce::trier(int x)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     if (x==1)
     model->setQuery("select * from Annonce ORDER BY ID_a");
     else if (x==2)
          model->setQuery("select * from Annonce ORDER BY dated");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("vehicule"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("station dep"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("station arrivee"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date "));

     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre de place"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("temps"));

         return model;
 }



 QSqlQueryModel * Annonce::stat(int x)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     if (x==1)
    { model->setQuery("select st_ar,count(id_a)*100/(select count (*) from annonce) from annonce group by st_ar ;");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num station d'arrivee"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));

     }
         else if (x==2)
          {model->setQuery("select dated,count(id_a)*100/(select count (*) from annonce) from annonce group by dated ;");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("date du voyage"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
}

         return model;
 }




#include "panne.h"
#include <QDebug>
#include <QString>
panne::panne()
{
idvehicule=0;

chauvehicule=0;
typepanne="";

}
panne::panne(int idvehicule, int chauvehicule  ,QString typepanne)
{
  this->idvehicule=idvehicule;

    this->chauvehicule=chauvehicule;
  this->typepanne=typepanne;

}
QString panne::get_typepanne(){return  typepanne;}

int panne::get_idvehicule(){return  idvehicule;}

int panne::get_chauvehicule(){return  chauvehicule;}

bool panne::ajouter()
{
QSqlQuery query;
QString res11= QString::number(idvehicule);
QString res22= QString::number(chauvehicule);

query.prepare("INSERT INTO panne (ID_VEHICULE, CIN_CHAUFFEUR ,TYPE_PANNE) "
                    "VALUES (:idvehicule,  :chauvehicule, :typepanne)");
query.bindValue(":idvehicule", res11);
query.bindValue(":chauvehicule", res22);


query.bindValue(":typepanne", typepanne);

return    query.exec();
}

bool panne::supprimer(int idvehicule)
{
QSqlQuery query;
QString res11= QString::number(idvehicule);
query.prepare("Delete from panne where ID_VEHICULE = :idvehicule ");
query.bindValue(":idvehicule", res11);
return    query.exec();
}
QSqlQueryModel * panne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from panne");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDVEHICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CHAUVEHICULE "));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPEPANNE"));
    return model;
}
bool panne::modifier(int idvehicule ,QString typepanne)
{
    QSqlQuery query;
    QString res= QString::number(idvehicule);
    query.prepare("update panne set idvehicule = :c where typepanne = :i");
    query.bindValue(":i", typepanne);
    query.bindValue(":c", res);



    return query.exec();
}

QSqlQueryModel *panne::cherch_type_panne(QString typepanne)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_VEHICULE, CIN_CHAUFFEUR, TYPE_PANNE from PANNE where TYPE_PANNE='"+typepanne+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idvehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("chauvehicule"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("typevehicule"));



    return model;
}
QSqlQueryModel * panne::afficher_tri_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from panne order by ID_VEHICULE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idvehicule"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("chauvehicule"));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("typepanne"));


    return model;
}
QSqlQueryModel * panne::afficher_tri_type_panne()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from panne order by TYPE_PANNE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idvehicule"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("chauvehicule"));

model->setHeaderData(3, Qt::Horizontal, QObject::tr("typepanne"));



    return model;
}



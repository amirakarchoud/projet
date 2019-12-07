#include "vehicule.h"
#include <QDebug>
#include <QString>
vehicule::vehicule()
{
id=0;
con=0;
chau=0;
type="";

}
vehicule::vehicule(int id, int con , int chau,QString type)
{
  this->id=id;
    this->con=con;
    this->chau=chau;
  this->type=type;

}
QString vehicule::get_type(){return  type;}

int vehicule::get_id(){return  id;}
int vehicule::get_con(){return  con;}
int vehicule::get_chau(){return  chau;}

bool vehicule::ajouter()
{
QSqlQuery query;
QString res1= QString::number(id);
QString res2= QString::number(con);
QString res3= QString::number(chau);
query.prepare("INSERT INTO vehicule (ID, CON, CHAU ,TYPE) "
                    "VALUES (:id, :con, :chau, :type)");
query.bindValue(":id", res1);
query.bindValue(":con", res2);
query.bindValue(":chau", res3);

query.bindValue(":type", type);

return    query.exec();
}

bool vehicule::supprimer(int id)
{
QSqlQuery query;
QString res1= QString::number(id);
query.prepare("Delete from vehicule where ID = :id ");
query.bindValue(":id", res1);
return    query.exec();
}
QSqlQueryModel * vehicule::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from vehicule");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CHAU "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CON"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

//recherche w modifier .cpp w tenesech t3aytelhom fil .h





 bool vehicule::modifier(int id ,int chau)
 {
     QSqlQuery query;
     QString res= QString::number(id);
     query.prepare("update vehicule set chau = :c where id = :i");
     query.bindValue(":c", chau);
     query.bindValue(":i", res);



     return query.exec();
 }


 QSqlQueryModel *vehicule::cherch_type(QString type)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select ID, CHAU, CON, TYPE from VEHICULE where TYPE='"+type+"'");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("chau"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("con"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));



     return model;
 }
 QSqlQueryModel * vehicule::afficher_tri_chau()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from vehicule order by CHAU");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("chau"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("con "));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


     return model;
 }
 QSqlQueryModel * vehicule::afficher_tri_type()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from vehicule order by TYPE");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("chau"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("con "));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));



     return model;
 }




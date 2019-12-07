#include "conge.h"

#include <QDebug>
Conge::Conge
()
{

type="";
id_conge=0;
cin=0;

}
Conge::Conge (QString type,int id_conge,int cin)
{


  this->type=type;
  this->id_conge=id_conge;
   this->cin=cin;


}

QString Conge::get_type(){return type;}
int Conge::get_id_conge(){return  id_conge;}
int Conge::get_cin(){return  cin;}

bool Conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_conge);
QString res1= QString::number(cin);
query.prepare("INSERT INTO conge( TYPE,ID_CONGE,CIN) "
                    "VALUES (  :type, :id_conge, :cin)");


query.bindValue(":type", type);
query.bindValue(":id_conge", res);
query.bindValue(":cin", res1);

return    query.exec();
}

QSqlQueryModel * Conge::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from conge");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Id_conge"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));
    return model;
}

bool Conge::supprimer(int id_conge)
{
    QSqlQuery query;
    QString res= QString::number(id_conge);
    query.prepare("Delete from conge where ID_CONGE = :id_conge ");
    query.bindValue(":id_conge", res);
    return    query.exec();
}
bool Conge::modifier(QString type,int id_conge)
 {
     QSqlQuery query;
     QString res= QString::number(id_conge);
     query.prepare("update conge set type = :t where ID_CONGE = :id_conge");
     query.bindValue(":t", type);
     query.bindValue(":id_conge", res);


     return query.exec();
 }
QSqlQueryModel *Conge::rechercher(QString type)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from Conge where TYPE LIKE '"+type+"%'");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("type "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_conge"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));



     return model;
 }




QSqlQueryModel *Conge::trier(bool ph,bool croissant)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString tr;
    tr="SELECT * FROM conge ORDER BY ";
    if (ph)
        tr+="ID_CONGE";
    else
        tr+="TYPE";
    if (!croissant)
        tr+=" DESC";
    model->setQuery(tr);
    return model;
}



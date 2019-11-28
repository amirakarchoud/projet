#include "conge.h"

#include <QDebug>
Conge::Conge
()
{
nom="";
prenom="";
type="";
id_conge=0;

}
Conge::Conge (QString nom,QString prenom,QString type,int id_conge)
{

  this->nom=nom;
  this->prenom=prenom;
  this->type=type;
  this->id_conge=id_conge;


}
QString Conge::get_nom(){return  nom;}
QString Conge::get_prenom(){return prenom;}
QString Conge::get_type(){return type;}
int Conge::get_id_conge(){return  id_conge;}

bool Conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_conge);
query.prepare("INSERT INTO conge( NOM, PRENOM,TYPE,ID_CONGE) "
                    "VALUES ( :nom, :prenom, :type, :id_conge)");

query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":type", type);
query.bindValue(":id_conge", res);

return    query.exec();
}

QSqlQueryModel * Conge::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from conge");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Id_conge"));
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

model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_conge"));



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



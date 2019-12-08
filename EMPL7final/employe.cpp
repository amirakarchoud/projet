#include "employe.h"
#include <QDebug>
Employe::Employe
()
{
nom="";
prenom="";
grade="";
cin=0;
}
Employe::Employe (QString nom,QString prenom,QString grade,int cin)
{

  this->nom=nom;
  this->prenom=prenom;
  this->grade=grade;
  this->cin=cin;
}
QString Employe::get_nom(){return  nom;}
QString Employe::get_prenom(){return prenom;}
QString Employe::get_grade(){return grade;}
int Employe::get_cin(){return  cin;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("INSERT INTO employe ( NOM, PRENOM,GRADE,CIN) "
                    "VALUES ( :nom, :prenom, :grade, :cin)");

query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":grade", grade);
query.bindValue(":cin", res);

return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Grade"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Cin"));
    return model;
}

bool Employe::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from employe where CIN = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}
bool Employe::modifier(QString grade,int cin)
 {
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("update employe set grade = :g where CIN = :cin");
    query.bindValue(":cin", res);
    query.bindValue(":g", grade);

    return query.exec();
 }



QSqlQueryModel *Employe::rechercher(QString grade)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from Employe where GRADE LIKE '"+grade+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));



     return model;
 }

QSqlQueryModel *Employe::trier(bool ph,bool croissant)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString tr;
    tr="SELECT * FROM employe ORDER BY ";
    if (ph)
        tr+="CIN";
    else
        tr+="GRADE";
    if (!croissant)
        tr+=" DESC";
    model->setQuery(tr);
    return model;
}

#include "abonne.h"
#include <QDebug>
Abonne::Abonne()
{
cin=0;
numero=0;
nom="";
prenom="";
adresse="";
profession="";
email="";
}
Abonne::Abonne(int cin,QString nom,QString prenom,int numero,QString adresse,QString profession,QString email)
{
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->numero=numero;
  this->adresse=adresse;
  this->profession=profession;
  this->email=email;

}
QString Abonne::get_nom(){return  nom;}
void Abonne::set_nom(QString nom)
{
    this->nom=nom;
}

QString Abonne::get_prenom(){return prenom;}
void Abonne::set_prenom(QString prenom)
{
    this->prenom=prenom;
}
int Abonne::get_cin(){return  cin;}
void Abonne::set_cin(int cin)
{
    this->cin=cin;
}
int Abonne::get_numero(){return  numero;}
void Abonne::set_numero(int numero)
{
    this->numero=numero;
}
QString Abonne::get_adresse(){return adresse;}
void Abonne::set_adresse(QString adresse)
{
    this->adresse=adresse;
}
QString Abonne::get_profession(){return profession;}
void Abonne::set_profession(QString profession)
{
    this->profession=profession;
}
QString Abonne::get_email(){return email;}
void Abonne::set_email(QString email)
{
    this->email=email;
}





bool Abonne::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
QString res1= QString::number(numero);


query.prepare("INSERT INTO abonne (CIN, NOM, PRENOM, NUMERO, ADRESSE, SEXE ,EMAIL) "
                    "VALUES (:cin, :nom, :prenom, :numero, :adresse, :profession ,:email)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":numero", res1);
query.bindValue(":adresse", adresse);
query.bindValue(":profession", profession);
query.bindValue(":email", email);

return query.exec();
}

QSqlQueryModel * Abonne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonne");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}

bool Abonne::supprimer(int cinn)
{
    QSqlQuery query;
    QString res= QString::number(cinn);
    query.prepare("Delete from abonne where CIN = :cin ");
    query.bindValue(":cin", res);
    return query.exec();
}

bool Abonne::recherche_cin(int cin)
 {
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("select * from abonne where CIN = :cin;");
    query.bindValue(":cin", res);
    return query.exec();
}

bool Abonne::modifier(int cin, int numero,QString adresse, QString email)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    QString res1= QString::number(numero);
    query.prepare("update abonne set numero=:numero ,adresse=:adresse ,email=:email  where cin =:cin;");


    query.bindValue(":cin", res);
    query.bindValue(":numero", res1);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);

    return query.exec();
}

//pour rechercher par nom (verifier)


QSqlQueryModel *Abonne::cherch_nom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
   // model->setQuery("select * from ABONNE where NOM like :nom");
/*
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Profession"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email")); */
    QSqlQuery * query = new QSqlQuery();
    query->prepare("select * from abonne where nom like :nom");
    nom = '%'+nom+'%';
    query->bindValue(":nom",nom);
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel * Abonne::afficher_tri_cin()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonne order by CIN");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("profession"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel * Abonne::afficher_tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonne order by NOM");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("profession"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

    return model;
}




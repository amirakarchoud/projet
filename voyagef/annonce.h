#ifndef ANNONCE_H
#define ANNONCE_H
#include <QDate>
#include <QTime>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Annonce
{ QString id_a;
    int vehicule;
    int st_dep,st_a;
    QDate dated;

    int nb_pl;
    QTime temps;
public:
    Annonce();
    Annonce(QString id, QDate date,QTime temps,int nums,int numa,int nbr,int numv);
    int getV();
    int getStdep();
    int getSta();
    QString getId();
     QDate getDate();
     int getNbpl();
     QTime getT();
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(QString);
     bool rechercher(QString idd,int st);
      QSqlQueryModel * afficherrecherche(QString idd);
     bool modifier(QString id ,QTime t,QDate d,int nbrp );
      QSqlQueryModel * trier(int x);
      QSqlQueryModel * stat(int x);

    ~Annonce(){}

};

#endif // ANNONCE_H

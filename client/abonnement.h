#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class Abonnement
{public:
    Abonnement();
    Abonnement(int,int,QDate);
    QDate get_date();
    int get_cin();
    int get_id();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche_cin(int);
    bool modifier(int,QDate,int);
    QSqlQueryModel * modelref();
private:
    QDate date;
    int cin,id;
};

#endif // ABONNEMENT_H

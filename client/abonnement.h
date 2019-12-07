#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Abonnement
{public:
    Abonnement();
    Abonnement(int,int,QString);
    QString get_date();
    int get_cin();
    int get_id();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche_cin(int);
    bool modifier(int,QString,int);
    QSqlQueryModel * modelref();
private:
    QString date;
    int cin,id;
};

#endif // ABONNEMENT_H

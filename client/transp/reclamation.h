#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reclamation
{public:
    reclamation();
    reclamation(int,QString,QString ,QString,QString);
    QString get_objet();
    QString get_description();
    QString get_lieu();
    int get_num();
    QString get_datee();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Modifier(int,QString,QString ,QString,QString);
    bool rech(int);
    QSqlQueryModel * trier();
private:
    QString objet;
    QString description;
    QString lieu;
    int num;
    QString datee;

};

#endif // RECLAMATION_H

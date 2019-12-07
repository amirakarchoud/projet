#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Conge
{public:
    Conge();
    Conge(QString,int,int);
    QString get_type();
    int get_id_conge();
    int get_cin();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (QString,int);
    QSqlQueryModel * rechercher(QString);
     QSqlQueryModel * trier(bool ph,bool croissant);

private:
    QString type;
    int id_conge,cin;

};

#endif // CONGE_H

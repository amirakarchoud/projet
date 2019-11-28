#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Conge
{public:
    Conge();
    Conge(QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_type();
    int get_id_conge();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (QString,int);
    QSqlQueryModel * rechercher(QString);
     QSqlQueryModel * trier(bool ph,bool croissant);

private:
    QString nom,prenom,type;
    int id_conge;

};

#endif // CONGE_H

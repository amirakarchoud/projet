#ifndef PANNE_H
#define PANNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class panne
{public:
    panne();
    panne(int,int,QString);
    QString get_typepanne();

    int get_idvehicule();
    int get_chauvehicule();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int , QString  );
    QSqlQueryModel * cherch_type_panne(QString);
    QSqlQueryModel * afficher_tri_id();
       QSqlQueryModel * afficher_tri_type_panne();
private:

    int idvehicule;
     int chauvehicule;

      QString typepanne;
};
#endif // PANNE_H

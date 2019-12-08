#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{public:
    Employe();
    Employe(QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_grade();
    int get_cin();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (QString,int);
     QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier(bool ph,bool croissant);
private:
    QString nom,prenom,grade;
    int cin;
};

#endif // EMPLOYE_H

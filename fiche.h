/*#ifndef FICHE_H
#define FICHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fiche
{public:
    fiche();
    fiche(int,QString,QString);
    int get_ref();
    QString get_etat();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer();
    bool Modifier(int);
private:
    int ref;
    QString etat;
    QString date;

};
#endif // FICHE_H
*/

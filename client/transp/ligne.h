#ifndef LIGNE_H
#define LIGNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Ligne
{public:
    Ligne();
    Ligne(int,QString,QString,int);
    int get_refligne();
    QString get_statdep();
    QString get_statarr();
    int get_distance();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel * trie(int);
    QString max();
    QString min();
    bool affecter(int ,int );
    QSqlQueryModel * AfficherAffecter();

    bool controleidentique(QString ,QString);
    bool ControleNumeroString(QString);
    bool controleNumber(int );
    bool controleLength(QString ,int);
    bool recherche(int );
    void soundcorrect();
    void sounderreur();







private:
    QString statdep,statarr;
    int refligne,distance;
};

#endif // LIGNE_H

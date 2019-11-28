#ifndef STATION_H
#define STATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class station
{public:
    station();
    station(int,QString);
    int get_numstation();
    QString get_locstation();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString);
    QSqlQueryModel * trie();
    QSqlQueryModel * trie2();
    QSqlQueryModel* recherche(QString);
    double stat(QString locstation);


    bool ControleNumeroString(QString);
    bool controleNumber(int );
    bool recherche(int );





private:
    QString locstation;
    int numstation;
};

#endif // STATION_H

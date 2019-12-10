#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMediaPlayer>


class Abonne
{public:
    Abonne();
    Abonne(int,QString,QString,int,QString,QString,QString);

    QString get_nom();
    void set_nom(QString);

    QString get_prenom();
    void set_prenom(QString);

    int get_cin();
    void set_cin(int);

    int get_numero();
    void set_numero(int);

    QString get_adresse();
    void set_adresse(QString);

    QString get_profession();
    void set_profession(QString);

    QString get_email();
    void set_email(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_tri_cin();
    QSqlQueryModel * afficher_tri_nom();


    bool supprimer(int);
    bool recherche_cin(int);
    bool modifier(int,int,QString,QString);

    //pour recherche (pas verifier)

    QSqlQueryModel * cherch_cin(int);
    QSqlQueryModel * cherch_nom(QString);


private:
    QString nom,prenom,adresse,profession,email;
    int cin,numero;
};

#endif // ETUDIANT_H

#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class vehicule
{public:
    vehicule();
    vehicule(int,int,int,QString);
    QString get_type();

    int get_id();
    int get_chau();
    int get_con();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

   bool modifier(int , int  );
       QSqlQueryModel * cherch_type(QString);
       QSqlQueryModel * afficher_tri_chau();
          QSqlQueryModel * afficher_tri_type();

private:

    int id;
     int chau;
      int con;
      QString type;
};
#endif // VEHICULE_H

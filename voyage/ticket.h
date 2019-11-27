#ifndef TICKET_H
#define TICKET_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include "annonce.h"

class Ticket
{   QString id_ticket,idannonce;
    long Cin_client;//ou type client et type annonce;
public:
    Ticket();
    Ticket(QString,QString,long);

    QString getId();
    QString getIdan();
    long getCin();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool rechercher(QString idt);
     QSqlQueryModel * afficherrecherche(QString idd);
    bool modifier(QString idt ,QString idan );
     QSqlQueryModel * trier(int x);
QSqlQueryModel * stat(int x);
QSqlQueryModel * affectation();

    ~Ticket(){}

};

#endif // TICKET_H

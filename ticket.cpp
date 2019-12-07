#include "ticket.h"
#include <QDebug>
#include "annonce.h"
#include <QDate>
#include <QTime>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
Ticket::Ticket()
{
 id_ticket="-";idannonce="_";Cin_client=00;
}


Ticket::Ticket(QString a,QString b,long c)
{
    id_ticket=a;idannonce=b;Cin_client=c;
}

QString Ticket::getId(){return id_ticket;}
QString Ticket::getIdan(){return idannonce;}
long Ticket::getCin(){return Cin_client;}






bool Ticket::ajouter()
{
QSqlQuery query;
QString res2= QString::number(Cin_client);
query.prepare("INSERT INTO ticket (ID_ticket,idannonce,cin_client) "
                    "VALUES (:id, :idan, :Cin)");
query.bindValue(":id", id_ticket);
query.bindValue(":idan", idannonce);
query.bindValue(":Cin", res2);

return    query.exec();
}

QSqlQueryModel * Ticket::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ticket");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("idannonce "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin client"));
    return model;
}

bool Ticket::supprimer(QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);

query.prepare("Delete from ticket where ID_ticket =:idd ");
query.bindValue(":idd", idd);

return    query.exec();
}

bool Ticket::modifier(QString idt ,QString idan)
 {
     QSqlQuery query;

     query.prepare("update ticket set idannonce = :idan where ID_ticket = :idt");
     query.bindValue(":idt", idt);
     query.bindValue(":idan", idan);


     return query.exec();
 }

QSqlQueryModel * Ticket::trier(int x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if (x==1)
    model->setQuery("select * from ticket ORDER BY ID_ticket");
    else if (x==2)
         model->setQuery("select * from ticket ORDER BY idannonce");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idannonce "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin client"));
        return model;
}





QSqlQueryModel * Ticket::stat(int x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if (x==1)
   { model->setQuery("select cin_client,count(id_ticket)*100/(select count (*) from ticket) from ticket group by cin_client ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin client"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage d'achat des tickets"));

    }
        else if (x==2)
         {model->setQuery("select idannonce,count(id_ticket)*100/(select count (*) from ticket) from ticket group by idannonce ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id annonce"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
}

        return model;
}



QSqlQueryModel * Ticket::afficherrecherche(QString idd)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from ticket where ID_ticket like '%"+idd+"%' ");
    //model->query().bindValue(":idd",idd);
    //query.bindValue(":idd", idd);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idannonce "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin client"));
//model->query().exec();
        return model;

}



QSqlQueryModel * Ticket::affectation()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from ticket t INNER JOIN annonce a on(t.idannonce=a.id_a) ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID ticket"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id annonce "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID annonce"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("vehicule"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("station dep"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("station arrivee"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("date "));

    model->setHeaderData(8, Qt::Horizontal, QObject::tr("nombre de place"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("temps"));

//model->query().exec();
        return model;

}

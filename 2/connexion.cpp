#include "connexion.h"
#include <QSqlError>
Connexion::Connexion(){ db = QSqlDatabase::addDatabase("QODBC");
                        db.setDatabaseName("test");
                        db.setUserName("malek");//inserer nom de l'utilisateur
                        db.setPassword("mlkhm29");//inserer mot de passe de cet utilisateur
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;


if (db.open())
    test=true;


return  test;
}
void Connexion::fermerConnexion()
{db.close();}

#ifndef malek_H
#define malek_H
#include "reclamation.h"
#include "fiche.h"
#include <QDialog>
#include <QPropertyAnimation>

namespace Ui {
class malek;
}

class malek : public QDialog
{
    Q_OBJECT

public:
    explicit malek(QWidget *parent = nullptr);
    ~malek();

private slots:
    void on_pb_ajouter_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pb_supprimer_clicked();
    void on_pushButton_9_clicked();
    void on_trierfournisseur_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();


private:
    Ui::malek *ui;
    QPropertyAnimation *animation;
    reclamation tmpr;
    fiche tmpc;
};

#endif // malek_H

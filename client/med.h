#ifndef med_H
#define med_H

#include <QDialog>
#include "abonne.h"
#include "abonnement.h"
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class med; }
QT_END_NAMESPACE

class med : public QDialog
{
    Q_OBJECT

public:
    med(QWidget *parent = nullptr);
    ~med();
    QMediaPlayer * correct=new QMediaPlayer();
    QMediaPlayer * incorrect=new QMediaPlayer();



private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_modif_client_clicked();

    void on_pb_modif_clicked();


    void on_pushButton_clicked();

    void on_tri_cin_clicked();

    void on_lineEdit_nom_textEdited(const QString &arg1);

    void on_pb_modif_abonnemnt_clicked();

    void on_tri_nom_clicked();

//email

    void sendMail();
    void mailSent(QString);


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_statistique_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_recherche_nom_textChanged(const QString &arg1);

private:
    Ui::med *ui;

    Abonne tmpabonne;
    Abonnement tmpabonnement;
    QString sexe;


};
#endif // med_H

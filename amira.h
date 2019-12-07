#ifndef amira_H
#define amira_H
#include "annonce.h"
#include "ticket.h"
#include "smtp.h"
#include <QDialog>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class amira; }
QT_END_NAMESPACE

class amira : public QDialog
{
    Q_OBJECT

public:
    amira(QWidget *parent = nullptr);
    ~amira();

private slots:
    void sendMail();
    void mailSent(QString);
    void on_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_valdiersup_clicked();

    void on_ajoutticket_clicked();

    void on_appliquer_clicked();

    void on_pushButton_4_clicked();

    void on_trier_clicked();

    void on_ajouter_pressed();

    void on_ajouter_released();

    void on_appliquer_2_clicked();

    void on_trier_2_clicked();

    void on_consulterstatan_clicked();

    void on_consulterstattic_clicked();

    void on_valdiersup_released();

    void on_valdiersup_pressed();

    void on_appliquer_released();

    void on_appliquer_pressed();

    void on_consulterstatan_released();

    void on_consulterstatan_pressed();

    void on_pushButton_4_released();

    void on_pushButton_4_pressed();

    void on_trier_released();

    void on_trier_pressed();

    void on_ajoutticket_released();

    void on_ajoutticket_pressed();

    void on_pushButton_2_released();

    void on_pushButton_2_pressed();

    void on_appliquer_2_released();

    void on_appliquer_2_pressed();

    void on_trier_2_released();

    void on_trier_2_pressed();

    void on_pushButton_6_released();

    void on_pushButton_6_pressed();

    void on_consulterstattic_released();

    void on_consulterstattic_pressed();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_comboBoxmodan_currentIndexChanged(const QString &arg1);

    void on_taban_activated(const QModelIndex &index);

    void on_taban_2_activated(const QModelIndex &index);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_tabticsup_activated(const QModelIndex &index);

    void on_comboBoxtic_currentIndexChanged(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::amira *ui;
    Annonce tmpannonce;
    Ticket tmpticket;
     QSound *son;
};
#endif // amira_H

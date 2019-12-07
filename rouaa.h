#ifndef rouaa_H
#define rouaa_H
#include "employe.h"
#include "conge.h"
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class rouaa; }
QT_END_NAMESPACE

class rouaa : public QDialog
{
    Q_OBJECT

public:
    rouaa(QWidget *parent = nullptr);
    ~rouaa();

private slots:
    void on_pb_ajouter_5_clicked();

    void on_pb_ajouter_6_clicked();

    void on_pb_ajouter_7_clicked();



    void on_ajoute_cong_clicked();

    void on_ajoute_cong_2_clicked();

    void on_pb_ajouter_8_clicked();

    void on_pb_ajouter_9_clicked();

    void on_ajoute_cong_3_clicked();

    void on_pb_ajouter_10_clicked();

    void on_pb_ajouter_11_clicked();

    void on_radioButton_23_clicked();

    void on_radioButton_23_toggled(bool checked);

    void on_radioButton_24_toggled(bool checked);

    void on_radioButton_27_toggled(bool checked);

    void on_groupBox_5_toggled(bool arg1);

    void on_radioButton_28_toggled(bool checked);

    void on_radioButton_25_toggled(bool checked);

    void sendMail();
    void mailSent(QString);

private:
    Ui::rouaa *ui;
    Employe tmpemploye;

    Conge  tmpconge;

};
#endif // rouaa_H

#ifndef adhir_H
#define adhir_H

#include <QDialog>
#include "vehicule.h"
#include "panne.h"
#include "smtp.h"
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class adhir; }
QT_END_NAMESPACE

class adhir : public QDialog
{
    Q_OBJECT

public:
    adhir(QWidget *parent = nullptr);
    ~adhir();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void sendMail();
    void mailSent(QString);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::adhir *ui;
     vehicule tmpvehicule;
     panne tmppanne;
};
#endif // adhir_H

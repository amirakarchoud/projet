#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "conge.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
    Employe tmpemploye;

    Conge  tmpconge;

};
#endif // MAINWINDOW_H

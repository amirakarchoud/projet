#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abonne.h"
#include "abonnement.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_modif_client_clicked();

    void on_pb_modif_clicked();

    void on_pushButton_recherche_nom_clicked();

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

private:
    Ui::MainWindow *ui;

    Abonne tmpabonne;
    Abonnement tmpabonnement;
    QString sexe;


};
#endif // MAINWINDOW_H

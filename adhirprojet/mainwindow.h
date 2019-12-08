#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "vehicule.h"
#include "panne.h"
#include "smtp.h"
#include <QString>

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
    void on_ajouter_vehicule_clicked();

    void on_supprimer_vehicule_clicked();

    void on_modifier_vehicule_clicked();

    void on_chercher_vehicule_clicked();

    void on_trier1_vehicule_clicked();

    void on_trier2_vehicule_clicked();

    void on_ajouter_vehicule_2_clicked();

    void on_supprimer_panne_clicked();

    void on_modifier_panne_clicked();

    void on_chercher_panne_clicked();

    void on_trier_panne1_clicked();

    void on_trier_panne2_clicked();
    void sendMail();
    void mailSent(QString);

private:
    Ui::MainWindow *ui;
    vehicule tmpvehicule;
    panne tmppanne;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "annonce.h"
#include "ticket.h"
#include "stmp.h"
#include <QMainWindow>
#include <QSound>

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
    Ui::MainWindow *ui;
    Annonce tmpannonce;
    Ticket tmpticket;
     QSound *son;
};
#endif // MAINWINDOW_H

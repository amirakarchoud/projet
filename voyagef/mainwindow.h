#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "annonce.h"
#include "ticket.h"

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
    void on_ajouterannonce_clicked();

    void on_valdiersupannonce_clicked();

    void on_ajoutticket_clicked();

    void on_supprimerticket_clicked();

    void on_appliquerannonce_clicked();

    void on_appliquer_2ticket_clicked();

    void on_consulterstatan_clicked();

    void on_consulterstattic_clicked();

    void on_comboBoxmodan_currentIndexChanged(const QString &arg1);

    void on_taban_2_activated(const QModelIndex &index);

    void on_rechercheticketle_textChanged(const QString &arg1);

    void on_rechercheannonce_textChanged(const QString &arg1);

    void on_tabticsup_activated(const QModelIndex &index);

    void on_comboBoxtic_currentIndexChanged(const QString &arg1);

    void on_affectationticket_clicked();

    void on_trierannonce_clicked();

    void on_trier_2ticket_clicked();

private:
    Ui::MainWindow *ui;
    Annonce tmpannonce;
    Ticket tmpticket;
     QSound *son;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ligne.h"
#include "station.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_trie_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_recherche2_clicked();

    void on_pb_modifier__clicked();

    void on_pushButton_statistique_clicked();

    void on_pushButton_clicked();

    void on_locstation_clicked();

    void on_numstation_clicked();

private:
    Ui::MainWindow *ui;
    Ligne tmpLigne;
    station tmpstation;
};

#endif // MAINWINDOW_H

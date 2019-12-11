#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include "fiche.h"
#include <QMainWindow>
#include <QPropertyAnimation>

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
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pb_supprimer_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();


    void on_trier_clicked();

    void on_trie_clicked();

    void on_actualiser_clicked();




    void on_act_clicked();

    void on_rechercher_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    reclamation tmpr;
    fiche tmpc;
};

#endif // MAINWINDOW_H

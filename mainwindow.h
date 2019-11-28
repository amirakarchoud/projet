#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include "fiche.h"
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

    void on_pb_ajouterf_clicked();

    void on_pb_supprimer2_clicked();

private:
    Ui::MainWindow *ui;
    reclamation tmpreclamation;
    //fiche tmpfiche;
};

#endif // MAINWINDOW_H

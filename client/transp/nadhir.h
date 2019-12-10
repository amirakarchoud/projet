#ifndef nadhir_H
#define nadhir_H
#include "ligne.h"
#include "station.h"
#include <QDialog>

namespace Ui {
class nadhir;
}

class nadhir : public QDialog
{
    Q_OBJECT

public:
    explicit nadhir(QWidget *parent = nullptr);
    ~nadhir();

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

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::nadhir *ui;
    Ligne tmpLigne;
    station tmpstation;
};

#endif // nadhir_H

#ifndef DIALOG_H
#define DIALOG_H
#include "localisation.h"
#include "evenement.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_3_clicked();
void on_pb_modifier_3_clicked();
    void on_pb_supprimer_3_clicked();
    void on_pb_ajouter_4_clicked();
void on_pb_modifier_4_clicked();
    void on_pb_supprimer_4_clicked();
    void on_rechercher_3_clicked();
    void on_rechercher_4_clicked();
    void on_lineEdit_11_selectionChanged();
    void on_trier_3_clicked();
    void on_pushButton_2_clicked();
     void on_pushButton_3_clicked();
    void on_lineEdit_8_selectionChanged();
    void on_trier_4_clicked();
    void on_tab_5_destroyed();

private:
    Ui::Dialog *ui;
    Localisation tmpLocalisation;
    Evenement tmpEvenement;
};

#endif // DIALOG_H

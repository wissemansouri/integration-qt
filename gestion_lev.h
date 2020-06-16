#ifndef GESTION_LEV_H
#define GESTION_LEV_H

#include "evenement.h"
#include "localisation.h"
#include <QMainWindow>
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class gestion_lev;
}

class gestion_lev : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_lev(QWidget *parent = nullptr);
    ~gestion_lev();

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
    void on_pushButton_4_clicked();
     void on_pushButton_3_clicked();
    void on_lineEdit_8_selectionChanged();
    void on_trier_4_clicked();
    void on_tab_5_destroyed();
 void on_pushButton_clicked();
private:
    Ui::gestion_lev *ui;
    Localisation tmpLocalisation;
    Evenement tmpEvenement;
};



#endif // GESTION_LEV_H

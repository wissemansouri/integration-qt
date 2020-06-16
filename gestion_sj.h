#ifndef GESTION_SJ_H
#define GESTION_SJ_H
#include "joueur.h"
#include "sport.h"
#include <QMainWindow>
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class gestion_sj;
}

class gestion_sj : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_sj(QWidget *parent = nullptr);
    ~gestion_sj();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_Ajouter_clicked();



    void on_pushButton_Chercher_clicked();

    void on_pushButton_Modifier_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_Consulter_clicked();

    void on_pushButton_AjouterS_clicked();

    void on_pushButton_ModifierS_clicked();

    void on_pushButton_SupprimerS_clicked();

    void on_pushButton_ConsulterS_clicked();

    void on_pushButton_ChercherS_clicked();

    void on_pushButton_clicked();

private:
    Ui::gestion_sj *ui;
    joueur tmpjoueur;
    sport tmpsport ;
};

#endif // GESTION_SJ_H

#ifndef DIALOG_HOME_H
#define DIALOG_HOME_H

#include <gestion_sj.h>
#include <gestion_pas.h>
#include <gestion_lev.h>

#include <QDialog>



namespace Ui {
class Dialog_home;
}

class Dialog_home : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_home(QWidget *parent = nullptr);
    ~Dialog_home();

private slots:
   /* void on_pushButton_Livre_clicked();

    void on_pushButton_Auteur_clicked();

    void on_pushButton_Personnel_clicked();

    void on_pushButton_Exemplaire_clicked();

    void on_pushButton_Departement_clicked();*/

    void on_sport_clicked();
    void on_localisationetevenement_clicked();
    void on_pubsponsoractu_clicked();
private:
    Ui::Dialog_home *ui;

     gestion_sj *acces_sport;
        gestion_lev *acces_localisationetevenement;
 gestion_pas *acces_pubsponsoractu;
};

#endif // DIALOG_HOME_H


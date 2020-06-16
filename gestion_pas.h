#ifndef GESTION_PAS_H
#define GESTION_PAS_H
#include "actualites.h"
#include "publicite.h"
#include "sponsor.h"
#include <QDialog>

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class gestion_pas;
}

class gestion_pas : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_pas(QWidget *parent = nullptr);
    ~gestion_pas();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_rechercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_rechercher_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_rechercher_3_clicked();


    void on_trier_clicked();
private:
    Ui::gestion_pas *ui;
    actualites tmpact;
        publicite tmpub;
        sponsor tmpsp;
};

#endif // GESTION_PAS_H

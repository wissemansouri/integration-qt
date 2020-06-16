/* #ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "localisation.h"
#include "evenement.h"
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
void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_ajouter_2_clicked();
void on_pb_modifier_2_clicked();
    void on_pb_supprimer_2_clicked();
    void on_rechercher_clicked();
    void on_rechercher_2_clicked();
    void on_lineEdit_5_selectionChanged();
    void on_trier_clicked();
    void on_pushButton_clicked();
      void on_trier_2_clicked();
      void on_lineEdit_6_selectionChanged();
    void on_tab_5_destroyed();

private:
    Ui::MainWindow *ui;
    Localisation tmpLocalisation;
    Evenement tmpEvenement;
};

#endif // MAINWINDOW_H */

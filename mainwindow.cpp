/* #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "localisation.h"
#include "evenement.h"
#include "statt.h"
#include <QMessageBox>
#include <QWidget>
#include <QTableWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabEvenement_2->setModel(tmpEvenement.afficher());
ui->tabLocalisation_2->setModel(tmpLocalisation.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString sport= ui->lineEdit_sport_7->text();
    QString tournois= ui->lineEdit_tournois_7->text();

  Localisation l(id,nom,sport,tournois);
  bool test=l.ajouter();
  if(test)
{

      ui->tabLocalisation_2->setModel(tmpLocalisation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter localisation"),
                  QObject::tr("Localisation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter localisation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_modifier_clicked()
{
    bool test=tmpLocalisation.modifier(ui->lineEdit_id_3->text().toInt(),ui->lineEdit_nom_2->text(),ui->lineEdit_sport_2->text(),ui->lineEdit_tournois_2->text());
    if(test)
  {
        ui->tabLocalisation_2->setModel(tmpLocalisation.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter localisation"),
                    QObject::tr("Localisation modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Localisation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpLocalisation.supprimer(id);
if(test)
{ui->tabLocalisation_2->setModel(tmpLocalisation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer Localisation"),
                QObject::tr(" Localisation supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer localisation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int idevenement = ui->lineEdit_id_4->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString sport= ui->lineEdit_sport->text();
    QString tournois=ui->lineEdit_tournois->text();
    QString date_debut= ui->dateTimeEdit->text();


  Evenement e(idevenement,nom,sport,tournois,date_debut);
  bool test=e.ajout();
  if(test)
{

      ui->tabEvenement_2->setModel(tmpEvenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_modifier_2_clicked()
{
    bool test=tmpEvenement.modifier(ui->lineEdit_id_5->text().toInt(),ui->lineEdit_nom_4->text(),ui->lineEdit_sport_4->text()
       ,ui->lineEdit_tournois_2->text(),ui->dateTimeEdit_2->text());
    if(test)
  {
        ui->tabEvenement_2->setModel(tmpEvenement.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un evenement"),
                    QObject::tr("Evenement modifie .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
int idevenement = ui->lineEdit_id_6->text().toInt();
bool test=tmpEvenement.supprimer(idevenement);
if(test)
{ui->tabEvenement_2->setModel(tmpEvenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_rechercher_clicked()
{
    QString str=ui->search->text();
    ui->tabrechercher->setModel(tmpLocalisation.recherche(str));
}
void MainWindow::on_rechercher_2_clicked()
{
    QString str=ui->search_2->text();
    ui->tabrechercher_2->setModel(tmpEvenement.recherche_2(str));
}


void MainWindow::on_lineEdit_5_selectionChanged()
{
    QString str=ui->lineEdit_5->text();
        ui->tabLocalisation_2->setModel(tmpLocalisation.recherche(str));
}

void MainWindow::on_trier_clicked()
{
     QString mode="ASC";
    if (ui->checkBox->checkState()==false)
        mode="DESC";
// ui->comboBox->currentText();
ui->tabLocalisation_2->setModel(tmpLocalisation.trier(ui->comboBox->currentText(),mode));

}
void MainWindow::on_lineEdit_6_selectionChanged()
{
    QString str=ui->lineEdit_6->text();
        ui->tabEvenement_2->setModel(tmpEvenement.recherche_2(str));
}
void MainWindow::on_trier_2_clicked()
{
     QString mode="ASC";
    if (ui->checkBox_2->checkState()==false)
        mode="DESC";
// ui->comboBox_2->currentText();
ui->tabEvenement_2->setModel(tmpEvenement.trier_2(ui->comboBox_2->currentText(),mode));

}
void MainWindow::on_pushButton_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}

void MainWindow::on_tab_5_destroyed()
{

}
*/

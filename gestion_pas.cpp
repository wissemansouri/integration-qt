#include "gestion_pas.h"
#include "ui_gestion_pas.h"
#include "actualites.h"
#include"publicite.h"
#include"sponsor.h"
#include <QMessageBox>
#include <QWidget>
#include <QTableWidget>

gestion_pas::gestion_pas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_pas)
{
    ui->setupUi(this);
    ui->tabLocalisation_2->setModel(tmpact.afficher());
    ui->tabLocalisation_3->setModel(tmpub.afficher());
    ui->tabLocalisation_4->setModel(tmpsp.afficher());

}

gestion_pas::~gestion_pas()
{
    delete ui;
}

void gestion_pas::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString texte= ui->lineEdit->text();


  actualites l(id,nom,texte);
  bool test=l.ajouter();
  if(test)
{

      ui->tabLocalisation_2->setModel(tmpact.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter actualites"),
                  QObject::tr("actualites ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter actualites"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_pas::on_pb_modifier_clicked()
{

    bool test=tmpact.modifier(ui->lineEdit_id_3->text().toInt(),ui->lineEdit_nom_2->text(),ui->lineEdit_sport_2->text());
    if(test)
  {
        ui->tabLocalisation_2->setModel(tmpact.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter actualites"),
                    QObject::tr("actualites modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter actualites"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_pas::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpact.supprimer(id);
    if(test)
    {ui->tabLocalisation_2->setModel(tmpact.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer actualites"),
                    QObject::tr("actualites supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer actualites"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_pas::on_rechercher_clicked()
{
    QString str=ui->search->text();
    ui->tabrechercher->setModel(tmpact.recherche(str));
}

void gestion_pas::on_pb_ajouter_2_clicked()
{


    int reference= ui->lineEdit_id_4->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString revenu= ui->lineEdit_2->text();


  publicite p(reference,nom,revenu);
  bool test=p.ajouter();
  if(test)
{

      ui->tabLocalisation_3->setModel(tmpub.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter publicite"),
                  QObject::tr("publicite ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter publicte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_pas::on_pb_modifier_2_clicked()
{
    bool test=tmpub.modifier(ui->lineEdit_id_5->text().toInt(),ui->lineEdit_nom_4->text(),ui->lineEdit_sport_3->text());
    if(test)
  {
        ui->tabLocalisation_3->setModel(tmpub.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter publicite"),
                    QObject::tr("publicite modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter publicite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_pas::on_pb_supprimer_2_clicked()
{

    int reference = ui->lineEdit_id_6->text().toInt();
    bool test=tmpub.supprimer(reference);
    if(test)
    {ui->tabLocalisation_3->setModel(tmpub.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer publicite"),
                    QObject::tr("publicite supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer publicite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_pas::on_rechercher_2_clicked()
{

    QString str=ui->search_2->text();
    ui->tabrechercher_2->setModel(tmpub.recherche(str));
}

void gestion_pas::on_pb_ajouter_3_clicked()
{
    int id = ui->lineEdit_id_7->text().toInt();
    QString nom= ui->lineEdit_nom_5->text();
    QString don= ui->lineEdit_3->text();


  sponsor s(id,nom,don);
  bool test=s.ajouter();
  if(test)
{

      ui->tabLocalisation_4->setModel(tmpsp.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter sponsor"),
                  QObject::tr("sponsor ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter sponsor"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_pas::on_pb_modifier_3_clicked()
{
    bool test=tmpsp.modifier(ui->lineEdit_id_8->text().toInt(),ui->lineEdit_nom_6->text(),ui->lineEdit_sport_4->text());
    if(test)
  {
        ui->tabLocalisation_4->setModel(tmpsp.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter sponsor"),
                    QObject::tr("sponsor modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter sponsor"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_pas::on_pb_supprimer_3_clicked()
{
    int id = ui->lineEdit_id_9->text().toInt();
    bool test=tmpsp.supprimer(id);
    if(test)
    {ui->tabLocalisation_4->setModel(tmpsp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer sponsor"),
                    QObject::tr("sponsor supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer sponsor"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_pas::on_rechercher_3_clicked()
{

    QString str=ui->search_3->text();
    ui->tabrechercher_3->setModel(tmpsp.recherche(str));
}



/*void gestion_pas::on_trier_clicked()
{
    QString mode="ASC";
   if (ui->checkBox->checkState()==false)
       mode="DESC";
// ui->comboBox->currentText();
ui->tabLocalisation_3->setModel(tmpub.trier(ui->comboBox->currentText(),mode));
}
*/

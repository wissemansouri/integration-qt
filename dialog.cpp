#include "dialog.h"
#include "ui_dialog.h"
#include "localisation.h"
#include "evenement.h"
#include "statt.h"
#include <QMessageBox>
#include <QWidget>
#include <QTableWidget>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
ui->setupUi(this);
ui->tabEvenement_4->setModel(tmpEvenement.afficher());
ui->tabLocalisation_4->setModel(tmpLocalisation.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_3_clicked()
{
    int id = ui->lineEdit_id_7->text().toInt();
    QString nom= ui->lineEdit_nom_5->text();
    QString sport= ui->lineEdit_sport_8->text();
    QString tournois= ui->lineEdit_tournois_8->text();
    int i,j,w,a;
       bool test1=true;
      bool test2=true;
      bool test3=true;
      bool test4=true;


      for (i=0;i<nom.length();i++) {
           if (nom[i]=="0" || nom[i]=="1" || nom[i]=="2" || nom[i]=="3" || nom[i]=="4" || nom[i]=="5" || nom[i]=="6" || nom[i]=="7" || nom[i]=="8" || nom[i]=="9")
              {
               test1=false;
               }
       }
      for (j=0;j<ui->lineEdit_id_7->text().length();j++) {
          if (ui->lineEdit_id_7->text()[j]=="a" || ui->lineEdit_id_7->text()[j]=="b" || ui->lineEdit_id_7->text()[j]=="c" || ui->lineEdit_id_7->text()[j]=="d" )
             {
              test2=false;
              }
      }
      for (w=0;w<sport.length();w++) {
           if (sport[w]=="0" || sport[w]=="1" || sport[w]=="2" || sport[w]=="3" || sport[w]=="4" || sport[w]=="5" || sport[w]=="6" || sport[w]=="7" || sport[w]=="8" || sport[w]=="9")
              {
               test3=false;
               }
                     }
           for (a=0;a<tournois.length();a++) {
                if (tournois[a]=="0" || tournois[a]=="1" || tournois[a]=="2" || tournois[a]=="3" || tournois[a]=="4" || tournois[a]=="5" || tournois[j]=="6" || tournois[a]=="7" || tournois[a]=="8" || tournois[a]=="9")
                   {
                    test4=false;
                    }
                   }
           if (ui->lineEdit_id_7->text().length()!=4)
                    test2=false;
        if ( test1  && test2 && test3 && test4)
      {
 Localisation l(id,nom,sport,tournois);
 bool test=l.ajouter();
 if(test)
{
     ui->tabLocalisation_4->setModel(tmpLocalisation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une localisation"),
                 QObject::tr("Localisation ajoutée.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
  } if (test2==false)
        {QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                    QObject::tr("Erreur ! il faut 4 chiffres \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
        if (test1==false)
    { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                 QObject::tr("Erreur ! pas de chiffres dans le nom \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);}
          if (test3==false)
           { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                            QObject::tr("Erreur ! pas de chiffres dans le sport \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
           if (test4==false)
           { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                            QObject::tr("Erreur ! pas de chiffres dans le tournois \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}


void Dialog::on_pb_modifier_3_clicked()
{
    bool test=tmpLocalisation.modifier(ui->lineEdit_id_8->text().toInt(),ui->lineEdit_nom_6->text(),ui->lineEdit_sport_3->text(),ui->lineEdit_tournois_3->text());
    if(test)
  {
        ui->tabLocalisation_4->setModel(tmpLocalisation.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter localisation"),
                    QObject::tr("Localisation modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Localisation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supprimer_3_clicked()
{
int id = ui->lineEdit_id_9->text().toInt();
bool test=tmpLocalisation.supprimer(id);
if(test)
{ui->tabLocalisation_4->setModel(tmpLocalisation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer Localisation"),
                QObject::tr(" Localisation supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer localisation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pb_ajouter_4_clicked()
{
    int idevenement = ui->lineEdit_id_10->text().toInt();
    QString nom= ui->lineEdit_nom_7->text();
    QString sport= ui->lineEdit_sport_5->text();
    QString tournois=ui->lineEdit_tournois_5->text();
    QString date_debut= ui->dateTimeEdit_3->text();
    int b,c,d,f;
           bool test5=true;
          bool test6=true;
          bool test7=true;
          bool test8=true;
          for (b=0;b<nom.length();b++) {
                     if (nom[b]=="0" || nom[b]=="1" || nom[b]=="2" || nom[b]=="3" || nom[b]=="4" || nom[b]=="5" || nom[b]=="6" || nom[b]=="7" || nom[b]=="8" || nom[b]=="9")
                        {
                         test5=false;
                         }
                 }
                for (c=0;c<ui->lineEdit_id_10->text().length();c++) {
                    if (ui->lineEdit_id_10->text()[c]=="a" || ui->lineEdit_id_10->text()[c]=="b" || ui->lineEdit_id_10->text()[c]=="c" || ui->lineEdit_id_10->text()[c]=="d" )
                       {
                        test6=false;
                        }
                }
                for (d=0;d<sport.length();d++) {
                     if (sport[d]=="0" || sport[d]=="1" || sport[d]=="2" || sport[d]=="3" || sport[d]=="4" || sport[d]=="5" || sport[d]=="6" || sport[d]=="7" || sport[d]=="8" || sport[d]=="9")
                        {
                         test7=false;
                         }
                               }
                     for (f=0;f<tournois.length();f++) {
                          if (tournois[f]=="0" || tournois[f]=="1" || tournois[f]=="2" || tournois[f]=="3" || tournois[f]=="4" || tournois[f]=="5" || tournois[f]=="6" || tournois[f]=="7" || tournois[f]=="8" || tournois[f]=="9")
                             {
                              test8=false;
                              }
                             }
                     if (ui->lineEdit_id_10->text().length()!=4)
                              test6=false;
                  if ( test5  && test6 && test7 && test8)
                {

  Evenement e(idevenement,nom,sport,tournois,date_debut);
  bool test=e.ajouter();
  if(test)
{

      ui->tabEvenement_4->setModel(tmpEvenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}    if (test6==false)
                  {QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                              QObject::tr("Erreur ! il faut 4 chiffres \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
                  if (test5==false)
                  { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                               QObject::tr("Erreur ! pas de chiffres dans le nom \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
                        if (test7==false)
                         { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                                          QObject::tr("Erreur ! pas de chiffres dans le sport \n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);}
                         if (test8==false)
                         { QMessageBox::critical(nullptr, QObject::tr("Ajouter une localisation"),
                                          QObject::tr("Erreur ! pas de chiffres dans le tournois \n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);}



              }

void Dialog::on_pb_modifier_4_clicked()
{
    bool test=tmpEvenement.modifier(ui->lineEdit_id_11->text().toInt(),ui->lineEdit_nom_8->text(),ui->lineEdit_sport_6->text()
       ,ui->lineEdit_tournois_6->text(),ui->dateTimeEdit_4->text());
    if(test)
  {
        ui->tabEvenement_4->setModel(tmpEvenement.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un evenement"),
                    QObject::tr("Evenement modifie .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supprimer_4_clicked()
{
int idevenement = ui->lineEdit_id_12->text().toInt();
bool test=tmpEvenement.supprimer(idevenement);
if(test)
{ui->tabEvenement_4->setModel(tmpEvenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void Dialog::on_rechercher_3_clicked()
{
    QString str=ui->search_3->text();
    ui->tabrechercher_3->setModel(tmpLocalisation.recherche(str));
}
void Dialog::on_rechercher_4_clicked()
{
    QString str=ui->search_4->text();
    ui->tabrechercher_4->setModel(tmpEvenement.recherche(str));
}


void Dialog::on_lineEdit_11_selectionChanged()
{
    QString str=ui->lineEdit_11->text();
        ui->tabLocalisation_4->setModel(tmpLocalisation.recherche(str));
}

void Dialog::on_trier_3_clicked()
{
     QString mode="ASC";
    if (ui->checkBox_3->checkState()==false)
        mode="DESC";
// ui->comboBox_3->currentText();
ui->tabLocalisation_4->setModel(tmpLocalisation.trier(ui->comboBox_3->currentText(),mode));

}
void Dialog::on_lineEdit_8_selectionChanged()
{
    QString str=ui->lineEdit_8->text();
        ui->tabEvenement_4->setModel(tmpEvenement.recherche(str));
}
void Dialog::on_trier_4_clicked()
{
     QString mode="ASC";
    if (ui->checkBox_4->checkState()==false)
        mode="DESC";
// ui->comboBox_4->currentText();
ui->tabEvenement_4->setModel(tmpEvenement.trier(ui->comboBox_4->currentText(),mode));

}
void Dialog::on_pushButton_2_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}
void Dialog::on_pushButton_3_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}

void Dialog::on_tab_5_destroyed()
{

}


#include "gestion_sj.h"
#include "ui_gestion_sj.h"
#include "joueur.h"
#include "sport.h"
#include "QTextBrowser"
#include <QtPrintSupport\qprinter.h>
#include <QTextStream>
gestion_sj::gestion_sj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_sj)
{
    ui->setupUi(this);
    ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
    ui->tablesport->setModel(tmpsport.afficher());//refresh
    //ui->comboBox_departement->setModel(tmpdepartement.Detailler());//refresh
    ui->tablesport_chercher->setModel(tmpsport.afficher());
    ui->tablesport->setModel(tmpsport.trier());
}

gestion_sj::~gestion_sj()
{
    delete ui;
}
void gestion_sj::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

}





void gestion_sj::on_pushButton_Ajouter_clicked()
{
    int Id =               ui->lineEdit_Id->text().toInt();
    QString Nom =          ui->lineEdit_Nom->text();
    QString Prenom =       ui->lineEdit_Prenom->text();
    int Age =              ui->lineEdit_Age->text().toInt();
    QString Role=          ui->lineEdit_Role->text();
    float Salaire=         ui->lineEdit_Salaire->text().toFloat();
    int Num_Tel  =         ui->lineEdit_NumTel->text().toInt();
    QString Adresse=       ui->lineEdit_Adresse->text();


 joueur J(Id,Nom,Prenom,Age,Role,Salaire,Num_Tel,Adresse);
 bool test=J.ajouter();
 if(test)
   {
       ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
       /*QMessageBox::information(nullptr, QObject::tr("Ajouter un joueur"),
       QObject::tr("joueur ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
       QMessageBox::information(this,"Ajout","Joueur ajouté");

   }
 else
   {
       /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un joueur"),
       QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
     QMessageBox::warning(this,"Ajout"," Erreur !");

   }
}



void gestion_sj::on_pushButton_Modifier_clicked()
{
    int Id2 =              ui->lineEdit_id2->text().toInt();
    QString Nom =          ui->lineEdit_Nom_2->text();
    QString Prenom =       ui->lineEdit_Prenom_2->text();
    int Age=               ui->lineEdit_Age_2->text().toInt();
    QString Role=          ui->lineEdit_Role_2->text();
    float Salaire=         ui->lineEdit_Salaire_2->text().toFloat();
    int Num_Tel=           ui->lineEdit_NumTel_2->text().toInt();
    QString Adresse=       ui->lineEdit_Adresse_2->text();

    joueur J(Id2,Nom,Prenom,Age,Role,Salaire,Num_Tel,Adresse);

     bool test=J.modifier(Id2);
     if(test)
     {
        ui->tablejoueur2->setModel(tmpjoueur.afficher());//refresh
        QMessageBox::information(this, "modification","joueur modifié");
     }


     else
     {

        QMessageBox::warning(this,"modification","Erreur ! ");
     }

}

void gestion_sj::on_pushButton_Supprimer_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
    bool test=tmpjoueur.supprimer(id);
    if(test)
    {
        ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
        /*QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
        QObject::tr("joueur supprimé.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Suppression","joueur supprimé");


    }
    else
    {
        /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un joueur"),
        QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
    }
}

void gestion_sj::on_pushButton_Consulter_clicked()
{
     ui->tablejoueur->setModel(tmpjoueur.trier());
}

void gestion_sj::on_pushButton_Chercher_clicked()
{
    int Id=ui->lineEdit_10->text().toInt();
    ui->tablejoueur->setModel(tmpjoueur.chercher(Id));
}

void gestion_sj::on_pushButton_AjouterS_clicked()
{
    int idS = ui->lineEdit->text().toInt();
    QString nomS =ui->lineEdit_2 ->text();
    QString type = ui->lineEdit_3->text();
    int budget = ui->lineEdit_4->text().toInt();
    int chiffreAffaire = ui->lineEdit_5->text().toInt();


   sport S(idS,nomS,type,budget,chiffreAffaire);
   bool test=S.ajouter();
   if(test)

           {
                ui->tablesport->setModel(tmpsport.afficher());//refresh
                 /*QMessageBox::information(nullptr, QObject::tr("Ajouter un Sport"),
                 QObject::tr("Sport ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
                QMessageBox::information(this,"Ajout","Sport ajouté");


           }
 else
           {
                 /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un Sport"),
                 QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
       QMessageBox::warning(this,"Ajout","Sport ajouté");

           }
}



void gestion_sj::on_pushButton_ModifierS_clicked()
{
    int idS = ui->lineEdit_12->text().toInt();
    QString nomS =ui->lineEdit_6 ->text();
    QString type = ui->lineEdit_7->text();
    int budget = ui->lineEdit_8->text().toInt();
    int chiffreAffaire = ui->lineEdit_11->text().toInt();

    sport S(idS,nomS,type,budget,chiffreAffaire);

     bool test=S.modifier(idS);
     if(test)
     {
        ui->tablesport->setModel(tmpsport.afficher());//refresh

        QMessageBox::information(this, "modification","sport modifié");

     }
     else
     {

         QMessageBox::warning(this,"modification","Erreur ! ");

     }

}


void gestion_sj::on_pushButton_SupprimerS_clicked()
{
    int id = ui->lineEdit_13->text().toInt();
    bool test=tmpsport.supprimer(id);
    if(test)
    {
          ui->tablesport->setModel(tmpsport.afficher());//refresh


          QMessageBox::information(this,"Suppression","Sport Supprimé");


    }
    else
       {
        QMessageBox::warning(this,"Suppression"," Erreur");

         }
}

void gestion_sj::on_pushButton_ConsulterS_clicked()
{

     ui->tablesport->setModel(tmpsport.trier());
}


void gestion_sj::on_pushButton_ChercherS_clicked()
{
    int idS=ui->lineEdit_12->text().toInt();
    ui->tablesport_chercher->setModel(tmpsport.chercher(idS));

}

void gestion_sj::on_pushButton_clicked()
{

    QString strStream;
        QTextStream out(&strStream);


        const int rowCount = ui->tablesport->model()->rowCount();
        const int columnCount = ui->tablesport->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("voiture")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tablesport->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tablesport->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tablesport->isColumnHidden(column)) {
                    QString data = ui->tablesport->model()->data(ui->tablesport->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

        QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("voiture.pdf");
            document->print(&printer);
}

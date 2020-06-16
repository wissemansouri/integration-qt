#include "evenement.h"
#include <QDebug>
#include "connexion.h"
Evenement::Evenement()
{
idevenement=0;
nom="";
sport="";
tournois="";
date_debut="";


}
Evenement::Evenement(int idevenement,QString nom,QString sport,QString tournois,QString date_debut)
{
  this->idevenement=idevenement;
  this->nom=nom;
  this->sport=sport;
  this->tournois=tournois;
  this->date_debut=date_debut;



}
int Evenement::get_idevenement(){return  idevenement;}
QString Evenement::get_nom(){return  nom;}
QString Evenement::get_sport(){return sport;}
QString Evenement::get_tournois(){return tournois;}
QString Evenement::get_date_debut(){return date_debut;}


bool Evenement::ajouter()
{
QSqlQuery query;
QString res= QString::number(idevenement);
QString res1= (date_debut);
QString res2=(nom);
QString res3=(sport);
QString res4=(tournois);
query.prepare("INSERT INTO Evenement (IDEVENEMENT, NOM, SPORT,TOURNOIS,DATE_DEBUT) "
                    "VALUES (:idevenement, :nom, :sport, :tournois, :date_debut)");
query.bindValue(":idevenement", res);
query.bindValue(":nom", res2);
query.bindValue(":sport", res3);
query.bindValue(":tournois", res4);
query.bindValue(":date_debut", res1);


return    query.exec();
}

QSqlQueryModel * Evenement::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Evenement");


    return model;
}


bool Evenement::modifier(int idevenement,QString nom,QString sport,QString tournois,QString date_debut)
{

    QSqlQuery qry;
        qry.prepare("UPDATE Evenement set NOM=(?),SPORT=(?),TOURNOIS=(?),DATE_DEBUT=(?) where IDEVENEMENT=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(sport);
        qry.addBindValue(tournois);
        qry.addBindValue(date_debut);
        qry.addBindValue(idevenement);
   return  qry.exec();
}

bool Evenement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Evenement where IDEVENEMENT = :idevenement ");
query.bindValue(":idevenement", res);
return    query.exec();
}

QSqlQueryModel * Evenement::recherche(const QString &idevenement)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Evenement where (IDEVENEMENT LIKE '"+idevenement+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("SPORT"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOURNOIS"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));


    return model;
}
QSqlQueryModel *  Evenement::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from Evenement order by "+critere+" "+mode+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEVENEMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SPORT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOURNOIS"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));

return model;
}


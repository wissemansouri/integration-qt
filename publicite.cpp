#include "publicite.h"
#include <QDebug>
#include "connexion.h"
publicite::publicite()
{
reference=0;
nom="";
revenu="";


}
publicite::publicite(int reference,QString nom,QString revenu)
{
  this->reference=reference;
  this->nom=nom;
  this->revenu=revenu;


}
QString publicite::get_nom(){return  nom;}

int publicite::get_reference(){return  reference;}
QString publicite::get_revenu(){return revenu;}


bool publicite::ajouter()
{
QSqlQuery query;
QString res= QString::number(reference);
query.prepare("INSERT INTO PUBLICITE (REF_PUB,NOM_PUB,REVENU_PUB) "
                    "VALUES (:ref_pub, :nom_pub, :revenu_pub)");
query.bindValue(":ref_pub", res);
query.bindValue(":nom_pub", nom);
query.bindValue(":revenu_pub", revenu);


return    query.exec();
}

QSqlQueryModel * publicite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PUBLICITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_PUB"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENU_PUB"));


    return model;
}

bool publicite::modifier(int reference,QString nom,QString revenu)
{

    QSqlQuery qry;
        qry.prepare("UPDATE PUBLICITE set NOM_PUB=(?),REVENU_PUB=(?) where REF_PUB=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(revenu);


        qry.addBindValue(reference);
   return  qry.exec();
}

bool publicite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PUBLICITE where REF_PUB= :ref_pub ");
query.bindValue(":ref_pub", res);
return    query.exec();
}

QSqlQueryModel * publicite::recherche(const QString &reference)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PUBLICTE where (REF_PUB LIKE '"+reference+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_PUB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REVENU_PUB"));



    return model;
}

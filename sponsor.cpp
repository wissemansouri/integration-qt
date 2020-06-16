#include "sponsor.h"
#include <QDebug>
#include "connexion.h"
sponsor::sponsor()
{
id=0;
nom="";
don="";


}
sponsor::sponsor(int id,QString nom,QString don)
{
  this->id=id;
  this->nom=nom;
  this->don=don;


}
QString sponsor::get_nom(){return  nom;}

int sponsor::get_id(){return  id;}
QString sponsor::get_don(){return don;}


bool sponsor::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO SPONSOR (ID,NOM,DON) "
                    "VALUES (:id, :nom, :don)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":don", don);


return    query.exec();
}

QSqlQueryModel * sponsor::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from SPONSOR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DON"));


    return model;
}

bool sponsor::modifier(int id,QString nom,QString don)
{

    QSqlQuery qry;
        qry.prepare("UPDATE SPONSOR set NOM=(?),DON=(?) where ID=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(don);


        qry.addBindValue(id);
   return  qry.exec();
}

bool sponsor::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from SPONSOR where ID= :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * sponsor::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from SPONSOR where (ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DON"));



    return model;
}

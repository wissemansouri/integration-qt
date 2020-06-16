#include "actualites.h"
#include <QDebug>
#include "connexion.h"
actualites::actualites()
{
id=0;
nom="";
texte="";


}
actualites::actualites(int id,QString nom,QString texte)
{
  this->id=id;
  this->nom=nom;
  this->texte=texte;


}
QString actualites::get_nom(){return  nom;}

int actualites::get_id(){return  id;}
QString actualites::get_texte(){return texte;}


bool actualites::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO ACTUALITES (ID,NOM,TEXTE) "
                    "VALUES (:id, :nom, :texte)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":texte", texte);


return    query.exec();
}

QSqlQueryModel * actualites::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from ACTUALITES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("texte"));


    return model;
}

bool actualites::modifier(int id,QString nom,QString texte)
{

    QSqlQuery qry;
        qry.prepare("UPDATE ACTUALITES set NOM=(?),TEXTE=(?) where ID=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(texte);


        qry.addBindValue(id);
   return  qry.exec();
}

bool actualites::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ACTUALITES where ID= :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * actualites::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from ACTUALITES where (ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("texte"));



    return model;
}

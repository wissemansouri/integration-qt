#include "localisation.h"
#include <QDebug>
#include "connexion.h"
Localisation::Localisation()
{
id=0;
nom="";
sport="";
tournois="";

}
Localisation::Localisation(int id,QString nom,QString sport,QString tournois)
{
  this->id=id;
  this->nom=nom;
  this->sport=sport;
  this->tournois=tournois;

}

int Localisation::get_id(){return  id;}
QString Localisation::get_nom(){return  nom;}
QString Localisation::get_sport(){return sport;}
QString Localisation::get_tournois(){return tournois;}

bool Localisation::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res0= (nom);
    QString res1= (sport);
    QString res2=(tournois);

    query.prepare("INSERT INTO LOCALISATION(ID,NOM,SPORT,TOURNOIS) "
                        "VALUES (:id,:nom,:sport,:tournois)");
    query.bindValue(":id", res);
    query.bindValue(":nom", res0);
    query.bindValue(":sport", res1);
    query.bindValue(":tournois", res2);


    return    query.exec();
    }


QSqlQueryModel * Localisation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Localisation");


    return model;
}

bool Localisation::modifier(int id,QString nom,QString sport,QString tournois)
{

    QSqlQuery qry;
        qry.prepare("UPDATE Localisation set NOM=(?),SPORT=(?),TOURNOIS=(?) where ID=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(sport);
        qry.addBindValue(tournois);
        qry.addBindValue(id);

   return  qry.exec();
}

bool Localisation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Localisation where ID= :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * Localisation::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Localisation where (ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SPORT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOURNOIS"));


    return model;
}

QSqlQueryModel *  Localisation::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from Localisation order by "+critere+" "+mode+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("sport"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("tournois"));

    return model;
}

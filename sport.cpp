#include "sport.h"

#include <QDebug>


sport::sport()
{

    idS=0;
    nomS="";
    type="";
    budget=0;
    chiffreAffaire=0;

}

sport::sport(int idS ,QString nomS,QString type,int budget,int chiffreAffaire)
{
  this->idS =idS ;
  this->nomS =nomS;
  this->type=type;
  this->budget=budget;
  this->chiffreAffaire=chiffreAffaire;
}
int sport::get_idS(){return  idS;}
QString sport::get_nomS(){return  nomS;}
QString sport::get_type(){return type;}
int sport::get_budget(){return budget;}
int sport::get_chiffreAffaire(){return chiffreAffaire;}


bool sport::ajouter()
{
QSqlQuery query;
QString res= QString::number(idS);
query.prepare("INSERT INTO SPORT    (idS,nomS,type,budget,chiffreAffaire)"
                           "VALUES (:idS,:nomS,:type,:budget,:chiffreAffaire)");
query.bindValue(":idS",res);
query.bindValue(":nomS",nomS);
query.bindValue(":type", type);
query.bindValue(":budget", budget);
query.bindValue(":chiffreAffaire", chiffreAffaire);
return   query.exec();
}

QSqlQueryModel * sport::afficher()
{

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SPORT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomS"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("chiffreAffaire"));
return model;
}

bool sport::supprimer(int idS)
{
QSqlQuery query;
QString res= QString::number(idS);
query.prepare("Delete from SPORT where idS = :idS ");
query.bindValue(":idS", res);
return    query.exec();
}

bool sport::modifier(int idS)
{
      QSqlQuery query;
    QString res= QString::number(idS);
    query.prepare("UPDATE sport SET nomS=:nomS,type=:type,budget=:budget,chiffreAffaire=:chiffreAffaire WHERE idS=:idS");
    query.bindValue(":idS",res);
    query.bindValue(":nomS",nomS);
    query.bindValue(":type",type);
    query.bindValue(":budget",budget);
    query.bindValue(":chiffreAffaire",chiffreAffaire);

    return    query.exec();
}

QSqlQueryModel * sport::chercher(int idS)
{
sport S;
    QSqlQuery query;
    QString res=QString::number(idS);
    query.prepare("Select * from SPORT where idS=:idS");
    query.bindValue(":idS",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idS"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nomS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  budget "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  chiffreAffaire "));


return model;
}
QSqlQueryModel *sport::trier()
{

    QSqlQuery query;
   query.prepare("select * from SPORT order By idS");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("idS"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nomS"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("  type "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("  budget "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("  chiffreAffaire "));


   return model;

}

#include "joueur.h"
#include<Qstring>
#include <QDebug>
#include<QPainter>
joueur::joueur()
{
 Id=0;
 Nom="";
 Prenom="";
 Age=0;
 Role="";
 Salaire=0;
 Num_Tel=0;
 Adresse="";

}

joueur::joueur(int Id ,QString Nom,QString Prenom,int Age, QString Role,float Salaire,int Num_Tel, QString Adresse)
{
  this->Id=Id;
  this->Nom=Nom;
  this->Prenom=Prenom;
  this->Age=Age;
  this->Role=Role;
  this->Salaire=Salaire;
  this->Adresse=Adresse;
  this->Num_Tel=Num_Tel;
  this->Adresse=Adresse;
  }

QString joueur::get_Nom(){return Nom;}
QString joueur::get_Prenom(){return  Prenom;}
QString joueur::get_Adresse(){return  Adresse;}
QString joueur::get_Role(){return  Role;}
int joueur::get_Id(){return  Id;}
int joueur::get_Age(){return  Age;}
int joueur::get_Num_Tel(){return  Num_Tel;}
float joueur::get_Salaire(){return Salaire;}

bool joueur::ajouter()
{
QSqlQuery query;

QString res= QString::number(Id);
query.prepare("INSERT INTO JOUEUR (Id,Nom,Prenom,Age,Role,Salaire,Num_Tel,Adresse)"
                             "VALUES (:Id,:Nom,:Prenom,:Age,:Role,:Salaire,:Num_Tel,:Adresse)");
query.bindValue(":Id", res);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Age", Age);
query.bindValue(":Role", Role);
query.bindValue(":Salaire", Adresse);
query.bindValue(":Num_Tel", Num_Tel);
query.bindValue(":Adresse", Adresse);

return  query.exec();
}

QSqlQueryModel * joueur::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from JOUEUR");
model->setHeaderData(0, Qt::Vertical, QObject::tr("Id"));
model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Vertical, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Vertical, QObject::tr("Age"));
model->setHeaderData(4, Qt::Vertical, QObject::tr("Role"));
model->setHeaderData(5, Qt::Vertical, QObject::tr("Salaire"));
model->setHeaderData(6, Qt::Vertical, QObject::tr("Num_Tel"));
model->setHeaderData(7, Qt::Vertical, QObject::tr("Adresse"));
return model;
}

bool joueur::supprimer(int Id)
{
    QSqlQuery query;
    QString res= QString::number(Id);
    query.prepare("Delete from joueur where Id = :Id ");
    query.bindValue(":Id", res);
    return    query.exec();
}

bool joueur::modifier(int Id)
{
    QSqlQuery query;
  QString res= QString::number(Id);
  query.prepare("UPDATE joueur SET Nom=:Nom,Prenom=:Prenom,Age=:Age,Role=:Role,Salaire=:Salaire,Num_Tel=:Num_Tel,Adresse=:Adresse WHERE Id=:Id");
  query.bindValue(":Id", res);
  query.bindValue(":Nom", Nom);
  query.bindValue(":Prenom", Prenom);
  query.bindValue(":Age", Age);
  query.bindValue(":Role", Role);
  query.bindValue(":Salaire", Adresse);
  query.bindValue(":Num_Tel", Num_Tel);
  query.bindValue(":Adresse", Adresse);
  return    query.exec();
}

QSqlQueryModel * joueur::chercher(int Id)
{
joueur j;
    QSqlQuery query;
    QString res=QString::number(Id);
    query.prepare("Select * from JOUEUR where Id=:Id");
    query.bindValue(":Id",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Num_Tel "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse "));

return model;
}
QSqlQueryModel *joueur::trier()
{

    QSqlQuery query;
   query.prepare("select * from JOUEUR order By Id");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Num_Tel "));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse "));
   return model;

}

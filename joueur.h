#ifndef JOUEUR_H
#define JOUEUR_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
class joueur
{
private:
    int Id,Age,Num_Tel ;
    float Salaire;
    QString Nom,Prenom,Role,Adresse;

public:
    joueur();
    joueur(int,QString,QString,int,QString,float,int,QString);

    int get_Id();
    QString get_Nom();
    QString get_Prenom();
    int get_Age();
    QString get_Role();
    float get_Salaire();
    int get_Num_Tel();
    QString get_Adresse();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trier();

    QSqlQueryModel * chercher(int);

};


#endif // JOUEUR_H

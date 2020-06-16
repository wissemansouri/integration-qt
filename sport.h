#ifndef SPORT_H
#define SPORT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class sport
{
private:
    int idS ;
    QString nomS,type ;
    int budget,chiffreAffaire;


public:
    sport();
    sport(int,QString,QString,int,int);

    int get_idS ();
    QString get_nomS ();
    QString get_type ();
    int get_budget();
    int get_chiffreAffaire();

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trier();
    QSqlQueryModel * chercher(int);
};

#endif // SPORT_H

#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Evenement
{public:
    Evenement();
    Evenement(int,QString,QString,QString,QString);
    int get_idevenement();
    QString get_nom();
    QString get_sport();
    QString get_tournois();
    QString get_date_debut();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int,QString,QString,QString,QString);
     QSqlQueryModel * recherche(const QString &idevenement);
      QSqlQueryModel * trier(const QString &critere, const QString &mode );
private:
    QString nom,sport,tournois,date_debut;
    int idevenement;

};

#endif // EVENEMENT_H

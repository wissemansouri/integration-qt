#ifndef LOCALISATION_H
#define LOCALISATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Localisation
{public:
    Localisation();
    Localisation(int,QString,QString,QString);
    QString get_sport();
      QString get_nom();
    QString get_tournois();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString);
       QSqlQueryModel * recherche(const QString &id);
       QSqlQueryModel * trier(const QString &critere, const QString &mode );
private:
    QString nom,tournois,sport;
    int id;
};

#endif // LOCALISATION_H

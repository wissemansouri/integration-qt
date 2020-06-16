#ifndef ACTUALITES_H
#define ACTUALITES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class actualites
{public:
    actualites();
    actualites(int,QString,QString);
    QString get_texte();
      QString get_nom();

    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);
       QSqlQueryModel * recherche(const QString &id);

private:
    QString nom,texte;
    int id;
};


#endif // ACTUALITES_H

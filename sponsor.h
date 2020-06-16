#ifndef SPONSOR_H
#define SPONSOR_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class sponsor
{public:
    sponsor();
    sponsor(int,QString,QString);
    QString get_don();
      QString get_nom();

    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);
       QSqlQueryModel * recherche(const QString &reference);

private:
    QString nom,don;
    int id;
};

#endif // SPONSOR_H

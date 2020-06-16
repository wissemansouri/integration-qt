#ifndef PUBLICITE_H
#define PUBLICITE_H



#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class publicite
{public:
    publicite();
    publicite(int,QString,QString);
    QString get_revenu();
      QString get_nom();

    int get_reference();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);
       QSqlQueryModel * recherche(const QString &reference);
        QSqlQueryModel * trier(const QString &critere, const QString &mode );

private:
    QString nom,revenu;
    int reference;
};


#endif // PUBLICITE_H

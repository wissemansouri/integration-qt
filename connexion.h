#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
    QSqlDatabase db;
public:
    connexion();
    bool createconnect();
    void fermerConnexion();
};

#endif // CONNEXION_H

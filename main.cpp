#include "dialog.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    Connexion c;
    try {
       bool t= c.ouvrirConnexion();
        qDebug()<<"hhhhhh"<<t;
        w.show();

    } catch (QString s) {
        qDebug()<<s;

    }



    return a.exec();
}

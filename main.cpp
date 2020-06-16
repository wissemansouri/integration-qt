#include "mainwindow.h"
#include "connexion.h"
#include "gestion_sj.h"
#include "gestion_lev.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    try {
       bool t= c.createconnect();
        qDebug()<<"connexion valide"<<t;

        w.show();

    } catch (QString s) {
        qDebug()<<s;

    }



    return a.exec();
}

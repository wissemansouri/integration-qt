#include "dialog_home.h"
#include "ui_dialog_home.h"

Dialog_home::Dialog_home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_home)
{
    ui->setupUi(this);
}

Dialog_home::~Dialog_home()
{
    delete ui;
}


void Dialog_home::on_sport_clicked()
{
    acces_sport = new gestion_sj(this);
    acces_sport->show();
}
void Dialog_home::on_localisationetevenement_clicked()
{
    acces_localisationetevenement= new gestion_lev(this);
    acces_localisationetevenement->show();
}
void Dialog_home::on_pubsponsoractu_clicked()
{
    acces_pubsponsoractu= new gestion_pas(this);
    acces_pubsponsoractu->show();
}


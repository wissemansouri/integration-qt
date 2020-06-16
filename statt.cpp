#include "statt.h"
#include "ui_statt.h"
#include"evenement.h"
#include"localisation.h"
#include <QDialog>
#include <QSqlQuery>

statt::statt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statt)
{
    ui->setupUi(this);
     this->setWindowTitle("Statistiques");
    //***************************************************************
       QSqlQuery q1,q2;
           qreal sport=0,tournois=0;
           //QSqlQuery q4,q5,q6;
          // qreal en_attente2=0,en_cours2=0,envoye2=0;

           q1.prepare("SELECT * FROM localisation ");
           q1.exec();
           q2.prepare("SELECT * FROM evenement ");
           q2.exec();


           while (q1.next()){sport++;}
           while (q2.next()){tournois++;}



           // Assign names to the set of bars used
           QBarSet *set0 = new QBarSet("les sports  ");
           QBarSet *set1 = new QBarSet("les tournois ");


           // Assign values for each bar
         *set0 << sport ; //hethouma les variable eli fihom les valeurs
          *set1 << tournois ;


           // Add all sets of data to the chart as a whole
           // 1. Bar Chart
           QBarSeries *series = new QBarSeries();

           // 2. Stacked bar chart
           //QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
           series->append(set0);
           series->append(set1);


           // Used to define the bar chart to display, title
           // legend,
           QChart *chart = new QChart();

           // Add the chart
           chart->addSeries(series);

           // Set title
           chart->setTitle("le nombre de sports et des tournois");

           // Define starting animation
           // NoAnimation, GridAxisAnimations, SeriesAnimations
           chart->setAnimationOptions(QChart::AllAnimations);

           // Holds the category titles
           QStringList categories;
           categories <<"";

           // Adds categories to the axes
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();

           // 1. Bar chart
           chart->setAxisX(axis,series);

           // 2. Stacked Bar chart
           // chart->setAxisY(axis, series);

           // Define where the legend is displayed
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);

           // Used to display the chart
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);

           // Used to change the palette
           QPalette pal = qApp->palette();

           // Change the color around the chart widget and text
           pal.setColor(QPalette::Window, QRgb(0xffffff));
           pal.setColor(QPalette::WindowText, QRgb(0x404044));

           // Apply palette changes to the application
           qApp->setPalette(pal);
           chartView->setParent(ui->horizontalFrame);

}

statt::~statt()
{
    delete ui;
}

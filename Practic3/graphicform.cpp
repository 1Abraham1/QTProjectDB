#include "graphicform.h"
#include "ui_graphicform.h"
#include "bookFile.h"
#include <algorithm>
#include <QVector>

using namespace std;

GraphicForm::GraphicForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicForm)
{
    ui->setupUi(this);

    bookFile book;
    //book.f->reset();

    QVector<int> years = book.GetAllYears();
    sort(years.begin(), years.end());

    QVector<int> amount;
    QVector<int>::iterator it = years.begin();

    for (int i = 0; i < years.size(); i++)
    {
        amount.push_back(1);
        for (int j = i + 1; j < years.size();)
        {
            if (years[i] == years[j])
            {
                amount[i] += 1;
                years.erase(it + j);
            }
            else { j++; }
        }
    }

    series = new QBarSeries();

    for (int i = 0; i < years.size(); i++)
    {
        set = new QBarSet(QString::number(years[i]));
        *set << amount[i];
        series->append(set);
    }


    //int xBegin = *min_element(years.begin(), years.end());
    //int xEnd = *max_element(years.begin(), years.end());
    int yEnd = *max_element(amount.begin(), amount.end());


    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("График количества произведенных трамваев по годам");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //QStringList categories;
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    axisX = new QBarCategoryAxis();
    axisX->append("Обозначение (год):");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0, yEnd + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
}

GraphicForm::~GraphicForm()
{
    delete ui;
}

void GraphicForm::on_pushButton_clicked()
{
    series->clear();
    close();
}


void GraphicForm::on_pushButton_2_clicked()
{
    bookFile book;
    //book.f->reset();

    QVector<int> years = book.GetAllYears();
    sort(years.begin(), years.end());

    QVector<int> amount;
    QVector<int>::iterator it = years.begin();

    for (int i = 0; i < years.size(); i++)
    {
        amount.push_back(1);
        for (int j = i + 1; j < years.size();)
        {
            if (years[i] == years[j])
            {
                amount[i] += 1;
                years.erase(it + j);
            }
            else { j++; }
        }
    }

    //series->clear();

    for (int i = 0; i < years.size(); i++)
    {
        set = new QBarSet(QString::number(years[i]));
        *set << amount[i];
        series->append(set);
    }

    //chart->removeAllSeries();
    //chart->addSeries(series);

    //int xBegin = *min_element(years.begin(), years.end());
    //int xEnd = *max_element(years.begin(), years.end());
    int yEnd = *max_element(amount.begin(), amount.end());
    axisY->setRange(0, yEnd + 1);


}
/*
 * void GraphicForm::on_pushButton_clicked()
{
    series->clear();
    close();
}
 *
 *
 *GraphicForm::GraphicForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicForm)
{
    ui->setupUi(this);


    series = new QBarSeries();

    chart = new QChart();
    //chart->addSeries(series);
    chart->setTitle("График количества произведенных трамваев по годам");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    axisX = new QBarCategoryAxis();
    axisX->append("Обозначение:");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
}

 *
void GraphicForm::on_pushButton_2_clicked()
{
    bookFile book;
    book.f->reset();

    QVector<int> years = book.GetAllYears();
    sort(years.begin(), years.end());

    QVector<int> amount;
    QVector<int>::iterator it = years.begin();

    for (int i = 0; i < years.size(); i++)
    {
        amount.push_back(1);
        for (int j = i + 1; j < years.size();)
        {
            if (years[i] == years[j])
            {
                amount[i] += 1;
                years.erase(it + j);
            }
            else { j++; }
        }
    }

    //series->clear();

    for (int i = 0; i < years.size(); i++)
    {
        set = new QBarSet(QString::number(years[i]));
        *set << amount[i];
        series->append(set);
    }

    chart->removeAllSeries();
    chart->addSeries(series);

    //int xBegin = *min_element(years.begin(), years.end());
    //int xEnd = *max_element(years.begin(), years.end());
    int yEnd = *max_element(amount.begin(), amount.end());


    axisY->setRange(0, yEnd + 1);


}
*/
/*


    bookFile book;
    book.f->reset();

    years = book.GetAllYears();
    sort(years.begin(), years.end());

    QVector<int> amount;
    QVector<int>::iterator it = years.begin();

    for (int i = 0; i < years.size(); i++)
    {
        amount.push_back(1);
        for (int j = i + 1; j < years.size();)
        {
            if (years[i] == years[j])
            {
                amount[i] += 1;
                years.erase(it + j);
            }
            else { j++; }
        }
    }

    series = new QBarSeries();

    for (int i = 0; i < years.size(); i++)
    {
        set = new QBarSet(QString::number(years[i]));
        *set << amount[i];
        series->append(set);
    }


    //int xBegin = *min_element(years.begin(), years.end());
    //int xEnd = *max_element(years.begin(), years.end());
    int yEnd = *max_element(amount.begin(), amount.end());


    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("График количества произведенных трамваев по годам");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //QStringList categories;
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    axisX = new QBarCategoryAxis();
    axisX->append("Обозначение:");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0, yEnd + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);

*/

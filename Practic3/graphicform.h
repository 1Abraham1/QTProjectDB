#ifndef GRAPHICFORM_H
#define GRAPHICFORM_H

#include <QWidget>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>
#include <QChartView>
#include <QChart>

namespace Ui {
class GraphicForm;
}

class GraphicForm : public QWidget
{
    Q_OBJECT
    QChart *chart;
    QBarSeries *series;
    QBarSet *set;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
public:
    explicit GraphicForm(QWidget *parent = nullptr);
    ~GraphicForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GraphicForm *ui;
};

#endif // GRAPHICFORM_H

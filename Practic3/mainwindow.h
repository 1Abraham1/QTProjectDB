
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addform.h"
#include "listform.h"
#include "delform.h"
#include "Findform.h"
#include "srokform.h"
#include "countmodelform.h"
#include "graphicform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT
    addForm winAdd;
    ListForm winList;
    DelForm winDel;
    FindForm winFind;
    SrokForm winSrok;
    CountModelForm winCountModel;
    GraphicForm winGraphic;
    /*
    deleteForm winDelete;
    findYearForm winFind;
    printForm winPrint;
    graphForm winGraph;
    */

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /*
    void showDelete();
    void showFindYear();

    void showPrintLife_time();
    void showGraph();
    void resetFile();
    void ModelCount();
    */

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

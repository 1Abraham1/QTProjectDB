
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_5_clicked()
{
    if( QMessageBox::question ( this, QString(), "Close application?",
                              QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes )
        exit(0);
    else show();
}


void MainWindow::on_pushButton_6_clicked()
{
    winAdd.show();
}


void MainWindow::on_pushButton_8_clicked()
{
    winList.show();
}


void MainWindow::on_pushButton_7_clicked()
{
    winDel.show();
}


void MainWindow::on_pushButton_clicked()
{
    winFind.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    winSrok.show();
}


void MainWindow::on_pushButton_3_clicked()
{
    winCountModel.show();
}


void MainWindow::on_pushButton_4_clicked()
{
    winGraphic.show();
}


#include "srokform.h"
#include "ui_srokform.h"
#include "bookFile.h"

SrokForm::SrokForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SrokForm)
{
    ui->setupUi(this);
    ui->table->setRowCount(0);
    ui->table->setColumnCount(3);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Номер" << "Модель" << "Просрочка (лет)");

    bookFile book;
    bool fff = book.readRec();
    int i = 0;
    int row = 1;
    while (fff)
    {
        if ((2023 - book.r.year.toInt()) > book.r.life_time.toInt()) {
            if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
            QTableWidgetItem *item;
            item = new QTableWidgetItem(book.r.num);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 0, item);
            item = new QTableWidgetItem(book.r.model);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 1, item);
            item = new QTableWidgetItem(QString::number(2023 - book.r.year.toInt() - book.r.life_time.toInt()));
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 2, item);
            fff = book.readRec();
            i++;
            row++;
        }
        else { fff = book.readRec(); }
    }
}

SrokForm::~SrokForm()
{
    delete ui;
}

void SrokForm::on_pushButton_clicked()
{
    //for (int i = 0; i < row; i++) {
    //    ui->table->hideRow(i);
    //}
    ui->table->setRowCount(0);
    close();
}


void SrokForm::on_pushButton_2_clicked()
{
    bookFile book;
    bool fff = book.readRec();
    int i = 0;
    while (fff)
    {
        if ((2023 - book.r.year.toInt()) > book.r.life_time.toInt()) {
            if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
            QTableWidgetItem *item;
            item = new QTableWidgetItem(book.r.num);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 0, item);
            item = new QTableWidgetItem(book.r.model);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 1, item);
            item = new QTableWidgetItem(QString::number(2023 - book.r.year.toInt() - book.r.life_time.toInt()));
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 2, item);
            fff = book.readRec();
            i++;
        }
        else { fff = book.readRec(); }
    }
}


#include "findform.h"
#include "ui_findform.h"
#include "bookFile.h"
#include <QMessageBox>

FindForm::FindForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindForm)
{
    ui->setupUi(this);
    ui->table->setRowCount(0);
    ui->table->setColumnCount(4);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Номер" << "Модель" << "Год производства" << "Срок службы");


}

FindForm::~FindForm()
{
    delete ui;
}

void FindForm::on_pushButton_2_clicked()
{
    //for (int i = 0; i < ui->table->rowCount(); i++) {
    //    ui->table->removeRow(i);
    //}
    ui->table->setRowCount(0);
    close();
}

void FindForm::showRow(int i, Tram r)
{
    QTableWidgetItem *item;

    item = new QTableWidgetItem(r.num);
    item->setFlags(Qt::NoItemFlags);
    ui->table->setItem(i, 0, item);

    item = new QTableWidgetItem(r.model);
    item->setFlags(Qt::NoItemFlags);
    ui->table->setItem(i, 1, item);

    item = new QTableWidgetItem(r.year);
    item->setFlags(Qt::NoItemFlags);
    ui->table->setItem(i, 2, item);

    item = new QTableWidgetItem(r.life_time);
    item->setFlags(Qt::NoItemFlags);
    ui->table->setItem(i, 3, item);
}



void FindForm::on_pushButton_clicked()
{
    for (int i = 0; i < ui->table->rowCount(); i++) {
        ui->table->removeRow(i);
    }
    int year = ui->yearEdit->text().toInt();
    ui->yearEdit->clear();

    bookFile book;
    bool fff = book.readRec();
    int i = 0;
    while (fff)
    {
        if (book.r.year.toInt() >= year) {
            if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
            QTableWidgetItem *item;
            item = new QTableWidgetItem(book.r.num);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 0, item);
            item = new QTableWidgetItem(book.r.model);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 1, item);
            item = new QTableWidgetItem(book.r.year);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 2, item);
            item = new QTableWidgetItem(book.r.life_time);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 3, item);
            fff = book.readRec();
            i++;
        }
        else { fff = book.readRec(); }
    }


    /*
    bookFile book;
    book.f->reset();

    if (!book.find(year))
    {
        QMessageBox msg(QMessageBox::Critical, "Нет данных", "Данные не найдены",
                        QMessageBox::Ok, 0);
        msg.exec();
    }
    else {
        showRow(0, book.r);
        int i = 0;
        while (book.find(year))
        {
            if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
            showRow(++i, book.r);
        }
        //ui->table->setRowCount(i+1);
    }
*/
}


#include "listform.h"
#include "ui_listform.h"
#include "bookFile.h"
#include <QMessageBox>

ListForm::ListForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListForm)
{
    ui->setupUi(this);
    ui->table->setRowCount(0);
    ui->table->setColumnCount(4);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Номер" << "Модель" << "Год производства" << "Срок службы");

    bookFile book;
    bool fff = book.readRec();

    int i = 0;
    while (fff) {
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
}

/*
void ListForm::showRow(int i, Tram r)
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
*/

ListForm::~ListForm()
{
    delete ui;
}

void ListForm::on_pushButton_clicked()
{
    close();
}


void ListForm::on_pushButton_2_clicked()
{

/*
 *    bookFile book;

    if (!book.readRec())
    {
        QMessageBox msg(QMessageBox::Critical, "Нет данных", "База пуста", QMessageBox::Ok, 0);
        msg.exec();
    }
    else {
        showRow(0, book.r);
        int i = 0;
        while(book.readRec())
        {
            showRow(++i, book.r);
        }
        if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
    }
 */


    bookFile book;
    bool fff = book.readRec();

    for (int i = 0; i < book.f->size(); i++) {
        ui->table->removeRow(i);
    }

    int i = 0;
    while (fff) {
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
}

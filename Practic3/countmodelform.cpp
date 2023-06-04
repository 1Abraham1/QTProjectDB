#include "countmodelform.h"
#include "ui_countmodelform.h"
#include "bookFile.h"

CountModelForm::CountModelForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountModelForm)
{
    ui->setupUi(this);
    ui->table->setRowCount(0);
    ui->table->setColumnCount(3);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Номер" << "Год произв." << "Срок службы");
}

CountModelForm::~CountModelForm()
{
    delete ui;
}

void CountModelForm::on_pushButton_clicked()
{
    ui->table->setRowCount(0);
    ui->countEdit->clear();
    close();
}


void CountModelForm::on_pushButton_2_clicked()
{
    //for (int i = 0; i < ui->table->rowCount(); i++) {
    //    ui->table->removeRow(i);
    //}
    ui->table->setRowCount(0);

    bookFile book;
    bool fff = book.readRec();
    int i = 0;
    count = 0;
    while (fff)
    {
        if (book.r.model == ui->modelEdit->text()) {
            if (i >= ui->table->rowCount()) {ui->table->setRowCount(i+1);}
            QTableWidgetItem *item;
            item = new QTableWidgetItem(book.r.num);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 0, item);
            item = new QTableWidgetItem(book.r.year);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 1, item);
            item = new QTableWidgetItem(book.r.life_time);
            item->setFlags(Qt::NoItemFlags);
            ui->table->setItem(i, 2, item);
            fff = book.readRec();
            i++;
            count++;
        }
        else { fff = book.readRec(); }
    }
    ui->modelEdit->clear();
    ui->countEdit->setText(QString::number(count));
}


void CountModelForm::on_modelEdit_textChanged(const QString &arg1)
{
    ui->countEdit->clear();
}


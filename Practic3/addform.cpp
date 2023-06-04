#include "addform.h"
#include "ui_addform.h"
#include "bookFile.h"

addForm::addForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addForm)
{
    ui->setupUi(this);
}


addForm::~addForm()
{
    delete ui;
}

void addForm::on_exitButton_clicked()
{
    ui->inf->clear();
    close();
}


void addForm::on_addButton_clicked()
{
    Tram r;
    bookFile book;

    r.num = ui->numEdit->text();
    r.model = ui->modelEdit->text();
    r.year = ui->yearEdit->text();
    r.life_time = ui->life_timeEdit->text();

    ui->numEdit->clear();
    ui->modelEdit->clear();
    ui->yearEdit->clear();
    ui->life_timeEdit->clear();

    ui->inf->setText("           Успешно");
    book.addRec(r);
}


void addForm::on_numEdit_textChanged(const QString &arg1)
{
    ui->inf->clear();
}

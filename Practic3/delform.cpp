#include "delform.h"
#include "ui_delform.h"
#include "bookFile.h"
#include <QMessageBox>

DelForm::DelForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DelForm)
{
    ui->setupUi(this);
}

DelForm::~DelForm()
{
    delete ui;
}

void DelForm::on_pushButton_2_clicked()
{
    ui->inf->setText(" ");
    close();
}


void DelForm::on_pushButton_clicked()
{
    bookFile book;
    book.f->reset();

    int num = ui->numEdit->text().toInt();

    ui->numEdit->clear();
    ui->inf->setText("  Успешно");



    if (!book.delete_num(num)){
        QMessageBox msg(QMessageBox::Warning, "Ошибка", "Номер не идентифицирован / БД пустая");
        msg.exec();
    }
}


void DelForm::on_numEdit_textChanged(const QString &arg1)
{
    ui->inf->clear();
}


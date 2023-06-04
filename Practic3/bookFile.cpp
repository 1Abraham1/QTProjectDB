#include "bookFile.h"
#include <QMessageBox>
#include <QVector>

bookFile::bookFile()
{
    f = new QFile("depo.txt");
    if (!f->exists())
    {
        QMessageBox msg(QMessageBox::Critical, "Файл не найден", "Файл book.txt создан",
                        QMessageBox::Ok, 0);
        msg.exec();
    }
    f->open(QFile::ReadWrite);
}

bookFile::~bookFile()
{
    f->close();
    delete f;
}

void bookFile::DeleteContent()
{
    if (f->size() == 0)
    {
        QMessageBox msg(QMessageBox::Warning, "Сброс данных", "База данных пуста");
        msg.exec();
    }
    else
    {
        f->resize(0);
        QMessageBox msg(QMessageBox::Information, "Сброс данных", "Данные успешно очищены");
        msg.exec();
    }
}

bool bookFile::addRec(Tram r)
{
    f->seek(f->size());
    QDataStream out(f);
    out << r.num << r.model << r.year << r.life_time;
    return true;
}

bool bookFile::readRec()
{
    QDataStream in(f);
    if (in.atEnd()) {
        f->seek(0);
        return false;
    }
    else {
        in >> r.num >> r.model >> r.year >> r.life_time;
        return true;
    }
}

bool bookFile::find(int year)
{

    ff = false;

    bool fff = readRec();


    while ((!ff) && fff)
    {
        if (r.year.toInt() > year) {
            ff = true;
        }
        else { fff = readRec(); }
    }
    return ff;
}

bool bookFile::findLife_time()
{

    ff = false;
    bool fff = readRec();


    while ((!ff) && fff)
    {
        if ((2021 - r.year.toInt()) > r.life_time.toInt()) {
            ff = true;
        }
        else { fff = readRec(); }
    }
    return ff;
}

bool bookFile::delete_num(int num)
{
    QVector<Tram> mas;

    bool fff = readRec();
    bool find = false;
    if (!fff) { return false; }
    while (fff)
    {
        if (r.num.toInt() != num) {
            mas.push_back(r);
        }
        else {find = true; }
        fff = readRec();
    }
    f->resize(0);
    for (int i = 0; i < mas.size(); i++)
    {
        addRec(mas[i]);
    }
    return find;

}

int bookFile::modelCount(QString model)
{
    bool fff = readRec();
    int count = 0;


    while (fff)
    {
        if (r.model == model) {
            count += 1;
        }
        fff = readRec();
    }
    return count;
}

QVector<int> bookFile::GetAllYears()
{
    QVector<int> years;

    bool fff = readRec();


    while (fff)
    {
        years.push_back(r.year.toDouble());
        fff = readRec();
    }

    return years;
}


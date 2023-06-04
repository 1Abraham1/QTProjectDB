
#ifndef BOOKFILE_H
#define BOOKFILE_H


#include <QFile>
#include <QVector>

struct Tram
{
    QString num, model, year, life_time;
};

class bookFile
{
    bool ff;
public:
    QFile *f;
    Tram r;
    bookFile();
    ~bookFile();
    bool addRec(Tram r);
    bool readRec();
    bool find(int year);
    bool findLife_time();
    bool delete_num(int num);
    int modelCount(QString model);
    bool findNext(int year);
    QVector<int> GetAllYears();
    void DeleteContent();
};



#endif // BOOKFILE_H

#ifndef LISTFORM_H
#define LISTFORM_H

#include <QWidget>
#include "bookFile.h"

namespace Ui {
class ListForm;
}

class ListForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListForm(QWidget *parent = nullptr);
    void showRow(int i, Tram r);

    ~ListForm();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::ListForm *ui;
};

#endif // LISTFORM_H

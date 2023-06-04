#ifndef FINDFORM_H
#define FINDFORM_H

#include "bookFile.h"
#include <QWidget>

namespace Ui {
class FindForm;
}

class FindForm : public QWidget
{
    Q_OBJECT

public:
    explicit FindForm(QWidget *parent = nullptr);
    void showRow(int i, Tram r);
    ~FindForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FindForm *ui;
};

#endif // FINDFORM_H

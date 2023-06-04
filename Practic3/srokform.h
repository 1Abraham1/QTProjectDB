#ifndef SROKFORM_H
#define SROKFORM_H

#include <QWidget>

namespace Ui {
class SrokForm;
}

class SrokForm : public QWidget
{
    Q_OBJECT

public:
    int row;
    explicit SrokForm(QWidget *parent = nullptr);
    ~SrokForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SrokForm *ui;
};

#endif // SROKFORM_H

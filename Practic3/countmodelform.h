#ifndef COUNTMODELFORM_H
#define COUNTMODELFORM_H

#include <QWidget>

namespace Ui {
class CountModelForm;
}

class CountModelForm : public QWidget
{
    Q_OBJECT

public:
    int count;
    explicit CountModelForm(QWidget *parent = nullptr);
    ~CountModelForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modelEdit_textChanged(const QString &arg1);

private:
    Ui::CountModelForm *ui;
};

#endif // COUNTMODELFORM_H

#ifndef DELFORM_H
#define DELFORM_H

#include <QWidget>

namespace Ui {
class DelForm;
}

class DelForm : public QWidget
{
    Q_OBJECT

public:
    explicit DelForm(QWidget *parent = nullptr);
    ~DelForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_numEdit_textChanged(const QString &arg1);

private:
    Ui::DelForm *ui;
};

#endif // DELFORM_H

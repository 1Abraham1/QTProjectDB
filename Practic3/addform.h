#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>

namespace Ui {
class addForm;
}

class addForm : public QWidget
{
    Q_OBJECT

public:
    explicit addForm(QWidget *parent = nullptr);
    ~addForm();

private slots:
    void on_exitButton_clicked();
    void on_addButton_clicked();
    void on_numEdit_textChanged(const QString &arg1);

private:
    Ui::addForm *ui;
};

#endif // ADDFORM_H

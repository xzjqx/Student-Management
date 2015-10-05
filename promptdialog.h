#ifndef PROMPTDIALOG_H
#define PROMPTDIALOG_H

#include <QDialog>

namespace Ui {
class promptDialog;
}

class promptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit promptDialog(QWidget *parent = 0);
    ~promptDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::promptDialog *ui;
};

#endif // PROMPTDIALOG_H

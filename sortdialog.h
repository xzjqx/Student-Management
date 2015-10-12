#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class sortDialog;
}

class sortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sortDialog(QWidget *parent = 0);
    ~sortDialog();

private slots:
    void on_zongheSButton_clicked();

    void on_zongheJButton_clicked();

    void on_xuefenSButton_clicked();

    void on_xuefenJButton_clicked();

private:
    Ui::sortDialog *ui;
};

#endif // SORTDIALOG_H

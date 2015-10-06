#ifndef SHOWSTUDIALOG_H
#define SHOWSTUDIALOG_H

#include <QDialog>

namespace Ui {
class showStuDialog;
}

class showStuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showStuDialog(QWidget *parent = 0);
    ~showStuDialog();

private:
    Ui::showStuDialog *ui;
};

#endif // SHOWSTUDIALOG_H

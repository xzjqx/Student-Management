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

private:
    Ui::sortDialog *ui;
};

#endif // SORTDIALOG_H

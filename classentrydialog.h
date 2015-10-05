#ifndef CLASSENTRYDIALOG_H
#define CLASSENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class classEntryDialog;
}

class classEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit classEntryDialog(QWidget *parent = 0);
    ~classEntryDialog();

private:
    Ui::classEntryDialog *ui;
};

#endif // CLASSENTRYDIALOG_H

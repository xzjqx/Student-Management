#ifndef GRADEENTRYDIALOG_H
#define GRADEENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class gradeEntryDialog;
}

class gradeEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gradeEntryDialog(QWidget *parent = 0);
    ~gradeEntryDialog();

private slots:
    void on_gradeCancelButton_clicked();

    void on_gradeSubmitButton_clicked();

private:
    Ui::gradeEntryDialog *ui;
};

#endif // GRADEENTRYDIALOG_H

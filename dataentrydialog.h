#ifndef DATAENTRYDIALOG_H
#define DATAENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class dataEntryDialog;
}

class dataEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dataEntryDialog(QWidget *parent = 0);
    ~dataEntryDialog();

private slots:
    void on_dataCancelButton_clicked();

    void on_dataSubmitButton_clicked();

private:
    Ui::dataEntryDialog *ui;
};

#endif // DATAENTRYDIALOG_H

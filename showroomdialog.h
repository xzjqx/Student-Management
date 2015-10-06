#ifndef SHOWROOMDIALOG_H
#define SHOWROOMDIALOG_H

#include <QDialog>

namespace Ui {
class showRoomDialog;
}

class showRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showRoomDialog(QWidget *parent = 0);
    ~showRoomDialog();

private:
    Ui::showRoomDialog *ui;
};

#endif // SHOWROOMDIALOG_H

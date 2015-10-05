#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include "stu.h"

namespace Ui {
class adminLoginDialog;
}

class adminLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminLoginDialog(QWidget *parent = 0);
    ~adminLoginDialog();

private slots:
    void on_loginButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::adminLoginDialog *ui;


};

extern STU_CLASS STU;
extern int isLogin;

#endif // ADMINLOGINDIALOG_H

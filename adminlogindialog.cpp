#include "stu.h"
#include "adminlogindialog.h"
#include "ui_adminlogindialog.h"

adminLoginDialog::adminLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员登录");
    this->setMaximumSize(284,151);
    this->setMinimumSize(284,151);
    STU.isLogin = 0;
}

adminLoginDialog::~adminLoginDialog()
{
    delete ui;
}

void adminLoginDialog::on_loginButton_clicked() {
    QString adminId, adminPsw;
    adminId = ui->adminIdLineEdit->text();
    adminPsw = ui->adminPswLineEdit->text();

    if (adminId == "") {
        QMessageBox::warning(this, tr("登录失败"), tr("管理员账号尚未填写"));
        this->close();
        return;
    }

    if (adminPsw == "") {
        QMessageBox::warning(this, tr("登录失败"), tr("管理员密码尚未填写"));
        this->close();
        return;
    }

    QSqlQuery query("SELECT account, password FROM admin");
    if (query.next()) {
        if (query.value(0) == adminId && query.value(1) == adminPsw) {
            STU.isLogin = 1;
            QMessageBox::information(this, tr("登录成功"), tr("登录成功，欢迎登录学生管理系统"));
            //QSqlQuery query1("SELECT * FROM student");
            this->close();
        }
        else {
            STU.isLogin = 0;
            QMessageBox::information(this, tr("登录失败"), tr("您提供的账号或密码错误，请检查后重新登录"));
            ui->adminPswLineEdit->setText("");
            return;
        }
    }
    else {
        STU.isLogin = 0;
        QMessageBox::warning(this, tr("登录失败"), tr("没有管理员账户"));
        return;
    }
}

void adminLoginDialog::on_cancelButton_clicked() {
    ui->adminIdLineEdit->setText("");
    ui->adminPswLineEdit->setText("");
    STU.isLogin = 2;
    this->close();
    return;
}

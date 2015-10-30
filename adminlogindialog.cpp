#include "stu.h"
#include "adminlogindialog.h"
#include "ui_adminlogindialog.h"

adminLoginDialog::adminLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员登录");//设置登录界面标题
    this->setMaximumSize(284,151);
    this->setMinimumSize(284,151);
    ui->adminPswLineEdit->setEchoMode(QLineEdit::Password);
    //设置登录界面大小不可变
    STU.isLogin = 0;//初始为未登录
}

adminLoginDialog::~adminLoginDialog()
{
    delete ui;
}

//点击登录按键的槽函数
void adminLoginDialog::on_loginButton_clicked() {
    QString adminId, adminPsw;
    adminId = ui->adminIdLineEdit->text();//记录管理员账号的String
    adminPsw = ui->adminPswLineEdit->text();//记录管理员密码的String

    if (adminId == "") {
        QMessageBox::warning(this, tr("登录失败"), tr("管理员账号尚未填写"));
        this->close();
        return;
    }//若未输入账号，弹出提示信息再转为重新输入

    if (adminPsw == "") {
        QMessageBox::warning(this, tr("登录失败"), tr("管理员密码尚未填写"));
        this->close();
        return;
    }//若未输入密码，弹出提示信息再转为重新输入

    QSqlQuery query("SELECT account, password FROM admin");//查询管理员数据库
    if(!STU.isConnect) {
        STU.isLogin = 2;
        QMessageBox::information(this, tr("登录失败"), tr("未连接上数据库"));
        this->close();
    }//若未连上数据库直接显示未连接数据库
    else {
        if (query.next() && STU.isConnect) {
            if (query.value(0) == adminId && query.value(1) == adminPsw) {
                STU.isLogin = 1;
                QMessageBox::information(this, tr("登录成功"), tr("登录成功，欢迎登录学生管理系统"));
                this->close();
            }//若连上数据库且账号密码对了，则登入主界面
            else {
                STU.isLogin = 0;
                QMessageBox::information(this, tr("登录失败"), tr("您提供的账号或密码错误，请检查后重新登录"));
                ui->adminPswLineEdit->setText("");
                return;
            }//否则重新登录
        }
        else {
            STU.isLogin = 0;
            QMessageBox::warning(this, tr("登录失败"), tr("没有管理员账户"));
            return;
        }//若数据库中一条信息也未找到，则弹出信息没有管理员
    }
}

//点击取消按键的槽函数
void adminLoginDialog::on_cancelButton_clicked() {
    ui->adminIdLineEdit->setText("");
    ui->adminPswLineEdit->setText("");
    STU.isLogin = 3;
    this->close();
    return;
}

#include "stu.h"
#include "checkdialog.h"
#include "ui_checkdialog.h"
#include "showroomdialog.h"
#include "showstudialog.h"

checkDialog::checkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkDialog)
{
    ui->setupUi(this);
    this->setMaximumSize(306,199);
    this->setMinimumSize(306,199);
    //设置窗口大小不可变
}

checkDialog::~checkDialog()
{
    delete ui;
}

//点击取消按键的槽函数
void checkDialog::on_dialogCancelButton_clicked()
{
    this->close();//关闭窗口
}

//点击查询按键的槽函数
void checkDialog::on_dialogCheckButton_clicked()
{
    QString stuId, stuName, stuRoom;
    stuId = ui->stuIdLineEdit->text();
    stuName = ui->stuNameLineEdit->text();
    stuRoom = ui->stuRoomLineEdit->text();
    //记录信息

    if ((stuId == "" || stuName == "") && stuRoom == ""){
        QMessageBox::warning(this, tr("查询失败"), tr("请完整填写学号姓名或者填写宿舍号"));
        return;
    }//若未写入账号密码且未写入宿舍号，则弹出提示信息并重新输入

    if(stuRoom != "") {
        QSqlQuery query;
        query.prepare("SELECT * FROM student where stuRoom = :room ORDER BY stuId");
        query.bindValue(":room", stuRoom);
        query.exec();
        //SQL查询该宿舍下的成员
        int i = 0;
        while(query.next()) {
            STU.room[i][0] = query.value(0).toString();
            STU.room[i][1] = query.value(1).toString();
            STU.room[i][2] = query.value(2).toString();
            STU.room[i][3] = query.value(3).toString();
            i++;
        }//将成员信息记录下来
        if(i == 0) {
            QMessageBox::warning(this, tr("查询失败"), tr("没有该宿舍信息"));
            return;
        }//若一条信息也没有，直接输出错误信息
        this->close();
        showRoomDialog *dia = new showRoomDialog;
        dia->show();
    }//若写入宿舍号，直接打开宿舍成员信息显示界面
    else {
        QSqlQuery query;
        query.prepare("SELECT * FROM student where stuId = :id && stuName = :name");
        query.bindValue(":id", stuId);
        query.bindValue(":name", stuName);
        query.exec();
        //SQL查询学生信息
        int i = 0;
        while(query.next()) {
            //qDebug() << i;
            STU.s[0] = query.value(0).toString();
            STU.s[1] = query.value(1).toString();
            STU.s[2] = query.value(2).toString();
            STU.s[3] = query.value(3).toString();
            i++;
        }//将查到的信息保存下来
        if(i == 0) {
            QMessageBox::warning(this, tr("查询失败"), tr("没有该学生信息"));
            return;
        }//若未找到，弹出错误信息
        this->close();
        showStuDialog *dia = new showStuDialog;
        dia->show();
    }//否则查询学生信息并显示
}

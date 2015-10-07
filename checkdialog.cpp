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
}

checkDialog::~checkDialog()
{
    delete ui;
}

void checkDialog::on_dialogCancelButton_clicked()
{
    this->close();
}

void checkDialog::on_dialogCheckButton_clicked()
{
    QString stuId, stuName, stuRoom;
    stuId = ui->stuIdLineEdit->text();
    stuName = ui->stuNameLineEdit->text();
    stuRoom = ui->stuRoomLineEdit->text();

    if ((stuId == "" || stuName == "") && stuRoom == ""){
        QMessageBox::warning(this, tr("查询失败"), tr("请完整填写学号姓名或者填写宿舍号"));
        return;
    }

    if(stuRoom != "") {
        QSqlQuery query;
        query.prepare("SELECT * FROM student where stuRoom = :room ORDER BY stuId");
        query.bindValue(":room", stuRoom);
        query.exec();
        int i = 0;
        while(query.next()) {
            STU.room[i][0] = query.value(0).toString();
            STU.room[i][1] = query.value(1).toString();
            STU.room[i][2] = query.value(2).toString();
            STU.room[i][3] = query.value(3).toString();
            i++;
        }
        if(i == 0) {
            QMessageBox::warning(this, tr("查询失败"), tr("没有该宿舍信息"));
            return;
        }
        this->close();
        showRoomDialog *dia = new showRoomDialog;
        dia->show();
    }
    else {
        QSqlQuery query;
        query.prepare("SELECT * FROM student where stuId = :id && stuName = :name");
        query.bindValue(":id", stuId);
        query.bindValue(":name", stuName);
        query.exec();
        int i = 0;
        while(query.next()) {
            //qDebug() << i;
            STU.s[0] = query.value(0).toString();
            STU.s[1] = query.value(1).toString();
            STU.s[2] = query.value(2).toString();
            STU.s[3] = query.value(3).toString();
            i++;
        }
        if(i == 0) {
            QMessageBox::warning(this, tr("查询失败"), tr("没有该学生信息"));
            return;
        }
        this->close();
        showStuDialog *dia = new showStuDialog;
        dia->show();
    }
}

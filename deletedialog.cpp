#include "stu.h"
#include "deletedialog.h"
#include "ui_deletedialog.h"

deleteDialog::deleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("删除学生信息");
}

deleteDialog::~deleteDialog()
{
    delete ui;
}

//点击确定按键的槽函数
void deleteDialog::on_submitButton_clicked()
{
    QString stuId, stuName;
    stuId = ui->stuIdLineEdit->text();
    stuName = ui->stuNameLineEdit->text();
    //记录填入的数据

    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE stuId = :i");
    query.bindValue(":i", stuId);
    query.exec();
    //SQL查询语句，查询数据库中是否有该学生
    if(!query.next()) {
        QMessageBox::warning(this, tr("删除失败"), tr("未找到该学生信息"));
        return;
    }//若未查到信息，则提示错误信息

    query.prepare("DELETE FROM student WHERE stuId = :i && stuName = :n");
    query.bindValue(":i", stuId);
    query.bindValue(":n", stuName);
    query.exec();
    //SQL删除语句，删除指定学生的基本信息
    query.prepare("DELETE FROM grades WHERE stuId = :i");
    query.bindValue(":i", stuId);
    query.exec();
    //SQL删除语句，删除指定学生的分数信息

    QMessageBox::warning(this, tr("删除成功"), tr("已删除该学生全部信息"));
    this->close();
}

//点击取消按键的槽函数
void deleteDialog::on_cancelButton_clicked()
{
    this->close();
}

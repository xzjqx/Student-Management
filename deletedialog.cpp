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

void deleteDialog::on_submitButton_clicked()
{
    QString stuId, stuName;
    stuId = ui->stuIdLineEdit->text();
    stuName = ui->stuNameLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE stuId = :i");
    query.bindValue(":i", stuId);
    query.exec();
    if(!query.next()) {
        QMessageBox::warning(this, tr("删除失败"), tr("未找到该学生信息"));
        return;
    }

    query.prepare("DELETE FROM student WHERE stuId = :i && stuName = :n");
    query.bindValue(":i", stuId);
    query.bindValue(":n", stuName);
    query.exec();

    query.prepare("DELETE FROM grades WHERE stuId = :i");
    query.bindValue(":i", stuId);
    query.exec();

    QMessageBox::warning(this, tr("删除成功"), tr("已删除该学生全部信息"));
    this->close();
}

void deleteDialog::on_cancelButton_clicked()
{
    this->close();
}

#include "stu.h"
#include "sortdialog.h"
#include "ui_sortdialog.h"

sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("学生课程排序");
    //设置窗口标题
}

sortDialog::~sortDialog()
{
    delete ui;
}

//点击按综合成绩升序的槽函数
void sortDialog::on_zongheSButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();
    //记录填入学生信息

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }
    //若某些信息没有填入，则提示错误信息

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY zonghechengji");
    query.bindValue(":i", id);
    query.exec();
    //SQL查询排序语句，在查询的过程中按要求排序
    int i = 0;
    while(query.next()) {
        //qDebug() << i;
        ui->tableWidget->setRowCount(i + 1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(query.value(6).toString()));
        i++;
    }
}

void sortDialog::on_zongheJButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();
    //记录填入学生信息

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }
    //若某些信息没有填入，则提示错误信息

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY zonghechengji DESC");
    query.bindValue(":i", id);
    query.exec();
    //SQL查询排序语句，在查询的过程中按要求排序
    int i = 0;
    while(query.next()) {
        //qDebug() << i;
        ui->tableWidget->setRowCount(i + 1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(query.value(6).toString()));
        i++;
    }
}

void sortDialog::on_xuefenSButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();
    //记录填入学生信息

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }
    //若某些信息没有填入，则提示错误信息

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY shidexuefen");
    query.bindValue(":i", id);
    query.exec();
    //SQL查询排序语句，在查询的过程中按要求排序
    int i = 0;
    while(query.next()) {
        //qDebug() << i;
        ui->tableWidget->setRowCount(i + 1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(query.value(6).toString()));
        i++;
    }
}

void sortDialog::on_xuefenJButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();
    //记录填入学生信息

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }
    //若某些信息没有填入，则提示错误信息

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY shidexuefen DESC");
    query.bindValue(":i", id);
    query.exec();
    //SQL查询排序语句，在查询的过程中按要求排序
    int i = 0;
    while(query.next()) {
        //qDebug() << i;
        ui->tableWidget->setRowCount(i + 1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(query.value(6).toString()));
        i++;
    }
}

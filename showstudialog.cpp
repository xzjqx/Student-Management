#include "stu.h"
#include "showstudialog.h"
#include "ui_showstudialog.h"

showStuDialog::showStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showStuDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("显示该生基本信息");
    //设置窗口标题
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置TableWidget不可编辑

    ui->stuIdLabel->setText(STU.s[0]);
    ui->stuNameLabel->setText(STU.s[1]);
    ui->stuRoomLabel->setText(STU.s[2]);
    ui->stuSexLabel->setText(STU.s[3]);
    //设置显示信息

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :id");
    query.bindValue(":id", STU.s[0]);
    query.exec();
    //SQL查询语句
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
    }//循环将查询到的该生成绩信息显示在TableWidget中
}

showStuDialog::~showStuDialog()
{
    delete ui;
}

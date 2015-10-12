#include "stu.h"
#include "showstudialog.h"
#include "ui_showstudialog.h"

showStuDialog::showStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showStuDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("显示该生基本信息");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->stuIdLabel->setText(STU.s[0]);
    ui->stuNameLabel->setText(STU.s[1]);
    ui->stuRoomLabel->setText(STU.s[2]);
    ui->stuSexLabel->setText(STU.s[3]);

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :id");
    query.bindValue(":id", STU.s[0]);
    query.exec();
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

showStuDialog::~showStuDialog()
{
    delete ui;
}

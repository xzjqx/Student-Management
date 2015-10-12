#include "stu.h"
#include "sortdialog.h"
#include "ui_sortdialog.h"

sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("学生课程排序");
}

sortDialog::~sortDialog()
{
    delete ui;
}


void sortDialog::on_zongheSButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY zonghechengji");
    query.bindValue(":i", id);
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

void sortDialog::on_zongheJButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY zonghechengji DESC");
    query.bindValue(":i", id);
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

void sortDialog::on_xuefenSButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY shidexuefen");
    query.bindValue(":i", id);
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

void sortDialog::on_xuefenJButton_clicked()
{
    QString id, name;
    id = ui->stuIdLineEdit->text();
    name = ui->stuNameLineEdit->text();

    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入学号"));
        return;
    }
    if( id == "" ){
        QMessageBox::warning(this, tr("无法排序"), tr("未输入姓名"));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM grades WHERE stuId = :i ORDER BY shidexuefen DESC");
    query.bindValue(":i", id);
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

#include "studentmanagement.h"
#include "ui_studentmanagement.h"
#include "selectdialog.h"
#include "deletedialog.h"
#include "sortdialog.h"
#include <QSplashScreen>
#include <QPixmap>

StudentManagement::StudentManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentManagement)
{
    ui->setupUi(this);
    this->setMaximumSize(546,392);
    this->setMinimumSize(546,392);
    ui->infoTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->infoTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QSqlQuery query("SELECT * FROM student ORDER BY stuId");
    STU.index = 0;

    while( query.next() ) {
        ui->infoTableWidget->setRowCount(STU.index + 1);
        ui->infoTableWidget->setItem(STU.index, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->infoTableWidget->setItem(STU.index, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->infoTableWidget->setItem(STU.index, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->infoTableWidget->setItem(STU.index, 3, new QTableWidgetItem(query.value(3).toString()));
        STU.index ++;
    }
}

StudentManagement::~StudentManagement()
{
    delete ui;
}

void StudentManagement::on_checkButton_clicked()
{
    checkDialog *dia = new checkDialog(this);
    dia->setWindowTitle("查询学生信息");
    dia->show();
}


void StudentManagement::on_pushButton_2_clicked()
{
    STU.index = 0;
    QSqlQuery que("SELECT * FROM student ORDER BY stuId");
    while( que.next() ) {
        ui->infoTableWidget->setRowCount(STU.index + 1);
        ui->infoTableWidget->setItem(STU.index, 0, new QTableWidgetItem(que.value(0).toString()));
        ui->infoTableWidget->setItem(STU.index, 1, new QTableWidgetItem(que.value(1).toString()));
        ui->infoTableWidget->setItem(STU.index, 2, new QTableWidgetItem(que.value(2).toString()));
        ui->infoTableWidget->setItem(STU.index, 3, new QTableWidgetItem(que.value(3).toString()));
        STU.index ++;
    }
}

void StudentManagement::on_dataButton_clicked()
{
    selectDialog *dia = new selectDialog;
    dia->show();
}

void StudentManagement::on_deleteButton_clicked()
{
    deleteDialog *dia = new deleteDialog;
    dia->show();
}

void StudentManagement::on_sortButton_clicked()
{
    sortDialog *dia = new sortDialog;
    dia->show();
}

#include "stu.h"
#include "studentmanagement.h"
#include "ui_studentmanagement.h"
#include "selectdialog.h"
#include "deletedialog.h"
#include "sortdialog.h"
#include "showstudialog.h"
#include <QSplashScreen>
#include <QPixmap>

StudentManagement::StudentManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentManagement)
{
    ui->setupUi(this);
    this->setMaximumSize(546,392);
    this->setMinimumSize(546,392);
    //设置主界面大小不可变
    ui->infoTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置TableWidget为选中整行
    ui->infoTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置TableWidget为不可编辑

    if( !STU.isAdminLogin() ) {//若未连上数据库，则设置按键不可用
        ui->checkButton->setEnabled(false);
        ui->dataButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->sortButton->setEnabled(false);
    }
    else {//若成功登陆，则刷新TableWidget并默认使按键可用
        QSqlQuery query("SELECT * FROM student ORDER BY stuId");//SQL查询语句
        STU.index = 0;
        while( query.next() ) {
            ui->infoTableWidget->setRowCount(STU.index + 1);
            ui->infoTableWidget->setItem(STU.index, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->infoTableWidget->setItem(STU.index, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->infoTableWidget->setItem(STU.index, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->infoTableWidget->setItem(STU.index, 3, new QTableWidgetItem(query.value(3).toString()));
            STU.index ++;
        }//循环在TableWidget插入数据
    }

}

StudentManagement::~StudentManagement()
{
    delete ui;
}

//点击查询按键后相应的槽函数
void StudentManagement::on_checkButton_clicked()
{
    checkDialog *dia = new checkDialog(this);
    dia->setWindowTitle("查询学生信息");
    dia->show();
    //打开查询学生信息界面
}

//点击数据录入按键后相应的槽函数
void StudentManagement::on_dataButton_clicked()
{
    selectDialog *dia = new selectDialog;
    dia->show();
    //打开选择要录入的信息的界面
}

//点击删除按键后相应的槽函数
void StudentManagement::on_deleteButton_clicked()
{
    deleteDialog *dia = new deleteDialog;
    dia->show();
    //打开删除界面
}

//点击排序按键后的槽函数
void StudentManagement::on_sortButton_clicked()
{
    sortDialog *dia = new sortDialog;
    dia->show();
    //打开排序界面
}

//设置双击TableWidget中的项相应的槽函数
void StudentManagement::on_infoTableWidget_cellDoubleClicked(int row, int column)
{
    STU.s[0] = ui->infoTableWidget->item(row, 0)->text();
    STU.s[1] = ui->infoTableWidget->item(row, 1)->text();
    STU.s[2] = ui->infoTableWidget->item(row, 2)->text();
    STU.s[3] = ui->infoTableWidget->item(row, 3)->text();
    //将点击的行信息保存在全局变量中
    showStuDialog *dia = new showStuDialog;
    dia->show();
    //打开显示学生具体信息的界面，并将上述点击的学生具体信息显示出来
}

//点击刷新按键后相应的槽函数
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
    }//循环将信息重新插入TableWidget中
}

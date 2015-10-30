#include "stu.h"
#include "showroomdialog.h"
#include "ui_showroomdialog.h"
#include "showstudialog.h"

showRoomDialog::showRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showRoomDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("显示该宿舍学生基本信息");
    //设置窗口标题
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置TableWidget不可编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置TableWidget整行选中
    ui->tableWidget->setRowCount(4);
    //设置TableWidget行数为4
    ui->susheLabel->setText(STU.room[0][2]);
    //设置显示宿舍号
    for(int i = 0; i < 4; i ++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(STU.room[i][0]));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(STU.room[i][1]));
        //ui->tableWidget->setItem(i, 2, new QTableWidgetItem(STU.room[i][2]));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(STU.room[i][3]));
    }//将宿舍成员信息显示在TableWidget中
}

showRoomDialog::~showRoomDialog()
{
    delete ui;
}

//设置双击TableWidget的槽函数
void showRoomDialog::on_tableWidget_cellDoubleClicked(int row, int column)
{
    STU.s[0] = ui->tableWidget->item(row, 0)->text();
    STU.s[1] = ui->tableWidget->item(row, 1)->text();
    STU.s[3] = ui->tableWidget->item(row, 2)->text();
    STU.s[2] = STU.room[0][2];
    //将点击行的信息存下来

    showStuDialog *dia = new showStuDialog;
    dia->show();
    //打开显示学生具体信息的界面，并将以上具体信息显示出来
}

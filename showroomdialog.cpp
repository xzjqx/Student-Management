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
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //qDebug() << STU.room[0][0];
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(4);
    ui->susheLabel->setText(STU.room[0][2]);
    for(int i = 0; i < 4; i ++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(STU.room[i][0]));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(STU.room[i][1]));
        //ui->tableWidget->setItem(i, 2, new QTableWidgetItem(STU.room[i][2]));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(STU.room[i][3]));
    }
}

showRoomDialog::~showRoomDialog()
{
    delete ui;
}

void showRoomDialog::on_tableWidget_cellDoubleClicked(int row, int column)
{
    STU.s[0] = ui->tableWidget->item(row, 0)->text();
    STU.s[1] = ui->tableWidget->item(row, 1)->text();
    STU.s[3] = ui->tableWidget->item(row, 2)->text();
    STU.s[2] = STU.room[0][2];

    showStuDialog *dia = new showStuDialog;
    dia->show();
}

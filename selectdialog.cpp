#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "dataentrydialog.h"
#include "classentrydialog.h"
#include "gradeentrydialog.h"

selectDialog::selectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("选择信息");
    //设置窗口标题
    this->setMaximumSize(306,105);
    this->setMinimumSize(306,105);
    //设置窗口大小不可变
}

selectDialog::~selectDialog()
{
    delete ui;
}

//点击学生信息的槽函数
void selectDialog::on_stuDataButton_clicked()
{
    this->close();
    dataEntryDialog *dia = new dataEntryDialog;
    dia->show();
    //打开录入学生信息的界面
}

//点击课程信息的槽函数
void selectDialog::on_classDataButton_clicked()
{
    this->close();
    classEntryDialog *dia = new classEntryDialog;
    dia->show();
    //打开录入课程信息的界面
}

//点击成绩信息的槽函数
void selectDialog::on_gradeDataButton_clicked()
{
    this->close();
    gradeEntryDialog *dia = new gradeEntryDialog;
    dia->show();
    //打开录入成绩信息的界面
}

#include "stu.h"
#include "promptdialog.h"
#include "ui_promptdialog.h"
#include "gradeentrydialog.h"

promptDialog::promptDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promptDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("提示信息");
    this->setMaximumSize(347,121);
    this->setMinimumSize(347,121);
}

promptDialog::~promptDialog()
{
    delete ui;
}

void promptDialog::on_pushButton_2_clicked()
{
    this->close();
}

void promptDialog::on_pushButton_clicked()
{
    gradeEntryDialog *dia = new gradeEntryDialog;
    this->close();
    dia->show();
}

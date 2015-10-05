#include "stu.h"
#include "checkdialog.h"
#include "ui_checkdialog.h"

checkDialog::checkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkDialog)
{
    ui->setupUi(this);
    this->setMaximumSize(306,199);
    this->setMinimumSize(306,199);
}

checkDialog::~checkDialog()
{
    delete ui;
}

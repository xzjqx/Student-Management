#include "stu.h"
#include "classentrydialog.h"
#include "ui_classentrydialog.h"

classEntryDialog::classEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classEntryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("课程信息录入");
    this->setMaximumSize(247,142);
    this->setMinimumSize(247,142);
}

classEntryDialog::~classEntryDialog()
{
    delete ui;
}

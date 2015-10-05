#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "dataentrydialog.h"
#include "classentrydialog.h"

selectDialog::selectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("选择信息");
    this->setMaximumSize(306,105);
    this->setMinimumSize(306,105);
}

selectDialog::~selectDialog()
{
    delete ui;
}

void selectDialog::on_stuDataButton_clicked()
{
    this->close();
    dataEntryDialog *dia = new dataEntryDialog;
    dia->show();
}

void selectDialog::on_classDataButton_clicked()
{
    this->close();
    classEntryDialog *dia = new classEntryDialog;
    dia->show();
}

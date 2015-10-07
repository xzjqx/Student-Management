#include "sortdialog.h"
#include "ui_sortdialog.h"

sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
}

sortDialog::~sortDialog()
{
    delete ui;
}


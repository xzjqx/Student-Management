#include "stu.h"
#include "dataentrydialog.h"
#include "ui_dataentrydialog.h"
#include "promptdialog.h"

dataEntryDialog::dataEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataEntryDialog)
{
    ui->setupUi(this);
    this->setMaximumSize(325,191);
    this->setMinimumSize(325,191);
    this->setWindowTitle("学生信息录入");
}

dataEntryDialog::~dataEntryDialog()
{
    delete ui;
}


void dataEntryDialog::on_dataCancelButton_clicked()
{
    this->close();
}

void dataEntryDialog::on_dataSubmitButton_clicked()
{
    //STU.isDataCancel = 0;
    QString dataId, dataName, dataRoom, dataSex;
    dataId = ui->dataIdLineEdit->text();
    dataName = ui->dataNameLineEdit->text();
    dataRoom = ui->dataRoomLineEdit->text();
    dataSex = ui->dataSexLineEdit->text();
    int haveStuInfo = 0;
    int index = 0;
    STU.id = dataId;

    if (dataId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生学号尚未填写"));
        return;
    }
    if (dataName == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生姓名尚未填写"));
        return;
    }
    if (dataRoom == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生宿舍号尚未填写"));
        return;
    }
    if (dataSex == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生性别尚未填写"));
        return;
    }

    QSqlQuery query("SELECT * FROM student");
    while( query.next() ) {
        if(dataId == query.value(index).toString()) {
            STU.id = query.value(index).toString();
            haveStuInfo = 1;
            break;
        }
        index ++;
    }
    if( !haveStuInfo ) {
        query.prepare("INSERT INTO `studentmanagement`.`student` (`stuId`, `stuName`, `stuRoom`, `stuSex`) VALUES (:id, :name, :room, :sex);");
        query.bindValue(":id", dataId);
        query.bindValue(":name", dataName);
        query.bindValue(":room", dataRoom);
        query.bindValue(":sex", dataSex);
        query.exec();
    }
    this->close();
    promptDialog *dia = new promptDialog;
    dia->show();
}

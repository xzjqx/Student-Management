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

//点击取消按键的槽函数
void dataEntryDialog::on_dataCancelButton_clicked()
{
    this->close();
}

//点击确定按键的槽函数
void dataEntryDialog::on_dataSubmitButton_clicked()
{
    QString dataId, dataName, dataRoom, dataSex;
    dataId = ui->dataIdLineEdit->text();
    dataName = ui->dataNameLineEdit->text();
    dataRoom = ui->dataRoomLineEdit->text();
    dataSex = ui->dataSexLineEdit->text();
    //记录填入数据
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
    //若某些信息没有填入，则提示错误信息

    QSqlQuery query("SELECT * FROM student");//SQL查询语句
    while( query.next() ) {
        if(dataId == query.value(0).toString()) {
            STU.id = query.value(0).toString();
            haveStuInfo = 1;//若查到填入的学生学号，则记录下来
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
        //SQL插入语句
        this->close();
        QMessageBox::warning(this, tr("录入成功"), tr("该生信息已在后台数据库中"));
    }//若未在数据库中查到新填写的学生，则插入新学生信息
    else {
        ui->dataIdLineEdit->setText("");
        ui->dataNameLineEdit->setText("");
        ui->dataRoomLineEdit->setText("");
        ui->dataSexLineEdit->setText("");
        QMessageBox::warning(this, tr("录入失败"), tr("数据库中已有该学生信息，无需再次录入"));
    }//否则提示错误信息并重新输入

}

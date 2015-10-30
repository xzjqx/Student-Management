#include "stu.h"
#include "classentrydialog.h"
#include "ui_classentrydialog.h"

classEntryDialog::classEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classEntryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("课程信息录入");
    //设置窗口标题
    this->setMaximumSize(246,177);
    this->setMinimumSize(246,177);
    //设置窗口大小不可变
}

classEntryDialog::~classEntryDialog()
{
    delete ui;
}

//点击取消按键的槽函数
void classEntryDialog::on_classCancelButton_clicked()
{
    this->close();
}

//点击确定按键的槽函数
void classEntryDialog::on_classSubmitButton_clicked()
{
    QString classId, className, classXuefen;
    classId = ui->classIdLineEdit->text();
    className = ui->classNameLineEdit->text();
    classXuefen = ui->classXuefenLineEdit->text();
    //记录填写的信息

    if (classId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("课程编号尚未填写"));
        return;
    }
    if (className == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("课程名称尚未填写"));
        return;
    }
    if (classXuefen == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("课程学分尚未填写"));
        return;
    }
    //若某些信息没有填入，则提示错误信息

    int haveClassInfo = 0;
    QSqlQuery query("SELECT * FROM class");//SQL查询语句
    while( query.next() ) {
        if(classId == query.value(0).toString()) {
            //STU.id = query.value(0).toString();
            haveClassInfo = 1;//若查到填入的课程编号，则记录下来
            break;
        }
    }

    if(!haveClassInfo) {
        query.prepare("INSERT INTO `class`(`id`, `name`, `credit`) VALUES (:cid,:cname,:x)");
        query.bindValue(":cid", classId);
        query.bindValue(":cname", className);
        query.bindValue(":x", classXuefen.toDouble());
        query.exec();
        //SQL插入语句
        this->close();
        QMessageBox::warning(this, tr("录入成功"), tr("该课程信息已录入后台数据库"));
    }//若未在数据库中查到新填写的课程，则插入新课程
    else {
        ui->classIdLineEdit->setText("");
        ui->classNameLineEdit->setText("");
        ui->classXuefenLineEdit->setText("");
        QMessageBox::warning(this, tr("录入失败"), tr("数据库中已有该课程信息，无需再次录入"));
    }//否则提示错误信息并重新输入
}

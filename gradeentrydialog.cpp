#include "stu.h"
#include "gradeentrydialog.h"
#include "ui_gradeentrydialog.h"

gradeEntryDialog::gradeEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gradeEntryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("录入学生课程分数");
    this->setMaximumSize(295,241);
    this->setMinimumSize(295,241);
    //ui->showIdLabel->setText(STU.id);
}

gradeEntryDialog::~gradeEntryDialog()
{
    delete ui;
}

void gradeEntryDialog::on_gradeCancelButton_clicked()
{
    this->close();
}

void gradeEntryDialog::on_gradeSubmitButton_clicked()
{
    QString stuId, classId, pingshi, shiyan, juanmian;
    stuId = ui->stuIdLineEdit->text();
    classId = ui->classIdLineEdit->text();
    pingshi = ui->pingshiLineEdit->text();
    shiyan = ui->shiyanLineEdit->text();
    juanmian = ui->juanmianLineEdit->text();
    bool flag = 0;

    if (stuId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生学号尚未填写"));
        return;
    }
    if (classId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("课程编号尚未填写"));
        return;
    }
    if (pingshi == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("平时成绩尚未填写"));
        return;
    }
    if (shiyan == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("实验成绩尚未填写"));
        return;
    }
    if (juanmian == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("卷面成绩尚未填写"));
        return;
    }

    QSqlQuery query("SELECT id FROM class");
    while(query.next()) {
        if(classId == query.value(0).toString()) {
            flag = 1;
            break;
        }
    }

    if(!flag) {
        this->close();
        QMessageBox::warning(this, tr("无该编号课程"), tr("请前往课程信息录入项录入该课程信息"));
        return;
    }
    else {
        double zonghe = 0, xuefen;
        query.prepare("SELECT * FROM class where id = :i");
        query.bindValue(":i", classId);
        query.exec();
        //qDebug() << xuefen;
        query.next();
        xuefen = query.value(2).toDouble();
        //qDebug() << xuefen;
        if( shiyan.toDouble() == -1 )
            zonghe = pingshi.toDouble()*0.3 + juanmian.toDouble()*0.7;
        else
            zonghe = pingshi.toDouble()*0.15 + shiyan.toDouble()*0.15 + juanmian.toDouble()*0.7;
        if(zonghe >= 90)
            xuefen = 1.0*xuefen;
        else if(zonghe >= 80)
            xuefen *= 0.8;
        else if(zonghe >= 70)
            xuefen *= 0.75;
        else if(zonghe >= 60)
            xuefen *= 0.6;
        else
            xuefen = 0;
        //qDebug() << xuefen;

        query.prepare("INSERT INTO `studentmanagement`.`grades` (`stuId`,`classId`,`pingshichengji`,`shiyanchengji`,`juanmianchengji`,`zonghechengji`,`shidexuefen`) VALUES (:id,:id2,:p,:s,:j,:z,:x);");
        query.bindValue(":id", stuId);
        query.bindValue(":id2", classId);
        query.bindValue(":p", pingshi.toDouble());
        query.bindValue(":s", shiyan.toDouble());
        query.bindValue(":j", juanmian.toDouble());
        query.bindValue(":z", zonghe);
        query.bindValue(":x", xuefen);
        query.exec();
        this->close();
        QMessageBox::warning(this, tr("录入成功"), tr("该生成绩已录入后台数据库"));
    }
}

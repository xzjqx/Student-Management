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

    QStringList strings;
    QSqlQuery query("SELECT id FROM class ORDER BY id");
    while(query.next()) {
        QString str = query.value(0).toString();
        strings.append(str);
    }
    ui->classIdComboBox->clear();
    ui->classIdComboBox->addItems(strings);
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
    classId = ui->classIdComboBox->currentText();
    pingshi = ui->pingshiLineEdit->text();
    shiyan = ui->shiyanLineEdit->text();
    juanmian = ui->juanmianLineEdit->text();

    if (stuId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("学生学号尚未填写"));
        return;
    }
    /*if (classId == "") {
        QMessageBox::warning(this, tr("录入失败"), tr("课程编号尚未填写"));
        return;
    }*/
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

    QSqlQuery query;
    double zonghe = 0, xuefen;
    QString Szonghe, Sxuefen;
    query.prepare("SELECT * FROM class where id = :i");
    query.bindValue(":i", classId);
    query.exec();
    query.next();
    xuefen = query.value(2).toDouble();

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
    Szonghe = QString::number(zonghe, 'f', 1);
    Sxuefen = QString::number(xuefen, 'f', 1);

    query.prepare("INSERT INTO `studentmanagement`.`grades` (`stuId`,`classId`,`pingshichengji`,`shiyanchengji`,`juanmianchengji`,`zonghechengji`,`shidexuefen`) VALUES (:id,:id2,:p,:s,:j,:z,:x);");
    query.bindValue(":id", stuId);
    query.bindValue(":id2", classId);
    query.bindValue(":p", pingshi);
    query.bindValue(":s", shiyan);
    query.bindValue(":j", juanmian);
    query.bindValue(":z", Szonghe);
    query.bindValue(":x", Sxuefen);
    query.exec();
    this->close();
    QMessageBox::warning(this, tr("录入成功"), tr("该生成绩已录入后台数据库"));

}

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
    ui->showIdLabel->setText(STU.id);
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
    QString classId, pingshi, shiyan, juanmian;
    classId = ui->classIdLineEdit->text();
    pingshi = ui->pingshiLineEdit->text();
    shiyan = ui->shiyanLineEdit->text();
    juanmian = ui->juanmianLineEdit->text();
    bool flag = 0;

    QSqlQuery query("SELECT id FROM class");
    while(query.next()) {
        if(classId == query.value(0).toString()) {
            flag = 1;
            break;
        }
    }

    if(!flag) {
        QMessageBox::warning(this, tr("无该编号课程"), tr("请前往课程信息录入项录入该课程信息"));
        return;
    }
    else {
        double zonghe = 0, xuefen;
        query.prepare("SELECT * FROM class where id = :i");
        query.bindValue(":i", classId);
        xuefen = query.value(2).toDouble();
        query.prepare("INSERT INTO `studentmanagement`.`grades` (`stuId`,`classId`,`pingshichengji`,`shiyanchengji`,`juanmianchengji`,`zonghechengji`,`shidexuefen`) VALUES (:id,:id2,:p,:s,:j,:z,:x);");
        query.bindValue(":id", STU.id);
        query.bindValue(":id2", classId);
        query.bindValue(":p", pingshi.toDouble());
        query.bindValue(":s", shiyan.toDouble());
        query.bindValue(":j", juanmian.toDouble());
        query.bindValue(":z", zonghe);
        query.bindValue(":x", xuefen);
        query.exec();
        this->close();
    }
}

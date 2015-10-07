#include "studentmanagement.h"
#include "stu.h"
#include <QApplication>

using namespace std;

STU_CLASS STU;

int main(int argc, char *argv[])
{
    STU.init_database();
    //qDebug() << STU.isConnect;
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("D:/Software practice/Student/233.jpg"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading into the main window..."),topRight,Qt::red);

    StudentManagement w;
    splash->showMessage(QObject::tr("Loading modules..."),topRight,Qt::yellow);
    for(int i = 0; i < 300000000; i++);
    splash->showMessage(QObject::tr("Establishing connections..."),topRight,Qt::green);
    for(int i = 0; i < 300000000; i++);

    splash->finish(&w);
    delete splash;

    adminLoginDialog *log = new adminLoginDialog;
    log->exec();
    for( ; ; ) {
        if( STU.isLogin == 1 ) {
            w.show();
            return a.exec();
        }
        else if( STU.isLogin == 2 ) {
            return a.exec();
        }
        else {
            log = new adminLoginDialog;
            log->exec();
        }
    }
}

void STU_CLASS::init_database() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanagement");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        STU.isConnect = 0;
        //QMessageBox::warning(log, tr("Warning!!!"), tr("连接数据库出现问题！"));
        //this->close();
    }
    else {
        STU.isConnect = 1;
        //QMessageBox::warning(adminLoginDialog, tr("恭喜你"), tr("成功连接上数据库！"));
        //this->close();
    }
}


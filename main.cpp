#include "studentmanagement.h"
#include "stu.h"
#include <QApplication>

using namespace std;

STU_CLASS STU;
//全局变量

//main函数
int main(int argc, char *argv[])
{
    QApplication::addLibraryPath(".");

    STU.init_database();//初始化连接数据库
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;//在打开窗口前使用一个SplashScreen动画
    splash->setPixmap(QPixmap(":/new/prefix1/233.jpg"));//设置图片
    splash->show();//显示动画
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading into the main window..."),topRight,Qt::red);
    //设置文字在右上角

    StudentManagement w;//新建主窗口
    splash->showMessage(QObject::tr("Loading modules..."),topRight,Qt::yellow);
    for(int i = 0; i < 300000000; i++);//延时效果
    splash->showMessage(QObject::tr("Establishing connections..."),topRight,Qt::green);
    for(int i = 0; i < 300000000; i++);//延时效果

    splash->finish(&w);
    delete splash;//动画结束

    adminLoginDialog *log = new adminLoginDialog;
    log->exec();//打开登录界面
    for( ; ; ) {//使用循环不断验证登录信息，直到登陆成功或取消登录
        if( STU.isLogin == 1 || STU.isLogin == 2 ) {
            w.show();
            return a.exec();
        }//若验证信息成功，则打开主界面
        else if( STU.isLogin == 3 ) {
            return 0;
        }//若取消登录，则退出程序
        else {
            log = new adminLoginDialog;
            log->exec();
        }//否则重新登录
    }
}

//初始化连接数据库
void STU_CLASS::init_database() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanagement");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        isConnect = 0;//若连接失败，能设置全局对象STU的变量isConnect为0
    }
    else {
        isConnect = 1;//若连接失败，能设置全局对象STU的变量isConnect为1
    }
}

bool STU_CLASS::isAdminLogin() {
    return isConnect;
}


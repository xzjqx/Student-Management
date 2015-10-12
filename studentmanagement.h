#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QPluginLoader>
#include <QtGui>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>

#include "stdio.h"
#include "adminlogindialog.h"
#include "dataentrydialog.h"
#include "checkdialog.h"

namespace Ui {
class StudentManagement;
}

class StudentManagement : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentManagement(QWidget *parent = 0);
    ~StudentManagement();

private slots:
    void on_dataButton_clicked();
    void on_checkButton_clicked();

    void on_pushButton_2_clicked();

    void on_deleteButton_clicked();

    void on_sortButton_clicked();


    void on_infoTableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::StudentManagement *ui;

public:
    bool isConnect;
    int isLogin;
    void init_database();

};

#endif // STUDENTMANAGEMENT_H

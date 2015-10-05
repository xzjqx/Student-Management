#ifndef STU_CLASS_H
#define STU_CLASS_H

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItem>
#include <QtSql>
#include <QSqlError>
#include <QTextCodec>

class STU_CLASS {

public:
    bool isConnect;
    int isLogin;
    int index;
    QString id;
    void init_database();

};

#include "adminlogindialog.h"
#include "checkdialog.h"
#include "dataentrydialog.h"
#include "studentmanagement.h"

#endif // STU_CLASS_H


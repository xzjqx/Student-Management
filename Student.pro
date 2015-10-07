#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T19:49:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Student
TEMPLATE = app


SOURCES += main.cpp\
        studentmanagement.cpp \
    dataentrydialog.cpp \
    adminlogindialog.cpp \
    checkdialog.cpp \
    classentrydialog.cpp \
    promptdialog.cpp \
    selectdialog.cpp \
    gradeentrydialog.cpp \
    showroomdialog.cpp \
    showstudialog.cpp \
    deletedialog.cpp \
    sortdialog.cpp

HEADERS  += studentmanagement.h \
    data_entry.h \
    dataentrydialog.h \
    adminlogindialog.h \
    checkdialog.h \
    stu.h \
    classentrydialog.h \
    promptdialog.h \
    selectdialog.h \
    gradeentrydialog.h \
    showroomdialog.h \
    showstudialog.h \
    deletedialog.h \
    sortdialog.h

FORMS    += studentmanagement.ui \
    dataentrydialog.ui \
    adminlogindialog.ui \
    checkdialog.ui \
    classentrydialog.ui \
    promptdialog.ui \
    selectdialog.ui \
    gradeentrydialog.ui \
    showroomdialog.ui \
    showstudialog.ui \
    deletedialog.ui \
    sortdialog.ui

QT += sql
QT += widgets

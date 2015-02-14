#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T21:22:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo
TEMPLATE = app

SOURCES += main.cpp\
            mainwindow.cpp \
            glwidget.cpp \
            globject.cpp

HEADERS  += mainwindow.h \
            glwidget.h \
            globject.h

FORMS    += mainwindow.ui


#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T21:22:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lecture1
TEMPLATE = app

SOURCES += main.cpp\
				mainwindow.cpp \
		glwidget.cpp \
    triangle.cpp \
    globject.cpp

HEADERS  += mainwindow.h \
		glwidget.h \
    triangle.h \
    globject.h

FORMS    += mainwindow.ui

OTHER_FILES	+= fshader.glsl \
						vshader.glsl

RESOURCES += \
		shaders.qrc

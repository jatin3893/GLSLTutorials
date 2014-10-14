#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T15:26:41
# Diffuse Lighting in GLSL Open GL
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lecture4
TEMPLATE = app


SOURCES +=	main.cpp\
						mainwindow.cpp \
						glwidget.cpp \
						globject.cpp \
						cube.cpp

HEADERS  += mainwindow.h \
						glwidget.h \
						globject.h \
						cube.h

FORMS    += mainwindow.ui

OTHER_FILES	+= fshader.glsl \
						vshader.glsl

RESOURCES += \
		shaders.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2012-07-03T12:23:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pickupper
TEMPLATE = app

DEPENDPATH += /user/include /usr/include/opencv2
INCLUDEPATH += /usr/include /usr/include/opencv2
LIBS += -lboost_iostreams -lboost_serialization -L/usr/lib -lGL -lGLU -lglut -lopencv_core -lopencv_highgui -lopencv_imgproc -L/usr/X11R6/lib -lX11 -lXi

QMAKE_CXXFLAGS += -std=gnu++11 -g -Wall -O3

SOURCES += main.cpp\
        mainwindow.cpp \
    MiddleWorker.cpp

HEADERS  += mainwindow.h \
    MiddleWorker.h

FORMS    += mainwindow.ui

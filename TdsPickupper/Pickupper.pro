#-------------------------------------------------
#
# Project created by QtCreator 2012-05-05T07:36:23
#
#-------------------------------------------------

QT       += core gui

TARGET = Pickupper
TEMPLATE = app

DEPENDPATH += /user/include /usr/include/opencv2
INCLUDEPATH += /usr/include /usr/include/opencv2
LIBS += -lboost_iostreams -lboost_serialization -L/usr/lib -lGL -lGLU -lglut -lopencv_core -lopencv_highgui -lopencv_imgproc -L/usr/X11R6/lib -lX11 -lXi
#-lavcodec -lavutil -lavdevice -lavfilter

QMAKE_CXXFLAGS += -std=gnu++11 -g -Wall
SOURCES += main.cpp\
        mainwindow.cpp \
    Routine.cpp \
    MaskCreator.cpp \
    ForMmmFile.cpp \
    MmmRoutine.cpp

HEADERS  += mainwindow.h\
    MovieLoader.h \
    Routine.h \
    MaskCreator.h \
    Pickupper.h \
    FromMoviePickupper.h \
    MmmRoutine.h

FORMS    += mainwindow.ui

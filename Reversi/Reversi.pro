#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T15:10:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reversi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chessboard.cpp \
    serversocket.cpp \
    portdialog.cpp \
    clientsocket.cpp \
    connectdialog.cpp \
    playerinfo.cpp

HEADERS  += mainwindow.h \
    chessboard.h \
    serversocket.h \
    portdialog.h \
    clientsocket.h \
    connectdialog.h \
    playerinfo.h

FORMS    += mainwindow.ui \
    portdialog.ui \
    connectdialog.ui \
    playerinfo.ui

LIBS += -lwsock32

RESOURCES += \
    res.qrc

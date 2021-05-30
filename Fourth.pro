#-------------------------------------------------
#
# Project created by QtCreator 2021-05-21T12:47:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fourth
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainscene.cpp \
    testui.cpp \
    Matrix.cpp \
    inputui.cpp \
    myqmatrix.cpp \
    reverseui.cpp \
    morepage.cpp \
    setpage.cpp \
    linearpage.cpp


HEADERS += \
        mainscene.h \
    testui.h \
    Matrix.h \
    inputui.h \
    myqmatrix.h \
    reverseui.h \
    morepage.h \
    setpage.h \
    linearpage.h


FORMS += \
        mainscene.ui \
    testui.ui \
    inputui.ui \
    reverseui.ui \
    morepage.ui \
    setpage.ui \
    linearpage.ui


RESOURCES += \
    res/res.qrc

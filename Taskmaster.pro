#-------------------------------------------------
#
# Project created by QtCreator 2018-07-31T20:17:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += xml
QT += network

TARGET = Taskmaster
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settings/musicsetting/musicsetting.cpp \
    settings/musicsetting/musicsettingitem.cpp \
    settings/musicsetting/taskmusic.cpp \
    settings/musicsetting/musicsettingxmlcache.cpp \
    settings/settingdialog.cpp \
    tasks/taskretriever.cpp \
    tasks/newtaskretriever.cpp \
    utils/fileutils.cpp \
    tasks/newtaskretriever.cpp \
    tasks/orderdetail.cpp \
    tasks/quicktask.cpp \
    tasks/taskretriever.cpp

HEADERS += \
        mainwindow.h \
    settings/musicsetting/musicsetting.h \
    settings/musicsetting/musicsettingcache.h \
    settings/musicsetting/musicsettingitem.h \
    settings/musicsetting/taskmusic.h \
    settings/musicsetting/tasktype.h \
    settings/musicsetting/musicsettingxmlcache.h \
    settings/settingdialog.h \
    tasks/taskretriever.h \
    tasks/newtaskretriever.h \
    utils/fileutils.h \
    tasks/newtaskretriever.h \
    tasks/orderdetail.h \
    tasks/quicktask.h \
    tasks/taskretriever.h

FORMS += \
        mainwindow.ui \
    settings/settingdialog.ui

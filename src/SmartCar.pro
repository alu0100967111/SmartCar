#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T20:05:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartCar
TEMPLATE = app
DEPENDPATH += UI \
              SmartCarWindow\
              SmartCarBoard\
              MainWindow\
              Common\

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0Q

SOURCES += \
        main.cpp \
        MainWindow/mainwindow.cpp \
    SmartCarWindow/smartcarwindow.cpp \
    SmartCarBoard/smartcarboard.cpp \
    SmartCarBoard/SmartCarBoardCell/smartcarboardcell.cpp \
    SmartCarBoard/ExtendedCells/ \
    Common/error.cpp \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/cartypecell.cpp \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/aimtypecell.cpp \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/blocktypecell.cpp

HEADERS += \
        MainWindow/mainwindow.h \
    SmartCarWindow/smartcarwindow.h \
    SmartCarBoard/smartcarboard.h \
    SmartCarBoard/SmartCarBoardCell/smartcarboardcell.h \
    Common/error.h \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/cartypecell.h \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/aimtypecell.h \
    SmartCarBoard/SmartCarBoardCell/ExtendedCells/blocktypecell.h

FORMS += \
    UI/mainwindow.ui \
    UI/smartcarwindow.ui

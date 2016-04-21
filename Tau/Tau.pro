#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T15:12:05
#
#-------------------------------------------------

QT       += core gui concurrent svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tau
TEMPLATE = app


SOURCES += main.cpp \
    ggraphicsview.cpp \
    player.cpp \
    ball.cpp \
    helper.cpp \
    powerup.cpp \
    ggamescene.cpp

HEADERS  += \
    ggraphicsview.h \
    player.h \
    constants.h \
    ball.h \
    helper.h \
    powerup.h \
    ggamescene.h

FORMS    +=

RESOURCES += \
    icons.qrc

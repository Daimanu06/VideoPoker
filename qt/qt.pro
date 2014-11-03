TARGET = ../VideoPokerQt

HEADERS += \ 
    mainwindow.h \
    centralwidget.h

SOURCES += \
    main.cpp \
    game.cpp \
    mainwindow.cpp \
    centralwidget.cpp

LIBS += -L"../lib/" -lVideoPoker

CONFIG += C++11 link_prl qt

INCLUDEPATH += ../lib

QT += widgets

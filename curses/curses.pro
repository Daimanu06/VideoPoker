TARGET = ../VideoPokerTUI

HEADERS += window.h

SOURCES += \
    main.cpp \
    game.cpp \
    window.cpp

LIBS += -lncursesw
LIBS += -L"../lib/" -lVideoPoker

CONFIG += C++11 link_prl

INCLUDEPATH += ../lib

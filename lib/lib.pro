TEMPLATE = lib
CONFIG += staticlib create_prl C++11
TARGET = VideoPoker

HEADERS += \
    card.h \
    deck.h \
    hand.h \
    player.h \
    money.h \
    machine.h \
    printer.h \
    game.h

SOURCES += \
    card.cpp \
    deck.cpp \
    hand.cpp \
    player.cpp \
    money.cpp \
    machine.cpp \
    printer.cpp


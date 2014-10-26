TEMPLATE = subdirs

CONFIG += C++11

SUBDIRS += lib curses

curses.depends = lib

OBJECTS_DIR = obj/

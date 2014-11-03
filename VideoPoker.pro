TEMPLATE = subdirs

CONFIG += C++11

SUBDIRS += lib qt curses

curses.depends = lib

OBJECTS_DIR = obj/

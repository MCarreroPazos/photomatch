QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

DEFINES += QT_PROJECT

SOURCES +=  tst_latchwidget.cpp

include(..\widgets_test.pri)
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

DEFINES += QT_PROJECT

SOURCES +=  tst_lce_bsescs.cpp

include(..\core.pri)
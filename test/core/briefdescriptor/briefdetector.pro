QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_PROJECT

SOURCES +=  tst_briefdescriptor.cpp

include(..\core.pri)
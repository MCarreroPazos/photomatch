QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_PROJECT

SOURCES +=  tst_image.cpp

include(..\core.pri)
#-------------------------------------------------
#
# Project created by QtCreator 2019-06-14T13:52:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fme
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_PROJECT

include(..\..\..\config.pri)

CONFIG += c++11

INCLUDEPATH += ../../
INCLUDEPATH += ../../../third_party

SOURCES += \
        main.cpp \
        MainWindowView.cpp \
        MainWindowPresenter.cpp \
        MainWindowModel.cpp \
        NewProjectPresenter.cpp \
        NewProjectView.cpp \
        ProjectModel.cpp \
        SettingsModel.cpp

HEADERS += \
        MainWindowView.h \
        MainWindowPresenter.h \
        MainWindowModel.h \
        mvp.h \
        NewProjectInterfaces.h \
        NewProjectPresenter.h \
        NewProjectView.h \
        ProjectModel.h \
        SettingsModel.h

FORMS += \
        MainWindowView.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../res/res.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

#INCLUDEPATH += $$PWD/../core
#DEPENDPATH += $$PWD/../core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/libcore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/libcore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/core.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../core/libcore.a

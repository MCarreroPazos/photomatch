#-------------------------------------------------
#
# Project created by QtCreator 2019-04-09T15:32:54
#
#-------------------------------------------------

QT       -= gui

QT += widgets

TARGET = libwidgets
TEMPLATE = lib

DEFINES += QT_PROJECT

include(..\..\..\config.pri)

!FME_EXPORTS {
  CONFIG += staticlib
}

#FME_VERSION = $${FME_MAJOR_VERSION}"."$${FME_MINOR_VERSION}
#QMAKE_SUBSTITUTES += config_fme.h.in

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../ \
               $$OUT_PWD/../../../  ## Para incluir el fichero config_fme.h
SOURCES += \
    AcebsfWidget.cpp \
    AgastWidget.cpp \
    AkazeWidget.cpp \
    BriefWidget.cpp \
    BriskWidget.cpp \
    CLAHEWidget.cpp \
    CmbfheWidget.cpp \
    DaisyWidget.cpp \
    DescriptorMatcherWidget.cpp \
    DheWidget.cpp \
    FaheWidget.cpp \
    FastWidget.cpp \
    FreakWidget.cpp \
    GfttWidget.cpp \
    HmclaheWidget.cpp \
    HogWidget.cpp \
    KazeWidget.cpp \
    LatchWidget.cpp \
    LceBsescsWidget.cpp \
    LucidWidget.cpp \
    MsdWidget.cpp \
    MserWidget.cpp \
    MsrcpWidget.cpp \
    NoshpWidget.cpp \
    OrbWidget.cpp \
    PoheWidget.cpp \
    SiftWidget.cpp \
    StarWidget.cpp \
    SurfWidget.cpp \
    WallisWidget.cpp \
    RswheWidget.cpp


HEADERS += ../fme_global.h \
    AcebsfWidget.h \
    AgastWidget.h \
    AkazeWidget.h \
    BriefWidget.h \
    BriskWidget.h \
    CLAHEWidget.h \
    CmbfheWidget.h \
    DaisyWidget.h \
    DescriptorMatcherWidget.h \
    DheWidget.h \
    FaheWidget.h \
    FastWidget.h \
    FmeWidget.h \
    FreakWidget.h \
    GfttWidget.h \
    HmclaheWidget.h \
    HogWidget.h \
    KazeWidget.h \
    LatchWidget.h \
    LceBsescsWidget.h \
    LucidWidget.h \
    MsdWidget.h \
    MserWidget.h \
    MsrcpWidget.h \
    NoshpWidget.h \
    OrbWidget.h \
    PoheWidget.h \
    SiftWidget.h \
    StarWidget.h \
    SurfWidget.h \
    WallisWidget.h \
    RswheWidget.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
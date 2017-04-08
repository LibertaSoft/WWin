TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgdi32

HEADERS += \
    wwin/wapplication.h \
    wwin/wobject.h \
    wwin/wwidget.h

SOURCES += main.cpp\
    wwin/wapplication.cpp \
    wwin/wobject.cpp \
    wwin/wwidget.cpp

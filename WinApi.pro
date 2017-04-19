TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgdi32

HEADERS += \
    wwin/wapplication.h \
    wwin/wobject.h \
    wwin/wwidget.h \
    wwin/helpers/winapiwindowbuilder.h \
    wwin/wscreen.h \
    wwin/wpushbutton.h \
    wwin/wevent.h \
    wwin/wmessagebox.h \
    wwin/wmouseevent.h \
    wwin/wlineedit.h

SOURCES += main.cpp\
    wwin/wapplication.cpp \
    wwin/wobject.cpp \
    wwin/wwidget.cpp \
    wwin/helpers/winapiwindowbuilder.cpp \
    wwin/wscreen.cpp \
    wwin/wpushbutton.cpp \
    wwin/wevent.cpp \
    wwin/wmessagebox.cpp \
    wwin/wmouseevent.cpp \
    wwin/wlineedit.cpp

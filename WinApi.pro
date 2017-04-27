TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgdi32
#if COMMON_CONTROLS
LIBS += -lcomctl32
#endif COMMON_CONTROLS

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
    wwin/wstringlistmodel.h \
    wwin/wabstractitemmodel.h \
    wwin/wlineedit.h \
    wwin/wstring.h \
    wwin/wlistbox.h \
    wwin/wlistview.h \
    wwin/wabstractitemview.h \
    testwindow.h \
    wwin/wabstractbutton.h \
    wwin/wcheckbox.h \
    wwin/wradiobutton.h \
    wwin/wbuttongroup.h \
    wwin/wplaintextedit.h \
    wwin/wspinbox.h \
    wwin/wprogressbar.h \
    wwin/wlabel.h

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
    wwin/wstringlistmodel.cpp \
    wwin/wabstractitemmodel.cpp \
    wwin/wlineedit.cpp \
    wwin/wstring.cpp \
    wwin/wlistbox.cpp \
    wwin/wlistview.cpp \
    wwin/wabstractitemview.cpp \
    testwindow.cpp \
    wwin/wabstractbutton.cpp \
    wwin/wcheckbox.cpp \
    wwin/wradiobutton.cpp \
    wwin/wbuttongroup.cpp \
    wwin/wplaintextedit.cpp \
    wwin/wspinbox.cpp \
    wwin/wprogressbar.cpp \
    wwin/wlabel.cpp

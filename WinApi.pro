TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

MODULES += ui

LIBS += -lgdi32 # Пока нигде, но понадобится для картинок
LIBS += -lcomctl32 # Некоторые виджеты типа WSpinBox

contains( LIBS, -lgdi32 ) {
    DEFINES += WWIN_GDI
}

contains( MODULES, ui ){
    HEADERS += \
        wwin/wgui.h \
        wwin/ui/wwidget.h \
        wwin/ui/wscreen.h \
        wwin/ui/wpushbutton.h \
        wwin/ui/wmessagebox.h \
        wwin/ui/wabstractitemmodel.h \
        wwin/ui/wlineedit.h \
        wwin/ui/wlistbox.h \
        wwin/ui/wlistview.h \
        wwin/ui/wabstractitemview.h \
        wwin/ui/wabstractbutton.h \
        wwin/ui/wcheckbox.h \
        wwin/ui/wradiobutton.h \
        wwin/ui/wbuttongroup.h \
        wwin/ui/wplaintextedit.h \
        wwin/ui/wprogressbar.h \
        wwin/ui/wlabel.h

    SOURCES += \
        wwin/ui/wwidget.cpp \
        wwin/ui/wscreen.cpp \
        wwin/ui/wpushbutton.cpp \
        wwin/ui/wmessagebox.cpp \
        wwin/ui/wabstractitemmodel.cpp \
        wwin/ui/wlineedit.cpp \
        wwin/ui/wlistbox.cpp \
        wwin/ui/wlistview.cpp \
        wwin/ui/wabstractitemview.cpp \
        wwin/ui/wabstractbutton.cpp \
        wwin/ui/wcheckbox.cpp \
        wwin/ui/wradiobutton.cpp \
        wwin/ui/wbuttongroup.cpp \
        wwin/ui/wplaintextedit.cpp \
        wwin/ui/wprogressbar.cpp \
        wwin/ui/wlabel.cpp

    contains( LIBS, -lcomctl32 ) {
        DEFINES += WWIN_COMMON_CONTROLS
        HEADERS += wwin/ui/wspinbox.h
        SOURCES += wwin/ui/wspinbox.cpp
    }
}

HEADERS += \
    wwin/wapplication.h \
    wwin/wobject.h \
    wwin/helpers/winapiwindowbuilder.h \
    wwin/wevent.h \
    wwin/wmouseevent.h \
    wwin/wstringlistmodel.h \
    wwin/wstring.h \
    testwindow.h \
    wwin/wimage.h \
    wwin/wstandardpaths.h \
    wwin/wstringlist.h

SOURCES += main.cpp\
    wwin/wapplication.cpp \
    wwin/wobject.cpp \
    wwin/helpers/winapiwindowbuilder.cpp \
    wwin/wevent.cpp \
    wwin/wmouseevent.cpp \
    wwin/wstringlistmodel.cpp \
    wwin/wstring.cpp \
    testwindow.cpp \
    wwin/wimage.cpp \
    wwin/wstandardpaths.cpp \
    wwin/wstringlist.cpp

#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "wwin/wwidget.h"
#include "wwin/wlineedit.h"
#include "wwin/wlistbox.h"
#include "wwin/wlistview.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wcheckbox.h"
#include "wwin/wradiobutton.h"
#include "wwin/wbuttongroup.h"
#include "wwin/wplaintextedit.h"
#include "wwin/wspinbox.h"
#include "wwin/wprogressbar.h"
#include "wwin/wscreen.h"
#include "wwin/wmessagebox.h"
#include "wwin/wlabel.h"

class TestWindow : public WWidget
{
public:
    TestWindow(WWidget *parent);
    void initUi();
};

#endif // TESTWINDOW_H

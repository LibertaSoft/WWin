#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "wwin/wwidget.h"
#include <wwin/wlineedit.h>
#include <wwin/wlistbox.h>
#include <wwin/wlistview.h>
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wscreen.h"
#include "wwin/wmessagebox.h"

class TestWindow : public WWidget
{
public:
    TestWindow(WWidget *parent);
    void initUi();
};

#endif // TESTWINDOW_H
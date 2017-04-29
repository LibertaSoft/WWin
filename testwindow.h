#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "wwin/wgui.h"

class TestWindow : public WWidget
{
public:
    TestWindow(WWidget *parent);
    void initUi();
};

#endif // TESTWINDOW_H

#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <WGui>

class TestWindow : public WWidget
{
public:
    TestWindow(WWidget *parent);
    void initUi();

    bool paintEvent(WPaintEvent *e);
};

#endif // TESTWINDOW_H

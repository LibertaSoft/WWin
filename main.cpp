#include <windows.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    WWidget *wgt = new WWidget();
    wgt->setTitle("WWinApi Lib");
    wgt->show();
    WPushButton *btn = new WPushButton("My Button", wgt);
    btn->show();

    return app->run();
}

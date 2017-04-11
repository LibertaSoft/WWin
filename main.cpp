#include <windows.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wscreen.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    // Window pos
    int width  = 480;
    int height = 320;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    WWidget *wgt = new WWidget();
//    wgt->setTitle("WWinApi Lib Title");
    wgt->setGeometry(x,y,width,height);
    wgt->show();

    WPushButton *btn = new WPushButton("My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();

    return app->run();
}

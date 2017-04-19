#include <windows.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wscreen.h"
#include "wwin/wmessagebox.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    // Window pos
    int width  = 480;
    int height = 320;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    WWidget *wgt = new WWidget();
    wgt->setTitle("WWinApi Lib Title");
    wgt->setGeometry(x,y,width,height);
    wgt->show();

    WPushButton *btn = new WPushButton("My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();

    WPushButton *btn2 = new WPushButton("My Button 2", wgt);
    btn2->setGeometry(140,10,120,60);
    btn2->show();
    btn2->setFocus();
    btn2->on_click([](){
        WMessageBox::information("Title", "Button clicked");
    });

    return app->run();
}

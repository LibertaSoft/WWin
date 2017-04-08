#include <windows.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    WWidget *wgt = new WWidget();
    wgt->show();

    return app->run();
}

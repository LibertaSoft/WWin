#include "wwidget.h"
#include "wwin/wapplication.h"

WWidget::WWidget(WWidget *parent, int params)
    : WObject(parent), _windowParams(params)
{
    _hwnd = CreateWindow( L"WWINAPI",
                         L"Fract Calculator", WS_OVERLAPPEDWINDOW |
                         WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
                         10,
                         10,
                         320,
                         480,
                         HWND_DESKTOP,
                         NULL,
                         WApplication::instance()->getHinstance(),
                         NULL );

    if( ! _hwnd )
        return;
}

void WWidget::show()
{
    ShowWindow( _hwnd, _windowParams );
    UpdateWindow( _hwnd );
}

void WWidget::setGeometry(int x, int y, int w, int h)
{
    _x = x;
    _y = y;
    _width = w;
    _height = h;
}


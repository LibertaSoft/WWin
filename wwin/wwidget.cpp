#include "wwidget.h"
#include "wwin/wapplication.h"
#include "wwin/helpers/winapiwindowbuilder.h"
#include "wwin/wscreen.h"

HWND WWidget::hwnd() const
{
    return _hwnd;
}

HWND WWidget::parentHwnd() const
{
    HWND p_hwnd = HWND_DESKTOP;
    WWidget *parent = parentWidget();
    if( parent && parent->hwnd() ){
        p_hwnd = parent->hwnd();
    }
    return p_hwnd;
}

WWidget* WWidget::parentWidget() const
{
    return static_cast<WWidget*>( WObject::parent() );
}

int WWidget::style()
{
    return WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
}

WWidget::WWidget(WWidget *parent, int params)
    : WObject(parent), _windowParams(params)
{
    _width  = 480;
    _height = 320;

    _x = WScreen::width()  / 2  - _width / 2,
    _y = WScreen::height() / 2 - _height / 2;
}

void WWidget::show()
{
    if( ! _hwnd ) {
       _hwnd = WinApiWindowBuilder()
            .className(_className)
            .title(_title)
            .style(style())
            .geometry(_x, _y, _width, _height)
            .parent(parentHwnd())
            .hinstance(WApplication::instance()->getHinstance())
            .param( LPVOID( _windowParams ) )
            .build();
    }
    ShowWindow( _hwnd, _windowParams );
    UpdateWindow( _hwnd );
}

void WWidget::setGeometry(int x, int y, int width, int height)
{
    _x = x;
    _y = y;

    // Можно проще
    if( width < _minWidth ) {
        width = _minWidth;
    } else if( width > _maxWidth ) {
        width = _maxWidth;
    }
    if( height < _minHeight ) {
        height = _minHeight;
    } else if( height > _maxHeight ) {
        height = _maxHeight;
    }

    _width = width;
    _height = height;
}

void WWidget::setTitle(const std::string &title)
{
    _title = title;
}


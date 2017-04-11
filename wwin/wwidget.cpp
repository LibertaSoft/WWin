#include "wwidget.h"
#include "wwin/wapplication.h"
#include "wwin/helpers/winapiwindowbuilder.h"
#include "wwin/wscreen.h"

#include <iostream>

HWND WWidget::hwnd() const
{
    return _hwnd;
}

void WWidget::hwnd(HWND hwnd)
{
    _hwnd = hwnd;
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
    WObject* parent = WObject::parent();
    if( parent && parent->type() == WObjectType::Widget ){
        return static_cast<WWidget*>( parent );
    }
    return nullptr;
}

int WWidget::style()
{
    return WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
}

bool WWidget::init()
{
    HWND x = WinApiWindowBuilder()
         .className( _className )
         .title( _title )
         .style( this->style() )
         .geometry( _x, _y, _width, _height )
         .parent( this->parentHwnd() )
         .hinstance( wApp->getHinstance() )
         .param( LPVOID( _windowParams ) )
         .build();
    this->hwnd(x);
    wApp->addComponent(this);

    return (x != nullptr);
}

WWidget::WWidget(WWidget *parent, int params)
    : WObject(parent), _windowParams(params)
{
    this->setType(WObjectType::Widget);

    if( parent == nullptr ) {
        this->init();
    }
}

WWidget::~WWidget()
{
    wApp->removeComponent(this);
}

void WWidget::show()
{
    if( ! this->hwnd() ) {
       this->init();
    }
    ShowWindow( this->hwnd(), _windowParams );
    UpdateWindow( this->hwnd() );
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

    SetWindowPos(this->hwnd(), nullptr, _x, _y, _width, _height, 0);

}

void WWidget::setTitle(const std::string &title)
{
    _title = title;
    SetWindowText(this->hwnd(), WObject::tow(_title));
}


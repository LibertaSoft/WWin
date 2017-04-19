#include "wwidget.h"
#include "wwin/wapplication.h"
#include "wwin/helpers/winapiwindowbuilder.h"
#include "wwin/wscreen.h"

#include <iostream>

int WWidget::_componentCount = 0;

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

WORD WWidget::cid() const
{
    return _cid;
}

int WWidget::style()
{
    return WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
}

bool WWidget::init()
{
    HWND x = WinApiWindowBuilder()
         .className( _className )
         .title( this->title() )
         .style( this->style() )
         .geometry( _x, _y, _width, _height )
         .parent( this->parentHwnd() )
         .hinstance( wApp->getHinstance() )
         .param( LPVOID( _windowParams ) )
         .menu( reinterpret_cast<HMENU>( this->cid() ) )
         .build();
    this->hwnd(x);
    wApp->addComponent(this);

    return (x != nullptr);
}

bool WWidget::mouseEvent(WMouseEvent *e)
{
    return e->isAccepted();
}

bool WWidget::event(WEvent *e)
{
    if( e->type() == WEventType::WMouseEvent ){
        this->mouseEvent( static_cast<WMouseEvent*>(e) );
    }
    return WObject::event(e);
}

WWidget::WWidget(WWidget *parent, int params)
    : WObject(parent), _windowParams(params)
{
    _cid = _componentCount++;
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

std::string WWidget::title() const
{
    return _title;
}

void WWidget::setTitle(const std::string &title)
{
    _title = title;
    SetWindowText(this->hwnd(), WObject::tow(_title));
}

void WWidget::setFocus()
{
    SetFocus( this->hwnd() );
}


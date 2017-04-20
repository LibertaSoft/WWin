#include "wmouseevent.h"
#include <windows.h>

WMouseEvent::WMouseEvent()
    : WEvent(WEvent::Type::MouseReleaseEvent)
{
    POINT p;
    if( GetCursorPos(&p) ){
        this->setCursorPos(p.x, p.y);
    }
    this->setButton(WMouseEvent::Button::LeftButton);
    int mod = WMouseEvent::KeyModifiers::NoModifier;
    if( GetAsyncKeyState(VK_LSHIFT) < 0 || GetAsyncKeyState(VK_RSHIFT) < 0 ){
        mod |= WMouseEvent::KeyModifiers::ShiftModifier;
    }
    if( GetKeyState(VK_LCONTROL) < 0 || GetKeyState(VK_RCONTROL) < 0 ){
        mod |= WMouseEvent::KeyModifiers::ControlModifier;
    }
    if( GetAsyncKeyState(VK_LMENU) < 0 || GetAsyncKeyState(VK_RMENU) < 0 ){
        mod |= WMouseEvent::KeyModifiers::AltModifier;
    }
    if( GetAsyncKeyState(VK_LWIN) < 0 || GetAsyncKeyState(VK_RWIN) < 0 ){
        mod |= WMouseEvent::KeyModifiers::MetaModifier;
    }
    this->setModifiers(mod);
}

void WMouseEvent::setCursorPos(long x, long y)
{
    _x = x;
    _y = y;
}

long WMouseEvent::x() const
{
    return _x;
}

long WMouseEvent::y() const
{
    return _y;
}

void WMouseEvent::setButton(WMouseEvent::Button button)
{
    _button = button;
}

WMouseEvent::Button WMouseEvent::button() const
{
    return _button;
}

void WMouseEvent::setModifiers(int modifiers)
{
    _modifiers = modifiers;
}

int WMouseEvent::modifiers() const
{
    return _modifiers;
}


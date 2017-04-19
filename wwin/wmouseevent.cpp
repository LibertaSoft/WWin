#include "wmouseevent.h"

WMouseEvent::WMouseEvent()
    : WEvent(WEventType::WMouseEvent)
{

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

void WMouseEvent::setButton(WMouseButton button)
{
    _button = button;
}

WMouseButton WMouseEvent::button() const
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


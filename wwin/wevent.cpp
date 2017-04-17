#include "wevent.h"

WEvent::WEvent(WEventType type)
    : _type(type)
{

}

void WEvent::accept()
{
    _accepted = true;
}

void WEvent::ignore()
{
    _accepted = false;
}

bool WEvent::isAccepted() const
{
    return _accepted;
}

void WEvent::setAccepted(bool accepted)
{
    _accepted = accepted;
}

WEventType WEvent::type()
{
    return _type;
}


#include "wevent.h"

WEvent::WEvent(WEvent::Type type)
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

WEvent::Type WEvent::type()
{
    return _type;
}


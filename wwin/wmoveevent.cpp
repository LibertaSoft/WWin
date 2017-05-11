#include "wmoveevent.h"

WPoint WMoveEvent::oldPos() const
{
    return _oldPos;
}

void WMoveEvent::setOldPos(const WPoint &oldPos)
{
    _oldPos = oldPos;
}

WPoint WMoveEvent::pos() const
{
    return _pos;
}

void WMoveEvent::setPos(const WPoint &pos)
{
    _pos = pos;
}

WMoveEvent::WMoveEvent()
    : WEvent( WEvent::Type::MoveEvent )
{}

WMoveEvent::WMoveEvent(const WPoint &pos, const WPoint &oldPos)
    : WEvent( WEvent::Type::MoveEvent ),
      _oldPos(oldPos), _pos(pos)
{}


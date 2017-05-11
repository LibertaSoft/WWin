#ifndef WMOVEEVENT_H
#define WMOVEEVENT_H

#include "wwin/wevent.h"
#include "wwin/wpoint.h"

class WMoveEvent : public WEvent
{
private:
    WPoint _oldPos;
    WPoint _pos;

public:
    WMoveEvent();
    WMoveEvent(const WPoint& pos, const WPoint& oldPos);

    WPoint oldPos() const;
    void setOldPos(const WPoint &oldPos);

    WPoint pos() const;
    void setPos(const WPoint &pos);
};

#endif // WMOVEEVENT_H

#ifndef WMOVEEVENT_H
#define WMOVEEVENT_H

#include "wwin/wevent.h"
#include "wwin/wpoint.h"

/*!
 * \brief WMoveEvent класс собтия перемещения
 */
class WMoveEvent : public WEvent
{
private:
    WPoint _oldPos; /// < старая позиция
    WPoint _pos;    /// < новая позиция

public:
    WMoveEvent();
    WMoveEvent(const WPoint& pos, const WPoint& oldPos);

    WPoint oldPos() const;
    void setOldPos(const WPoint &oldPos);

    WPoint pos() const;
    void setPos(const WPoint &pos);
};

#endif // WMOVEEVENT_H

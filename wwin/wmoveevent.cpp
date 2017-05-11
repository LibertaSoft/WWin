#include "wmoveevent.h"

/*!
 * \brief WMoveEvent::oldPos получить старую позицию
 * \return
 */
WPoint WMoveEvent::oldPos() const
{
    return _oldPos;
}

/*!
 * \brief WMoveEvent::setOldPos установить старую позицию
 * \param oldPos
 */
void WMoveEvent::setOldPos(const WPoint &oldPos)
{
    _oldPos = oldPos;
}

/*!
 * \brief WMoveEvent::pos получить текущую позицию
 * \return
 */
WPoint WMoveEvent::pos() const
{
    return _pos;
}

/*!
 * \brief WMoveEvent::setPos установить текущую позицию
 * \param pos
 */
void WMoveEvent::setPos(const WPoint &pos)
{
    _pos = pos;
}

/*!
 * \brief WMoveEvent::WMoveEvent конструктор с инициализацией события
 */
WMoveEvent::WMoveEvent()
    : WEvent( WEvent::Type::MoveEvent )
{}

/*!
 * \brief WMoveEvent::WMoveEvent конструктор с инициализацией события
 * \param pos
 * \param oldPos
 */
WMoveEvent::WMoveEvent(const WPoint &pos, const WPoint &oldPos)
    : WEvent( WEvent::Type::MoveEvent ),
      _oldPos(oldPos), _pos(pos)
{}


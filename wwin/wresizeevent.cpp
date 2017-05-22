#include "wresizeevent.h"

/*!
 * \brief WResizeEvent::size получить новый размер
 * \return
 */
WSize WResizeEvent::size() const
{
    return _size;
}

/*!
 * \brief WResizeEvent::setSize установить новый размер
 * \param size
 */
void WResizeEvent::setSize(const WSize &size)
{
    _size = size;
}

/*!
 * \brief WResizeEvent::oldSize получить старый размер
 * \return
 */
WSize WResizeEvent::oldSize() const
{
    return _oldSize;
}

/*!
 * \brief WResizeEvent::setOldSize установить старый размер
 * \param oldSize
 */
void WResizeEvent::setOldSize(const WSize &oldSize)
{
    _oldSize = oldSize;
}

/*!
 * \brief WResizeEvent::WResizeEvent инициализировать событие изменения размера
 */
WResizeEvent::WResizeEvent()
    : WEvent( WEvent::Type::ResizeEvent )
{

}

/*!
 * \brief WResizeEvent::WResizeEvent инициализировать событие изменения размера
 * \param size
 * \param oldSize
 */
WResizeEvent::WResizeEvent(const WSize &size, const WSize &oldSize)
    : WEvent( WEvent::Type::ResizeEvent ),
      _size(size), _oldSize(oldSize)
{}


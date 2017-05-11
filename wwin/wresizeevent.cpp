#include "wresizeevent.h"

WSize WResizeEvent::size() const
{
    return _size;
}

void WResizeEvent::setSize(const WSize &size)
{
    _size = size;
}

WSize WResizeEvent::oldSize() const
{
    return _oldSize;
}

void WResizeEvent::setOldSize(const WSize &oldSize)
{
    _oldSize = oldSize;
}

WResizeEvent::WResizeEvent()
    : WEvent( WEvent::Type::ResizeEvent )
{

}

WResizeEvent::WResizeEvent(const WSize &size, const WSize &oldSize)
    : WEvent( WEvent::Type::ResizeEvent ),
      _size(size), _oldSize(oldSize)
{}


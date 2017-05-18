#include "wpaintevent.h"

WRect WPaintEvent::rect() const
{
  return _rect;
}

void WPaintEvent::setRect(const WRect &rect)
{
  _rect = rect;
}

WPaintEvent::WPaintEvent(WRect rect)
  : WEvent( WEvent::Type::PaintEvent )
{
  _rect = rect;
}

/*
WPaintEvent::WPaintEvent(WRegion region)
  : _type(WEvent::Type::PaintEvent)
{
  _region = region;
}
//*/

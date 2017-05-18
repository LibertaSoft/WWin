#ifndef WPAINTEVENT_H
#define WPAINTEVENT_H

#include "wwin/wevent.h"

struct WRect {
  int x1 = 0;
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;
};

class WPaintEvent : public WEvent
{
    WRect _rect;
    //WRegion _region;
public:
  WPaintEvent(WRect);
  //WPaintEvent(WRegion);
  WRect rect() const;
  void setRect(const WRect &rect);
};

#endif // WPAINTEVENT_H

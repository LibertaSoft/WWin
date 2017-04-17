#ifndef WMOUSEEVENT_H
#define WMOUSEEVENT_H

#include "wwin/wevent.h"

class WMouseEvent : public WEvent
{
    int _x = 0;
    int _y = 0;
public:
    WMouseEvent();
};

#endif // WMOUSEEVENT_H

#ifndef WRESIZEEVENT_H
#define WRESIZEEVENT_H

#include "wwin/wevent.h"
#include "wwin/wsize.h"

class WResizeEvent : public WEvent
{
private:
    WSize _size;
    WSize _oldSize;

public:
    WResizeEvent();
    WResizeEvent(const WSize &size, const WSize &oldSize);

    WSize size() const;
    void setSize(const WSize &size);

    WSize oldSize() const;
    void setOldSize(const WSize &oldSize);
};

#endif // WRESIZEEVENT_H

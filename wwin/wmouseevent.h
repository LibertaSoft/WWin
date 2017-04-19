#ifndef WMOUSEEVENT_H
#define WMOUSEEVENT_H

#include "wwin/wevent.h"

enum class WMouseButton : int {
    LeftButton,
    RightButton,
    MiddleButton,
    BackButton,
    NoButton
};
namespace WMouseKeyModifiers {
    enum WMouseKeyModifiers {
        NoModifier      = 0,
        ShiftModifier   = 1 << 0,
        ControlModifier = 1 << 1,
        AltModifier     = 1 << 2,
        MetaModifier    = 1 << 3,
        KeypadModifier  = 1 << 4
    };
}

class WMouseEvent : public WEvent
{
    int _x = 0;
    int _y = 0;

    WMouseButton _button = WMouseButton::NoButton;
    int _modifiers = WMouseKeyModifiers::NoModifier;
public:
    WMouseEvent();
    void setCursorPos(long x, long y);

    long x() const;
    long y() const;

    void setButton(WMouseButton button);
    WMouseButton button() const;

    void setModifiers(int modifiers);
    int modifiers() const;
};

#endif // WMOUSEEVENT_H

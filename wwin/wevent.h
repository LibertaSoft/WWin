#ifndef WEVENT_H
#define WEVENT_H

enum class WEventType : int {
    WNone,
    WMouseEvent,
//    WKeyEvent,
//    WPaintEvent,
//    WShowEvent,
//    WHideEvent,
//    WWheelEvent,
//    WTabletEvent,
//    WFocusEvent
};

class WEvent
{
    WEventType _type = WEventType::WNone;
    bool _accepted = false;
public:
    WEvent(WEventType type = WEventType::WNone);
    void accept();
    void ignore();
    bool isAccepted() const;
    void setAccepted(bool accepted);
    WEventType type();
};

#endif // WEVENT_H

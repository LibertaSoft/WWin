#ifndef WEVENT_H
#define WEVENT_H



class WEvent
{
public:
    enum class Type : int {
        None,
        MouseReleaseEvent,
        WindowTitleChange,
        KeyEvent,
        PaintEvent,
        ShowEvent,
        HideEvent,
        WheelEvent,
        TabletEvent,
        FocusEvent
    };
private:
    WEvent::Type _type = WEvent::Type::None;
    bool _accepted = false;
public:
    WEvent(WEvent::Type type = WEvent::Type::None);
    void accept();
    void ignore();
    bool isAccepted() const;
    void setAccepted(bool accepted);
    WEvent::Type type();
};

#endif // WEVENT_H

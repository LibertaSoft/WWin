#ifndef WEVENT_H
#define WEVENT_H


/**
 * @brief WEvent Базовый класс для системы событий.
 * описывающий информацию о событии, принято оно или нет, тип события и т.п..
 */
class WEvent
{
public:
    enum class Type : int {
        None,
        MouseReleaseEvent,
        MouseDoubleClickEvent,
        WindowTitleChange,
        KeyEvent,
        PaintEvent,
        ResizeEvent,
        MoveEvent,
        ChangeEvent,
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
    void setType(WEvent::Type type);
};

#endif // WEVENT_H

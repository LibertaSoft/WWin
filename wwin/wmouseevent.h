#ifndef WMOUSEEVENT_H
#define WMOUSEEVENT_H

#include "wwin/wevent.h"

/**
 * @brief WMouseEvent Класс события с информацией о клике мыши.
 * Так же содержит информацию о зажатии управляющих клавиш во время клика и позицию курсора.
 */
class WMouseEvent : public WEvent
{
public:
    enum KeyModifiers {
        NoModifier      = 0,
        ShiftModifier   = 1 << 0,
        ControlModifier = 1 << 1,
        AltModifier     = 1 << 2,
        MetaModifier    = 1 << 3,
        KeypadModifier  = 1 << 4
    };
    enum class Button : int {
        LeftButton,
        RightButton,
        MiddleButton,
        BackButton,
        NoButton,
        dblClick
    };

private:
    int _x = 0; /// < Позиция мыши на экране по оси Ox, относительно экрана
    int _y = 0; /// < Позиция мыши на экране по оси Oy, относительно экрана

    WMouseEvent::Button _button = WMouseEvent::Button::NoButton; /// < Клавиша мыши инициировавшая событие
    int _modifiers = WMouseEvent::KeyModifiers::NoModifier; /// < Зажатые клавиши-модификаторы
public:
    WMouseEvent();
    void setCursorPos(long x, long y);

    long x() const;
    long y() const;

    void setButton(WMouseEvent::Button button);
    WMouseEvent::Button button() const;

    void setModifiers(int modifiers);
    int modifiers() const;
};

#endif // WMOUSEEVENT_H

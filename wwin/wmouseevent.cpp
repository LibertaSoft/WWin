#include "wmouseevent.h"
#include <windows.h>

/**
 * @brief WMouseEvent::WMouseEvent Конструктор с инициализацией события
 * Получает из системы информацию о зажатых клавишах-модификаторах и курсоре мыши.
 */
WMouseEvent::WMouseEvent()
    : WEvent(WEvent::Type::MouseReleaseEvent)
{
    POINT p;
    if( GetCursorPos(&p) ){
        this->setCursorPos(p.x, p.y);
    }
    this->setButton(WMouseEvent::Button::LeftButton);
    int mod = WMouseEvent::KeyModifiers::NoModifier;
    if( GetAsyncKeyState(VK_LSHIFT) < 0 || GetAsyncKeyState(VK_RSHIFT) < 0 ){
        mod |= WMouseEvent::KeyModifiers::ShiftModifier;
    }
    if( GetKeyState(VK_LCONTROL) < 0 || GetKeyState(VK_RCONTROL) < 0 ){
        mod |= WMouseEvent::KeyModifiers::ControlModifier;
    }
    if( GetAsyncKeyState(VK_LMENU) < 0 || GetAsyncKeyState(VK_RMENU) < 0 ){
        mod |= WMouseEvent::KeyModifiers::AltModifier;
    }
    if( GetAsyncKeyState(VK_LWIN) < 0 || GetAsyncKeyState(VK_RWIN) < 0 ){
        mod |= WMouseEvent::KeyModifiers::MetaModifier;
    }
    this->setModifiers(mod);
}

/**
 * @brief WMouseEvent::setCursorPos Задать данные о положении мыши
 * @note Мышь перемещена не будет ... ну так на всякий...
 * @param x - позиция по оси Ox
 * @param y - позиция по оси Oy
 */
void WMouseEvent::setCursorPos(long x, long y)
{
    _x = x;
    _y = y;
}

/**
 * @brief WMouseEvent::x получить позицию курсора по оси Ox
 * @return
 */
long WMouseEvent::x() const
{
    return _x;
}

/**
 * @brief WMouseEvent::y получить позицию курсора по оиси Oy
 * @return
 */
long WMouseEvent::y() const
{
    return _y;
}

/**
 * @brief WMouseEvent::setButton Установить информацию о нажатой кнопке мыши
 * @param button
 */
void WMouseEvent::setButton(WMouseEvent::Button button)
{
    _button = button;
}

/**
 * @brief WMouseEvent::button получить информацию о нажатой кнопке мыши
 * @return
 */
WMouseEvent::Button WMouseEvent::button() const
{
    return _button;
}

/**
 * @brief WMouseEvent::setModifiers установить кливиши-модификаторы
 * @param modifiers
 */
void WMouseEvent::setModifiers(int modifiers)
{
    _modifiers = modifiers;
}

/**
 * @brief WMouseEvent::modifiers получить клавиши модификаторы
 * @return
 */
int WMouseEvent::modifiers() const
{
    return _modifiers;
}


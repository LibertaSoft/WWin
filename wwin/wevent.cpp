#include "wevent.h"

/**
 * @brief WEvent::WEvent Конструктор класса события
 * @param type тип события
 */
WEvent::WEvent(WEvent::Type type)
    : _type(type)
{}

/**
 * @brief WEvent::accept пометить что событие обработано.
 */
void WEvent::accept()
{
    _accepted = true;
}

/**
 * @brief WEvent::ignore пометить что событие проигнорировано.
 */
void WEvent::ignore()
{
    _accepted = false;
}

/**
 * @brief WEvent::isAccepted проверить обработано ли событие
 * @return
 */
bool WEvent::isAccepted() const
{
    return _accepted;
}

/**
 * @brief WEvent::setAccepted установить обработано событие или нет
 * @param accepted
 */
void WEvent::setAccepted(bool accepted)
{
    _accepted = accepted;
}

/**
 * @brief WEvent::type Получить тип события
 * @return
 */
WEvent::Type WEvent::type()
{
    return _type;
}

void WEvent::setType(WEvent::Type type)
{
    _type = type;
}


#include "wpushbutton.h"

#include "wwin/ui/wmessagebox.h"
#include <iostream>

/**
 * @brief WPushButton::style стиль кнопки
 * @return
 */
int WPushButton::style()
{
    return BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD;
}

/**
 * @brief WPushButton::WPushButton Коснтруктор с инициализацией базового класса и окна кнопки
 * @param parent - родитель
 */
WPushButton::WPushButton(WWidget *parent)
    : WAbstractButton(parent)
{
    this->initWndClass(L"BUTTON");
}

/**
 * @brief WPushButton::WPushButton Конструктор с инициализацией базового класса и окна кнопки,
 * плюс установкой надписи на кнопке
 * @param title - надпись на кнопке
 * @param parent - родитель
 */
WPushButton::WPushButton(WString title, WWidget *parent)
    : WAbstractButton(parent)
{
    _title = title;
    this->initWndClass(L"BUTTON");
}


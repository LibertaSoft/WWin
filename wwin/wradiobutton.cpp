#include "wradiobutton.h"

/*!
 * \brief WRadioButton::WRadioButton Конструктор с инциализацией базового класса WAbstractButton
 * \param parent - родительское окно
 */
WRadioButton::WRadioButton(WWidget *parent)
    : WAbstractButton(parent)
{
    this->setCheckable(true);
    this->initWndClass(L"BUTTON");
}

/*!
 * \brief WRadioButton::WRadioButton Конструктор с инциализацией базового класса WAbstractButton
 * \param parent - родительское окно
 */
WRadioButton::WRadioButton(const WString title, WWidget *parent)
    : WAbstractButton(parent)
{
    this->setTitle(title);
    this->setCheckable(true);
    this->initWndClass(L"BUTTON");
}

/*!
 * \brief WRadioButton::style Перегрузка стиля окна переключателя(radiobutton)
 * \return
 */
int WRadioButton::style()
{
    return WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON;
}


#include "wcheckbox.h"

/*!
 * \brief WCheckBox::WCheckBox Конструктор с инциализацией базового класса WAbstractButton
 * \param parent - родительское окно
 */
WCheckBox::WCheckBox(WWidget *parent)
    : WAbstractButton(parent)
{
    this->initWndClass(L"BUTTON");
    this->setCheckable(true);
}

/*!
 * \brief WCheckBox::WCheckBox Конструктор с инциализацией базового класса WAbstractButton
 * \param parent - родительское окно
 */
WCheckBox::WCheckBox(const WString title, WWidget *parent)
    : WAbstractButton(parent)
{
    this->setTitle( title );
    this->initWndClass(L"BUTTON");
    this->setCheckable(true);
}

/*!
 * \brief WCheckBox::style Перегрузка стиля окна переключателя(checkbox)
 * \return
 */
int WCheckBox::style()
{
    return WS_VISIBLE | WS_CHILD | BS_CHECKBOX;
}


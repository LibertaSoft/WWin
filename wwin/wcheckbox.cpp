#include "wcheckbox.h"

WCheckBox::WCheckBox(WWidget *parent)
    : WAbstractButton(parent)
{
    this->initWndClass(L"BUTTON");
    this->setCheckable(true);
}

WCheckBox::WCheckBox(const WString title, WWidget *parent)
    : WAbstractButton(parent)
{
    this->setTitle( title );
    this->initWndClass(L"BUTTON");
    this->setCheckable(true);
}

int WCheckBox::style()
{
    return WS_VISIBLE | WS_CHILD | BS_CHECKBOX;
}


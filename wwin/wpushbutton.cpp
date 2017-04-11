#include "wpushbutton.h"

int WPushButton::style()
{
    return WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
}

WPushButton::WPushButton(WWidget *parent)
    : WWidget(parent)
{
    _className = "BUTTON";
    this->init();
}
WPushButton::WPushButton(std::string title, WWidget *parent)
    : WWidget(parent)
{
    _className = "BUTTON";
    _title = title;
    this->init();
}


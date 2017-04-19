#include "wpushbutton.h"

#include "wwin/wmessagebox.h"
#include <iostream>

int WPushButton::style()
{
    return BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD;
}

bool WPushButton::mouseEvent(WMouseEvent *e)
{
    for(auto callback : _callbacks){
        callback(e);
    }

    e->accept();
    return e->isAccepted();
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

int WPushButton::on_click(std::function<void(WMouseEvent*)> callback)
{
    _callbacks.push_back( callback );
    return _callbacks.size();
}


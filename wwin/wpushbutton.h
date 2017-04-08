#ifndef WPUSHBUTTON_H
#define WPUSHBUTTON_H

#include "wwin/wwidget.h"

class WPushButton : public WWidget
{

    int style() override;
public:
    WPushButton(WWidget* parent = nullptr);
    WPushButton(std::string title, WWidget* parent = nullptr);
};

#endif // WPUSHBUTTON_H

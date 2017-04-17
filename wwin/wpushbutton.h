#ifndef WPUSHBUTTON_H
#define WPUSHBUTTON_H

#include <functional>
#include <vector>
#include "wwin/wwidget.h"

class WPushButton : public WWidget
{
private:
    std::vector< std::function<void()> > _callbacks;

    int style() override;

protected:
    virtual bool mouseEvent(WMouseEvent *e);
public:
    WPushButton(WWidget* parent = nullptr);
    WPushButton(std::string title, WWidget* parent = nullptr);
    int on_click( std::function<void()> callback );
};

#endif // WPUSHBUTTON_H

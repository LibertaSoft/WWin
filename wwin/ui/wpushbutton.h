#ifndef WPUSHBUTTON_H
#define WPUSHBUTTON_H

#include <functional>
#include <vector>
#include "wwin/ui/wabstractbutton.h"

/**
 * @brief WPushButton Класс самой обычной кнопки
 */
class WPushButton : public WAbstractButton
{
private:
    int style() override;

public:
    WPushButton(WWidget* parent = nullptr);
    WPushButton(WString title, WWidget* parent = nullptr);
};

#endif // WPUSHBUTTON_H

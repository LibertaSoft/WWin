#ifndef WRADIOBUTTON_H
#define WRADIOBUTTON_H

#include "wwin/ui/wabstractbutton.h"

/*!
 * \brief WRadioButton Класс виджета переключателя c текстовой надписью
 */
class WRadioButton : public WAbstractButton
{
public:
    WRadioButton(WWidget *parent);
    WRadioButton(const WString title, WWidget *parent);

    // WWidget interface
protected:
    virtual int style() override;
};

#endif // WRADIOBUTTON_H

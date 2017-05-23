#ifndef XOFIELD_H
#define XOFIELD_H

#include "wwin/ui/wwidget.h"

class XOField : public WWidget
{
public:
    XOField(WWidget* parent = nullptr);

    // WWidget interface
protected:
    virtual int style() override;
    virtual bool paintEvent(WPaintEvent *e) override;
};

#endif // XOFIELD_H

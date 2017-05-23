#include "xofield.h"

#include <wwin/wpainter.h>

XOField::XOField(WWidget *parent)
    : WWidget(parent)
{

}

int XOField::style()
{
    return WS_CHILD | WS_BORDER | WS_VISIBLE;
}

bool XOField::paintEvent(WPaintEvent *e)
{
    WPainter p;

    p.begin(this);

    WRect r = e->rect();

    p.drawLine(10,10,50,50);
    p.drawLine(r.right(),r.top(),r.left(),r.bottom());
    p.drawLine(r.left(),r.top(),r.right(),r.bottom());

    p.end();
}


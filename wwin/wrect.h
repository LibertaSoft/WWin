#ifndef WRECT_H
#define WRECT_H

#include "wwin/wpoint.h"
#include "wwin/wsize.h"

class WRect
{
    int _left   = 0;
    int _top    = 0;
    int _width  = 0;
    int _height = 0;

public:
    WRect();
    WRect(const WPoint& topLeft, const WPoint& bottomRight);
    WRect(const WPoint& topLeft, const WSize& size);
    WRect(int left, int top, int width, int height);

    bool isEmpty() const;
    bool isValid() const;
    bool isNull() const;

    int left() const;
    void setLeft(int left);

    int top() const;
    void setTop(int top);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    int right() const;
    int bottom() const;
};

#endif // WRECT_H

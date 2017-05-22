#ifndef WRECT_H
#define WRECT_H

#include "wwin/wpoint.h"
#include "wwin/wsize.h"

class WRect
{
    int _left   = 0;
    int _top    = 0;
    int _right  = 0;
    int _bottom = 0;

public:
    WRect();
    WRect(const WPoint& topLeft, const WPoint& bottomRight);
    WRect(const WPoint& topLeft, const WSize& size);
    WRect(int left, int top, int width, int height);

    bool isEmpty() const;
    bool isValid() const;
    bool isNull() const;

    WPoint topLeft() const;
    void setTopLeft(const WPoint& position);

    WPoint topRight() const;
    void setTopRight(const WPoint& position);

    WPoint bottomLeft() const;
    void setBottomLeft(const WPoint& position);

    WPoint bottomRight() const;
    void setBottomRight(const WPoint& position);

    void setRect(int x, int y, int width, int height);
    void setSize(const WSize& size);

    void getRect(int *x, int *y, int *width, int *height) const;
    void getCoords(int *x1, int *y1, int *x2, int *y2) const;

    WPoint center() const;
    void moveCenter(const WPoint& position);

    void moveTo(int x, int y);
    void moveTo(const WPoint& pos);

    void moveLeft(int x);
    void moveRight(int x);
    void moveTop(int y);
    void moveBottom(int y);

    int left() const;
    void setLeft(int left);

    int top() const;
    void setTop(int top);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    int right() const;
    void setRight(int right);

    int bottom() const;
    void setBottom(int bottom);
};

#endif // WRECT_H

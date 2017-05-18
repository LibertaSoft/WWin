#include "wrect.h"

int WRect::left() const
{
    return _left;
}

void WRect::setLeft(int x)
{
    _left = x;
}

int WRect::top() const
{
    return _y;
}

void WRect::setTop(int y)
{
    _y = y;
}

int WRect::width() const
{
    return _width;
}

void WRect::setWidth(int width)
{
    _width = width;
}

int WRect::height() const
{
    return _height;
}

void WRect::setHeight(int height)
{
    _height = height;
}

WRect::WRect()
{}

WRect::WRect(const WPoint &topLeft, const WPoint &bottomRight)
{
    _left = topLeft.x();
    _top  = topLeft.y();
    _width = bottomRight.x() - topLeft.x();
    _height = bottomRight.y() - topLeft.y();
}

WRect::WRect(int left, int top, int width, int height)
{
    _left   = left;
    _top    = top;
    _width  = width;
    _height = height;
}

bool WRect::isEmpty() const
{
    return ( this->left() > this->right() || this->top() > this->bottom() );
}

bool WRect::isValid() const
{
    return ( this->left() <= this->right() && this->top() <= this->bottom() );
}

bool WRect::isNull() const
{
    return ( this->left() == this->right() && this->top() == this->bottom() );
}



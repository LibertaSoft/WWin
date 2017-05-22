#include "wrect.h"
#include <cassert>

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
    return _top;
}

void WRect::setTop(int y)
{
    _top = y;
}

int WRect::width() const
{
    return this->right() - this->left();
}

void WRect::setWidth(int width)
{
    _right = this->left() + width;
}

int WRect::height() const
{
    return this->bottom() - this->top();
}

void WRect::setHeight(int height)
{
    _bottom = this->top() + height;
}

int WRect::right() const
{
    return _right;
}

void WRect::setRight(int right)
{
    _right = right;
}

int WRect::bottom() const
{
    return _bottom;
}

void WRect::setBottom(int bottom)
{
    _bottom = bottom;
}

WRect::WRect()
{}

WRect::WRect(const WPoint &topLeft, const WPoint &bottomRight)
{
    this->setRect( topLeft.x(), topLeft.y(), bottomRight.x() - topLeft.x(), bottomRight.y() - topLeft.y() );
}

WRect::WRect(int left, int top, int width, int height)
{
    this->setRect( left, top, width, height );
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

WPoint WRect::topLeft() const
{
    return WPoint( this->left(), this->top() );
}

void WRect::setTopLeft(const WPoint &position)
{
    this->setTop( position.y() );
    this->setLeft( position.x() );
}

WPoint WRect::topRight() const
{
    return WPoint( this->right(), this->top() );
}

void WRect::setTopRight(const WPoint &position)
{
    this->setTop( position.y() );
    this->setRight( position.x() );
}

WPoint WRect::bottomLeft() const
{
    return WPoint( this->left(), this->bottom() );
}

void WRect::setBottomLeft(const WPoint &position)
{
    this->setBottom( position.y() );
    this->setLeft( position.x() );
}

WPoint WRect::bottomRight() const
{
    return WPoint( this->right(), this->bottom() );
}

void WRect::setBottomRight(const WPoint &position)
{
    this->setBottom( position.y() );
    this->setRight( position.x() );
}

void WRect::setRect(int x, int y, int width, int height)
{
    this->setLeft( x );
    this->setTop( y );
    this->setWidth( width );
    this->setHeight( height );
}

void WRect::setSize(const WSize &size)
{
    this->setWidth( size.width() );
    this->setHeight( size.height() );
}

void WRect::getRect(int *x, int *y, int *width, int *height) const
{
    assert( x != nullptr );
    assert( y != nullptr );
    assert( width != nullptr );
    assert( height != nullptr );

    *x = this->left();
    *y = this->top();
    *width  = this->width();
    *height = this->height();
}

void WRect::getCoords(int *x1, int *y1, int *x2, int *y2) const
{
    assert( x1 != nullptr );
    assert( y1 != nullptr );
    assert( x2 != nullptr );
    assert( y2 != nullptr );

    *x1 = this->left();
    *y1 = this->top();
    *x2 = this->right();
    *y2 = this->bottom();
}

WPoint WRect::center() const
{
    WPoint p;
    p.setX( this->left() + (this->width()  / 2) );
    p.setY( this->top()  + (this->height() / 2) );
    return p;
}

void WRect::moveCenter(const WPoint &position)
{
    int width  = this->width();
    int height = this->height();
    this->setLeft( position.x() - (width  / 2) );
    this->setTop(  position.y() - (height / 2) );
    this->setRight(  this->left() + width );
    this->setBottom( this->top()  + height );
}

void WRect::moveTo(int x, int y)
{
    int width = this->width();
    int height = this->height();
    this->setLeft( x );
    this->setTop( y );
    this->setWidth( width );
    this->setHeight( height );
}

void WRect::moveTo(const WPoint &pos)
{
    this->moveTo( pos.x(), pos.y() );
}

void WRect::moveLeft(int x)
{
    this->setLeft(  this->left() - x );
    this->setRight( this->right() - x );
}

void WRect::moveRight(int x)
{
    this->setLeft(  this->left() + x );
    this->setRight( this->right() + x );
}

void WRect::moveTop(int y)
{
    this->setTop( this->top() - y );
    this->setBottom( this->bottom() - y );
}

void WRect::moveBottom(int y)
{
    this->setTop( this->top() + y );
    this->setBottom( this->bottom() + y );
}



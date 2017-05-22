#include "wrect.h"
#include <cassert>

/*!
 * \brief WRect::left получить левую границу прямоугольника
 * \return
 */
int WRect::left() const
{
    return _left;
}

/*!
 * \brief WRect::setLeft установить левую границу прямоугольника
 * \param x
 */
void WRect::setLeft(int x)
{
    _left = x;
}

/*!
 * \brief WRect::top получить верхнюю границу прямоугольника
 * \return
 */
int WRect::top() const
{
    return _top;
}

/*!
 * \brief WRect::setTop установить верхнюю границу прямоугольника
 * \param y
 */
void WRect::setTop(int y)
{
    _top = y;
}

/*!
 * \brief WRect::width получить ширину прямоугольника
 * \return
 */
int WRect::width() const
{
    return this->right() - this->left();
}

/*!
 * \brief WRect::setWidth установить ширину прямоугольника
 * \param width
 */
void WRect::setWidth(int width)
{
    _right = this->left() + width;
}

/*!
 * \brief WRect::height получить высоту прямоугольника
 * \return
 */
int WRect::height() const
{
    return this->bottom() - this->top();
}

/*!
 * \brief WRect::setHeight установить высоту прямоугольника
 * \param height
 */
void WRect::setHeight(int height)
{
    _bottom = this->top() + height;
}

/*!
 * \brief WRect::right получить правую границу прямоугольника
 * \return
 */
int WRect::right() const
{
    return _right;
}

/*!
 * \brief WRect::setRight установить правую границу прямоугольника
 * \param right
 */
void WRect::setRight(int right)
{
    _right = right;
}

/*!
 * \brief WRect::bottom получить нижнюю границу прямоугольника
 * \return
 */
int WRect::bottom() const
{
    return _bottom;
}

/*!
 * \brief WRect::setBottom установить нижнюю границу прямоугольника
 * \param bottom
 */
void WRect::setBottom(int bottom)
{
    _bottom = bottom;
}

/*!
 * \brief WRect::WRect создать пустой прямоугольник с размерами равными нулю
 */
WRect::WRect()
{}

/*!
 * \brief WRect::WRect создать прямоугольник на основе уже существующего
 * \param rect
 */
WRect::WRect(const WRect &rect)
{
    this->setRect( rect.left(), rect.top(), rect.width(), rect.height() );
}

/*!
 * \brief WRect::WRect создать прямоугольник с указанными размерами
 * \param topLeft
 * \param bottomRight
 */
WRect::WRect(const WPoint &topLeft, const WPoint &bottomRight)
{
    this->setRect( topLeft.x(), topLeft.y(), bottomRight.x() - topLeft.x(), bottomRight.y() - topLeft.y() );
}

/*!
 * \brief WRect::WRect создать прямоугольник с указанными размерами
 * \param left
 * \param top
 * \param width
 * \param height
 */
WRect::WRect(int left, int top, int width, int height)
{
    this->setRect( left, top, width, height );
}

/*!
 * \brief WRect::isEmpty возвращает true если левая граница больше правой
 * или верхняя граница меньше левой
 * \return
 */
bool WRect::isEmpty() const
{
    return ( this->left() > this->right() || this->top() > this->bottom() );
}

/*!
 * \brief WRect::isValid возвращает true если левая граница меньше или равна правой
 * и верхняя граница меньше или равна нижней
 * \return
 */
bool WRect::isValid() const
{
    return ( this->left() <= this->right() && this->top() <= this->bottom() );
}

bool WRect::isNull() const
{
    return ( this->left() == this->right() && this->top() == this->bottom() );
}

/*!
 * \brief WRect::topLeft получить верхнюю левую точку прямоугольника
 * \return
 */
WPoint WRect::topLeft() const
{
    return WPoint( this->left(), this->top() );
}

/*!
 * \brief WRect::setTopLeft установить верхнюю левую точку прямоугольника
 * \param position
 */
void WRect::setTopLeft(const WPoint &position)
{
    this->setTop( position.y() );
    this->setLeft( position.x() );
}

/*!
 * \brief WRect::topRight получить верхнюю правую точку прямоугольника
 * \return
 */
WPoint WRect::topRight() const
{
    return WPoint( this->right(), this->top() );
}

/*!
 * \brief WRect::setTopRight установить верхнюю правую точку прямоугольника
 * \param position
 */
void WRect::setTopRight(const WPoint &position)
{
    this->setTop( position.y() );
    this->setRight( position.x() );
}

/*!
 * \brief WRect::bottomLeft получить нижнюю левую точку прямоугольника
 * \return
 */
WPoint WRect::bottomLeft() const
{
    return WPoint( this->left(), this->bottom() );
}

/*!
 * \brief WRect::setBottomLeft установить нижнюю левую точку прямоугольника
 * \param position
 */
void WRect::setBottomLeft(const WPoint &position)
{
    this->setBottom( position.y() );
    this->setLeft( position.x() );
}

/*!
 * \brief WRect::bottomRight получить нижнюю правую точку прямоугольника
 * \return
 */
WPoint WRect::bottomRight() const
{
    return WPoint( this->right(), this->bottom() );
}

/*!
 * \brief WRect::setBottomRight установить нижнюю правую точку прямоугольника
 * \param position
 */
void WRect::setBottomRight(const WPoint &position)
{
    this->setBottom( position.y() );
    this->setRight( position.x() );
}

/*!
 * \brief WRect::setRect установить новые значения позиции и размера для прямоугольника
 * \param x
 * \param y
 * \param width
 * \param height
 */
void WRect::setRect(int x, int y, int width, int height)
{
    this->setLeft( x );
    this->setTop( y );
    this->setWidth( width );
    this->setHeight( height );
}

/*!
 * \brief WRect::setSize установить размер прямоугольника
 * \param size
 */
void WRect::setSize(const WSize &size)
{
    this->setWidth( size.width() );
    this->setHeight( size.height() );
}

/*!
 * \brief WRect::getRect получить позицию и размер прямоугольника
 * \param x
 * \param y
 * \param width
 * \param height
 */
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

/*!
 * \brief WRect::getCoords получить координаты прямоугольника
 * \param x1
 * \param y1
 * \param x2
 * \param y2
 */
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

/*!
 * \brief WRect::center возвращает точку - центр прямоугольника
 * \return
 */
WPoint WRect::center() const
{
    WPoint p;
    p.setX( this->left() + (this->width()  / 2) );
    p.setY( this->top()  + (this->height() / 2) );
    return p;
}

/*!
 * \brief WRect::moveCenter перемещает центр прямоугольника в указанную точку
 * \param position
 */
void WRect::moveCenter(const WPoint &position)
{
    int width  = this->width();
    int height = this->height();
    this->setLeft( position.x() - (width  / 2) );
    this->setTop(  position.y() - (height / 2) );
    this->setRight(  this->left() + width );
    this->setBottom( this->top()  + height );
}

/*!
 * \brief WRect::moveTo перемещает левый верхний угол прямоугольника в указанную точку
 * \param x
 * \param y
 */
void WRect::moveTo(int x, int y)
{
    int width = this->width();
    int height = this->height();
    this->setLeft( x );
    this->setTop( y );
    this->setWidth( width );
    this->setHeight( height );
}

/*!
 * \brief WRect::moveTo перемещает прямоугольник в указанную позицию
 * \param pos - позиция в которую будет перемещён левый верхний угол прямоугольника
 */
void WRect::moveTo(const WPoint &pos)
{
    this->moveTo( pos.x(), pos.y() );
}

/*!
 * \brief WRect::moveLeft сдвигает прямоугольник влево, на указанное смещение
 * \param x
 */
void WRect::moveLeft(int x)
{
    this->setLeft(  this->left() - x );
    this->setRight( this->right() - x );
}

/*!
 * \brief WRect::moveRight сдвигает прямоугольник вправо, на указанное смещение
 * \param x
 */
void WRect::moveRight(int x)
{
    this->setLeft(  this->left() + x );
    this->setRight( this->right() + x );
}

/*!
 * \brief WRect::moveTop сдвигает прямоугольник вверх, на указанное смещение
 * \param y
 */
void WRect::moveTop(int y)
{
    this->setTop( this->top() - y );
    this->setBottom( this->bottom() - y );
}

/*!
 * \brief WRect::moveBottom сдвигает прямоугольник вниз, на указанное смещение
 * \param y
 */
void WRect::moveBottom(int y)
{
    this->setTop( this->top() + y );
    this->setBottom( this->bottom() + y );
}

/*!
 * \brief WRect::translate  сдвигает прямоугольник на указанное смещение
 * \param dx
 * \param dy
 */
void WRect::translate(int dx, int dy)
{
    this->setTop(   this->top()    + dy );
    this->setRight( this->right()  + dx );
    this->setBottom(this->bottom() + dy );
    this->setLeft(  this->left()   + dx );
}

/*!
 * \brief WRect::translate сдвигает прямоугольник на указанное смещение
 * \param offset
 */
void WRect::translate(const WPoint &offset)
{
    this->setTop(   this->top()    + offset.y() );
    this->setRight( this->right()  + offset.x() );
    this->setBottom(this->bottom() + offset.y() );
    this->setLeft(  this->left()   + offset.x() );
}

/*!
 * \brief WRect::contains возвращает true в случае если точка находится внутри прямоугольника
 * \param x
 * \param y
 * \param proper если proper == true то возвращает true только в том случае если точка находится
 * внутри прямоугольника а не на границе.
 * \return
 */
bool WRect::contains(int x, int y, bool proper) const
{
    if( proper ) {
        if( x < this->left() || x > this->right() || y < this->top() || y > this->bottom() ){
            return false;
        }
    } else {
        if( x <= this->left() || x >= this->right() || y <= this->top() || y >= this->bottom() ){
            return false;
        }
    }
    return true;
}

/*!
 * \brief WRect::contains возвращает true в случае если точка находится внутри прямоугольника
 * \param point
 * \param proper если proper == true то возвращает true только в том случае если точка находится
 * внутри прямоугольника а не на границе.
 * \return
 */
bool WRect::contains(const WPoint &point, bool proper) const
{
    return this->contains( point.x(), point.y(), proper );
}

/*!
 * \brief WRect::contains возвращает true в случае если переданный прямоугольник вписывается внутрь.
 * \param rectangle
 * \param proper если proper == true то возвращает true только в том случае если точка находится
 * внутри прямоугольника а не на границе.
 * \return
 */
bool WRect::contains(const WRect &rectangle, bool proper) const
{
    if( this->contains( rectangle.topLeft() , proper) ){
        if( this->contains( rectangle.bottomRight() , proper) ){
            return true;
        }
    }
    return false;
}
/*!
 * \brief WRect::translated смещает прямоугольник на указанное смещение
 * \param dx
 * \param dy
 * \return
 */
WRect WRect::translated(int dx, int dy) const
{
    WRect translated;
    translated.setTop(   this->top()    + dy );
    translated.setRight( this->right()  + dx );
    translated.setBottom(this->bottom() + dy );
    translated.setLeft(  this->left()   + dx );
    return translated;
}

/*!
 * \brief WRect::translated смещает прямоугольник на указанную величину
 * \param offset - смещение
 * \return
 */
WRect WRect::translated(const WPoint &offset) const
{
    WRect translated;
    translated.setTop(   this->top()    + offset.y() );
    translated.setRight( this->right()  + offset.x() );
    translated.setBottom(this->bottom() + offset.y() );
    translated.setLeft(  this->left()   + offset.x() );
    return translated;
}

/*!
 * \brief WRect::transposed меняет местами ширину и высоту прямоугольника
 * \return возвращает копию прямоугольника с поменняными местами шириной и высотой
 * \code
    WRect r(15, 51, 42, 24);
    r = r.transposed(); // r == {15, 51, 24, 42}
 * \endcode
 */
WRect WRect::transposed() const
{
    WRect transposed(*this);
    transposed.setWidth( this->height() );
    transposed.setHeight( this->width() );
    return transposed;
}

/*!
 * \brief WRect::normalized возвращает прямоугольник с не отрицательными width() и height()
 * если width() меньше нуля - меняет местами left() и right() аналогично и с height()
 * \return
 */
WRect WRect::normalized() const
{
    WRect normalized(*this);
    if( normalized.width() < 0 ) {
        normalized.setLeft( this->right() );
        normalized.setRight( this->left() );
    }
    if( normalized.height() < 0 ) {
        normalized.setTop( this->bottom() );
        normalized.setBottom( this->top() );
    }
    return normalized;
}

/*!
 * \brief WRect::united возвращяет прямоугольник охватывающий оба прямоугольника
 * \param rectangle
 * \return
 */
WRect WRect::united(const WRect &rectangle) const
{
    WRect united;
    united.setTop( this->top() < rectangle.top() ? this->top() : rectangle.top() );
    united.setRight( this->right() < rectangle.right() ? this->right() : rectangle.right() );
    united.setBottom( this->bottom() < rectangle.bottom() ? this->bottom() : rectangle.bottom() );
    united.setLeft( this->left() < rectangle.left() ? this->left() : rectangle.left() );
    return united;
}



#include "wpoint.h"

/*!
 * \brief WPoint::x получить значение x координаты
 * \return
 */
int WPoint::x() const
{
    return _x;
}

/*!
 * \brief WPoint::setX установить значение x координаты
 * \param x
 */
void WPoint::setX(int x)
{
    _x = x;
}

/*!
 * \brief WPoint::rx получить ссылку на x координату
 * \return
 */
int &WPoint::rx()
{
    return _x;
}

/*!
 * \brief WPoint::y получить значение y координаты
 * \return
 */
int WPoint::y() const
{
    return _y;
}

/*!
 * \brief WPoint::setY установить значение y координаты
 * \param y
 */
void WPoint::setY(int y)
{
    _y = y;
}

/*!
 * \brief WPoint::ry получить ссылку на y координату
 * \return
 */
int &WPoint::ry()
{
    return _y;
}

/*!
 * \brief WPoint::isNull возвращает True в случае если x и y координаты равны нулю
 * \return
 */
bool WPoint::isNull() const
{
    return ( ( this->x() == 0 ) && ( this->y() == 0 ) );
}

/*!
 * \brief WPoint::operator *= оператор умножения на скаляр
 * \param factor
 * \return
 */
WPoint &WPoint::operator*=(float factor)
{
    this->setX( this->x() * factor );
    this->setY( this->y() * factor );
    return *this;
}

/*!
 * \brief WPoint::operator *= оператор умножения на скаляр
 * \param factor
 * \return
 */
WPoint &WPoint::operator*=(double factor)
{
    this->setX( this->x() * factor );
    this->setY( this->y() * factor );
    return *this;
}

/*!
 * \brief WPoint::operator *= оператор умножения на скаляр
 * \param factor
 * \return
 */
WPoint &WPoint::operator*=(int factor)
{
    this->setX( this->x() * factor );
    this->setY( this->y() * factor );
    return *this;
}

/*!
 * \brief WPoint::operator += оператор суммы
 * \param point
 * \return
 */
WPoint &WPoint::operator+=(const WPoint &point)
{
    this->setX( point.x() + this->x() );
    this->setY( point.y() + this->y() );
    return *this;
}

/*!
 * \brief WPoint::operator -= оператор разности
 * \param point
 * \return
 */
WPoint &WPoint::operator-=(const WPoint &point)
{
    this->setX( this->x() - point.x() );
    this->setY( this->y() - point.y() );
    return *this;
}

/*!
 * \brief WPoint::operator /= оператор деления
 * \param divisor
 * \return
 */
WPoint &WPoint::operator/=(double divisor)
{
    if( divisor != 0 ){
        this->setX( this->x() / divisor );
        this->setY( this->y() / divisor );
    }
    return *this;
}

/*!
 * \brief WPoint::WPoint Конструктор WPoint с координатами(0,0)
 */
WPoint::WPoint()
{}

/*!
 * \brief WPoint::WPoint конструктор WPoint с координатами(x,y)
 * \param x - координата
 * \param y - координата
 */
WPoint::WPoint(int x, int y)
    : _x(x), _y(y)
{}


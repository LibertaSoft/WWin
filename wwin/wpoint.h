#ifndef WPOINT_H
#define WPOINT_H

/*!
 * \brief WPoint класс определяет двумерную точку integer типа.
 */
class WPoint
{
private:
    int _x = 0;
    int _y = 0;

public:
    WPoint();
    WPoint(int x, int y);

    int x() const;
    void setX(int x);
    int& rx();

    int y() const;
    void setY(int y);
    int& ry();

    bool isNull() const;

    WPoint& operator*=(float factor);
    WPoint& operator*=(double factor);
    WPoint& operator*=(int factor);
    WPoint& operator+=(const WPoint & point);
    WPoint& operator-=(const WPoint & point);
    WPoint& operator/=(double divisor);

    /// \todo friend operators
};

#endif // WPOINT_H

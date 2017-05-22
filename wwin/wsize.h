#ifndef WSIZE_H
#define WSIZE_H

/*!
 * \brief Класс WSize определяет размер двумерного объекта.
 *
 * Класс WSize определяет Размер двумерного объекта, используя int тип.
 * Размер определяется width() и height().
 * Он может быть установлен в конструкторе
 * и изменён с помощью setWidth(), setHeight(), или scale() функциях,
 * или, используя арифметические операторы.
 *
 * Размером также можно манипулировать непосредственно путем
 * получения ссылок на ширину и высоту с помощью rwidth() и rheight() функций.
 * Наконец, ширина и высота могут быть заменены с помощью метода transpose().
 *
 * Метод isValid() определяет правильный ли размер
 * (допустимый размер определяется шириной и высотой больше или равной нулю).
 * isEmpty() функция возвращает True, если ширина и высота меньше или равна нулю,
 * в то время как функция isNull() возвращает True, только если и ширина и высота равны нулю.
 *
 * Используйте метод expandedTo, чтобы получить Размер,
 * который имеет максимальную высоту и ширину данного размера и данного размера.
 *
 * Аналогично, boundedTo (функция) возвращает Размер,
 * который имеет минимальную высоту и ширину данного размера и данного размера.
 */
class WSize
{
public:
    enum class AspectRatioMode : int {
        IgnoreAspectRatio = 0,
        KeepAspectRatio = 1,
        KeepAspectRatioByExpanding = 2
    };

private:
    int _width  = 0;
    int _height = 0;

public:
    WSize();
    WSize(const int width, const int height);

    int width() const;
    void setWidth(int width);
    int &rwidth();

    int height() const;
    void setHeight(int height);
    int& rheight();

    void scale(int width, int height, WSize::AspectRatioMode mode = WSize::AspectRatioMode::IgnoreAspectRatio);
    void scale(const WSize &size, WSize::AspectRatioMode mode = WSize::AspectRatioMode::IgnoreAspectRatio);

    void transpose();
    WSize transposed() const;

    WSize boundedTo(const WSize &otherSize) const;
    WSize expandedTo(const WSize &otherSize) const;

    bool isEmpty() const;
    bool isNull() const;
    bool isValid() const;

    WSize& operator*=(double factor);
    WSize& operator+=(const WSize &size);
    WSize& operator-=(const WSize &size);
    WSize& operator/=(double divisor);

    friend inline bool operator==(const WSize& s1, const WSize& s2);
    friend inline bool operator!=(const WSize& s1, const WSize& s2);
    friend inline const WSize operator+(const WSize& s1, const WSize& s2);
    friend inline const WSize operator-(const WSize& s1, const WSize& s2);
    friend inline const WSize operator*(const WSize& s1, double factor);
    friend inline const WSize operator*(double factor, const WSize& s2);
    friend inline const WSize operator/(const WSize& s1, double divisor);
};

#endif // WSIZE_H

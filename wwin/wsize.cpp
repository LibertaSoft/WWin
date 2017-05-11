#include "wsize.h"

/*!
 * \brief WSize::width получить текущую ширину
 * \return текущая ширина
 */
int WSize::width() const
{
    return _width;
}

/*!
 * \brief WSize::setWidth установить новую ширину
 * \param width - новая ширина
 */
void WSize::setWidth(int width)
{
    _width = width;
}

/*!
 * \brief WSize::rwidth получить ссылку на ширину.
 *
 * Использование ссылки позволяет сделать такие вещи:
 * \code
 * WSize size(100, 10);
 * size.rwidth() += 5;
 *
 * // Теперь размер (105,10)
 * \endcode
 * \return ссылка на ширину
 */
int &WSize::rwidth()
{
    return _width;
}

/*!
 * \brief WSize::height получить высоту
 * \return текущая высота
 */
int WSize::height() const
{
    return _height;
}

/*!
 * \brief WSize::setHeight установить новую высоту
 * \param height - высота
 */
void WSize::setHeight(int height)
{
    _height = height;
}

/*!
 * \brief WSize::rwidth получить ссылку на высоту.
 *
 * Использование ссылки позволяет сделать такие вещи:
 * \code
 * WSize size(100, 10);
 * size.rheight() += 5;
 *
 * // Теперь размер (100,15)
 * \endcode
 * \return ссылка на высоту
 */
int &WSize::rheight()
{
    return _height;
}

/*!
 * \brief WSize::scale Масштабирует размеры прямоугольник до заданной ширины и высоты,
 * в соответствии с заданным режимом
 * \param width - ширина
 * \param height - высота
 * \param mode - режим масштабирования
 */
void WSize::scale(int width, int height, WSize::AspectRatioMode mode)
{
    this->scale( WSize(width, height), mode );
}

/*!
 * \brief WSize::scale Масштабирует размеры прямоугольник до заданной ширины и высоты,
 * в соответствии с заданным режимом
 * \param width - ширина
 * \param height - высота
 * \param mode - режим масштабирования
 *
 * \todo fixme Неправильное масштабирование
 *
 * Если режим IgnoreAspectRatio, размер устанавливается как (width, height).
 * Если режим KeepAspectRatio, текущий размер масштабируется до прямоугольника
 * где наибольшая из сторон умещается в (width, height), сохраняя пропорции.
 * Если режим KeepAspectRatioByExpanding, текущий размер масштабируется до прямоугольника
 * наименьшая из сторон умещается в (width, height), а вторая выходит за границы, сохраняя пропорции.
 *
 \code
    WSize t1(10, 12);
    t1.scale(60, 60, WSize::AspectRatioMode::IgnoreAspectRatio);
    // t1 is (60, 60)

    WSize t2(10, 12);
    t2.scale(60, 60, WSize::AspectRatioMode::KeepAspectRatio);
    // t2 is (50, 60)

    WSize t3(10, 12);
    t3.scale(60, 60, WSize::AspectRatioMode::KeepAspectRatioByExpanding);
    // t3 is (60, 72)
 \endcode
 */
void WSize::scale(const WSize &size, WSize::AspectRatioMode mode)
{
    int ratio = 1;
    int min = 0, max = 0;
    if( this->width() < this->height() ) {
        min = this->width();
        max = this->height();
    } else {
        max = this->width();
        min = this->height();
    }

    if( WSize::AspectRatioMode::IgnoreAspectRatio == mode ){
        ratio = 1;
    } else if( WSize::AspectRatioMode::KeepAspectRatio == mode ) {
        ratio = min / max;
    } else if( WSize::AspectRatioMode::KeepAspectRatioByExpanding == mode ) {
        ratio = max / min;
    }

    this->setWidth( size.width() * ratio );
    this->setHeight( size.height() * ratio );
}

/*!
 * \brief WSize::transpose меняет местами ширину и высоту
 */
void WSize::transpose()
{
    int tmp = this->width();
    this->setWidth( this->height() );
    this->setHeight( tmp );
}

/*!
 * \brief WSize::transposed возвращает размер с поменяными местами шириной и высотой
 */
WSize WSize::transposed() const
{
    return WSize( this->height(), this->width() );
}

/*!
 * \brief WSize::boundedTo Возвращает Размер, ширина и высота которого
 * равна минимальной ширине и высоте из текущего размера и otherSize.
 * \param otherSize сравниваемый размер
 * \return WSize
 */
WSize WSize::boundedTo(const WSize &otherSize) const
{
    int minWidth = ( this->width() < otherSize.width() )? this->width() : otherSize.width();
    int minHeight = ( this->height() < otherSize.height() )? this->height() : otherSize.height();
    return WSize( minWidth, minHeight );
}

/*!
 * \brief WSize::expandedTo Возвращает Размер, ширина и высота которого
 * равна максимальной ширине и высоте из текущего размера и otherSize.
 * \param otherSize сравниваемый размер
 * \return WSize
 */
WSize WSize::expandedTo(const WSize &otherSize) const
{
    int maxWidth = ( this->width() > otherSize.width() )? this->width() : otherSize.width();
    int maxHeight = ( this->height() > otherSize.height() )? this->height() : otherSize.height();
    return WSize( maxWidth, maxHeight );
}

/*!
 * \brief WSize::isEmpty возвращает True в случае если высота и ширина больше или равны нулю
 * Во всех остальных случаях возвращает False
 * \return bool
 */
bool WSize::isEmpty() const
{
    return ( (this->width() <= 0) && (this->height() <= 0) );
}

/*!
 * \brief WSize::isNull возвращает True в случае если высота и ширина равны нулю.
 * Во всех остальных случаях возвращает False
 * \return bool
 */
bool WSize::isNull() const
{
    return ( (this->width() == 0) && (this->height() == 0) );
}

/*!
 * \brief WSize::isValid возвращает True в случае если высота и ширина больше или равны нулю.
 * Во всех остальных случаях возвращает False
 * \return bool
 */
bool WSize::isValid() const
{
    return ( (this->width() >= 0) && (this->height() >= 0) );
}

/*!
 * \brief WSize::operator *= умножает ширину и высоту на factor и возвращает ссылку на размер
 * \param factor множитель
 * \return возвращает ссылку на WSize
 */
WSize &WSize::operator*=(double factor)
{
    this->setWidth( this->width() * factor );
    this->setHeight( this->height() * factor );
    return *this;
}

/*!
 * \brief WSize::operator += прибавляет к текущему размеру переданный и возвращает ссылку на размер
 * \param size прибавляемый размер
 * \return WSize&
 */
WSize &WSize::operator+=(const WSize &size)
{
    this->setWidth( this->width() + size.width() );
    this->setHeight( this->height() + size.height() );
    return *this;
}

/*!
 * \brief WSize::operator -= вычитает из текущего размера переданный и возвращает ссылку на размер
 * \param size
 * \return WSize&
 */
WSize &WSize::operator-=(const WSize &size)
{
    this->setWidth( this->width() - size.width() );
    this->setHeight( this->height() - size.height() );
    return *this;
}

/*!
 * \brief WSize::operator /= делит ширину и высоту на переданный делитель и возвращет ссылку на размер
 * \warning если делитель равен нулю, деление не происходит
 * \param divisor
 * \return WSize&
 */
WSize &WSize::operator/=(double divisor)
{
    if( divisor != 0 ) {
        this->setWidth( this->width() / divisor );
        this->setHeight( this->height() / divisor );
    }
    return *this;
}

/*!
 * \brief operator * умножает ширину и высоту s2 на factor и возвращает WSize
 * \param factor - множитель
 * \param s2 - умножаемый размер
 * \return WSize = s2 * factor
 */
inline const WSize operator*(double factor, const WSize &s2)
{
    WSize size;
    size.setWidth( s2.width() * factor );
    size.setHeight( s2.height() * factor );
    return size;
}

/*!
 * \brief operator / делит ширину и высоту s1 на divisor и возвращает WSize
 * \param s1 - делимый размер
 * \param divisor - делитель
 * \return WSize = s1.width() / divisor и s1.height() / divisor
 */
inline const WSize operator/(const WSize &s1, double divisor)
{
    if( divisor == 0 ){
        return WSize(0,0);
    }
    WSize size;
    size.setWidth( s1.width() / divisor );
    size.setHeight( s1.height() / divisor );
    return size;
}

/*!
 * \brief operator * умножает ширину и высоту s1 на factor
 * \param s1 - WSize размер
 * \param factor - множитель
 * \return WSize
 */
inline const WSize operator*(const WSize &s1, double factor)
{
    WSize size;
    size.setWidth( s1.width() * factor );
    size.setHeight( s1.height() * factor );
    return size;
}

/*!
 * \brief operator - отнимает от ширины и высоты s1 ширину и высоту s2 и возвращает WSize
 * \param s1 - вычитаемый
 * \param s2 - вычитаемое
 * \return WSize
 */
inline const WSize operator-(const WSize &s1, const WSize &s2)
{
    WSize size;
    size.setWidth( s1.width() - s2.width() );
    size.setHeight( s1.height() - s2.height() );
    return size;
}

/*!
 * \brief operator + прибавляет к ширине и высоте s1 ширину и высоту s2 и возвращает WSize
 * \param s1 - слагаемый размер
 * \param s2 - слагаемый размер
 * \return WSize
 */
inline const WSize operator+(const WSize &s1, const WSize &s2)
{
    WSize size;
    size.setWidth( s1.width() + s2.width() );
    size.setHeight( s1.height() + s2.height() );
    return size;
}

/*!
 * \brief operator != оператор сравнения на неравенство,
 * возвращает True если ширина или высота обоих размеров не равная
 * \param s1 - WSize - сравниваемый размер
 * \param s2 - WSize - сравниваемый размер
 * \return bool
 */
inline bool operator!=(const WSize &s1, const WSize &s2)
{
    return ( ( s1.width() != s2.width() ) || ( s1.height() != s2.height() ) );
}

/*!
 * \brief operator == оператор сравнения равенства размеров
 * возвращщает True если и ширина и высота обоих размеров равна
 * \param s1 - сравниваемый размер
 * \param s2 - сравниваемый размер
 * \return bool
 */
inline bool operator==(const WSize &s1, const WSize &s2)
{
    return ( ( s1.width() == s2.width() ) && ( s1.height() == s2.height() ) );
}

/*!
 * \brief WSize::WSize Конструктор по умолчанию.
 * Высота и ширина будут равны нулю.
 */
WSize::WSize()
{}

/*!
 * \brief WSize::WSize конструктор с указанием ширины и высоты.
 * \param width - ширина
 * \param height - высота
 */
WSize::WSize(const int width, const int height)
{
    _width = width;
    _height = height;
}


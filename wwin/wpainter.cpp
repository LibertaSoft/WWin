#include "wpainter.h"
#include <cassert>

/*!
 * \brief WPainter::device получить контекст рисования
 * \return
 */
WPaintDevice *WPainter::device() const
{
    return _device;
}

/*!
 * \brief WPainter::setDevice установить устройство(контекст) рисования
 * \param device
 */
void WPainter::setDevice(WPaintDevice *device)
{
    _device = device;
}

/*!
 * \brief WPainter::WPainter инициализировать пустой класс WPainter
 */
WPainter::WPainter()
{}

/*!
 * \brief WPainter::WPainter инициализировать класс WPainter с устройством рисования
 * \param device
 */
WPainter::WPainter(WPaintDevice *device)
{
    _device = device;

}

/*!
 * \brief WPainter::begin начать рисование на установленном устройстве рисования
 */
void WPainter::begin()
{
    assert( this->device() != nullptr );
    _hdc = BeginPaint(this->device()->painterHWND(), &_ps);
}

/*!
 * \brief WPainter::begin начать рисовать на переданном устройстве рисования
 * \param device
 */
void WPainter::begin(WPaintDevice *device)
{
    assert( device != nullptr );
    this->setDevice(device);
    this->begin();
}

/*!
 * \brief WPainter::end закончить рисовать на установленном устройстве рисования
 */
void WPainter::end()
{
    assert( this->device() != nullptr );
    EndPaint(this->device()->painterHWND(), &_ps);
}

/*!
 * \brief WPainter::drawLine нарисовать линию на установленном устройстве рисования
 * \param beginX
 * \param beginY
 * \param endX
 * \param endY
 */
void WPainter::drawLine(int beginX, int beginY, int endX, int endY)
{
    assert( _hdc != nullptr );
    MoveToEx(_hdc, beginX, beginY, 0);
    LineTo(_hdc, endX, endY);
}

/*!
 * \brief WPainter::drawRect нарисовать прямоугольник на установленном устройстве рисования
 * \param leftX
 * \param topY
 * \param width
 * \param height
 */
void WPainter::drawRect(int leftX, int topY, int width, int height)
{
    assert( _hdc != nullptr );
    Rectangle(_hdc, leftX, topY, width+leftX, height+topY);
}

/*!
 * \brief WPainter::drawElipce нарисовать элипс на установленном устройстве рисования
 * \param leftX
 * \param topY
 * \param width
 * \param height
 */
void WPainter::drawElipce(int leftX, int topY, int width, int height)
{
    assert( _hdc != nullptr );
    Ellipse(_hdc, leftX, topY, width+leftX, height+topY);
}

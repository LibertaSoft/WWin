#include "wpaintdevice.h"

/*!
 * \brief WPaintDevice::painterHWND получить hwnd окна-контекста рисования
 * \return
 */
HWND WPaintDevice::painterHWND() const
{
    return _painterHWND;
}

/*!
 * \brief WPaintDevice::WPaintDevice инициаллизировать пустой контекст рисования
 */
WPaintDevice::WPaintDevice()
{}

/*!
 * \brief WPaintDevice::initPaintDevice инициализировать устройство рисования
 * \param hwnd
 */
void WPaintDevice::initPaintDevice(HWND hwnd)
{
    _painterHWND = hwnd;
}

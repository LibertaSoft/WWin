#ifndef WPAINTDEVICE_H
#define WPAINTDEVICE_H

#include <windows.h>

/*!
 * \brief Класс WPaintDevice описывает устройство на котором можно рисовать
 */
class WPaintDevice
{
private:
    HWND _painterHWND = nullptr;

public:
    WPaintDevice();
    void initPaintDevice(HWND hwnd);
    HWND painterHWND() const;
};

#endif // WPAINTDEVICE_H

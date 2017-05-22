#ifndef WPAINTER_H
#define WPAINTER_H

#include "wpaintdevice.h"

/*!
 * \brief Класс WPainter предназначен для рисования на любом WPaintDevice
 */
class WPainter
{
private:
    WPaintDevice* _device = nullptr;
    HDC _hdc = nullptr;
    PAINTSTRUCT _ps;

public:
    WPainter();
    WPainter(WPaintDevice *device);

    void begin();
    void begin(WPaintDevice *device);
    void end();

    void drawLine(int beginX, int beginY, int endX, int endY);
    void drawRect(int left, int top, int width, int height);
    void drawElipce(int left, int top, int width, int height);

    WPaintDevice *device() const;
    void setDevice(WPaintDevice *device);
};

#endif // WPAINTER_H

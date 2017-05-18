#include "wpainter.h"

WPaintDevice *WPainter::device() const
{
  return _device;
}

void WPainter::setDevice(WPaintDevice *device)
{
  _device = device;
}

WPainter::WPainter()
{

}

WPainter::WPainter(WPaintDevice *device)
{
  _device = device;

}

void WPainter::begin()
{
  _hdc = BeginPaint(_device->painterHWND(), &_ps);
}

void WPainter::begin(WPaintDevice *device)
{
  this->setDevice(device);
  this->begin();
}

void WPainter::end()
{
  EndPaint(_device->painterHWND(), &_ps);
}

void WPainter::drawLine(int beginX, int beginY, int endX, int endY)
{
  MoveToEx(_hdc, beginX, beginY, 0);
  LineTo(_hdc, endX, endY);
}

void WPainter::drawRect(int leftX, int topY, int width, int height)
{
  Rectangle(_hdc, leftX, topY, width+leftX, height+topY);
}

void WPainter::drawElipce(int leftX, int topY, int width, int height)
{
  Ellipse(_hdc, leftX, topY, width+leftX, height+topY);
}


/// \made Begin
/// \made End
/// drawRectegle
/// drawElips
/// drawLine
/// drawPoly


#include "wpaintdevice.h"

HWND WPaintDevice::painterHWND() const
{
  return _painterHWND;
}

WPaintDevice::WPaintDevice()
{

}

void WPaintDevice::initPaintDevice(HWND hwnd)
{
  _painterHWND = hwnd;
}

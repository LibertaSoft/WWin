#ifndef WPAINTDEVICE_H
#define WPAINTDEVICE_H

#include <windows.h>

class WPaintDevice
{
  HWND _painterHWND = nullptr;
public:
  WPaintDevice();
  void initPaintDevice(HWND hwnd);
  HWND painterHWND() const;
};

#endif // WPAINTDEVICE_H

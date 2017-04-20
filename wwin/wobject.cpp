#include "wobject.h"
#include "wwin/wapplication.h"

#include <windows.h>
#include <iostream>

WObject::WObject(WObject* parent = nullptr)
    : _parent(parent)
{

}

WObject::~WObject()
{

}

void WObject::setType(WObjectType::WObjectType type)
{
    _type = type;
}

WObjectType::WObjectType WObject::type() const
{
    return _type;
}

WObject *WObject::parent() const
{
    return _parent;
}

bool WObject::event(WEvent *e)
{
  return e->isAccepted();
}

bool WObject::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( message == WM_TIMER ){
      /// \todo process timer event
      /// return true;
  }

  return false;
}

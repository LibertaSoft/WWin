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

bool WObject::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( message == WM_TIMER ){
      /// \todo process timer event
      /// return true;
  }

  return false;
}

LPWSTR WObject::tow(const std::string &s)
{
    LPWSTR ws = new wchar_t[s.size()+1];
    copy( s.begin(), s.end(), ws );
    ws[s.size()] = 0;
    return ws;
}

std::string WObject::tos(const TCHAR *s)
{
  std::wstring arr_w( s );
  std::string arr_s( arr_w.begin(), arr_w.end() );
  return arr_s;
}

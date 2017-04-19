#include "wpushbutton.h"

#include "wwin/wmessagebox.h"
#include <iostream>

int WPushButton::style()
{
    return BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD;
}

bool WPushButton::mouseEvent(WMouseEvent *e)
{
    for(auto callback : _callbacks){
        callback(e);
    }

    e->accept();
    return e->isAccepted();
}

WPushButton::WPushButton(WWidget *parent)
    : WWidget(parent)
{
    _className = "BUTTON";
    this->init();
}
WPushButton::WPushButton(std::string title, WWidget *parent)
    : WWidget(parent)
{
    _className = "BUTTON";
    _title = title;
    this->init();
}

int WPushButton::on_click(std::function<void(WMouseEvent*)> callback)
{
    _callbacks.push_back( callback );
    return _callbacks.size();
}

bool WPushButton::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if(message != WM_COMMAND){
    return WWidget::processEvent(hWnd, message, wParam, lParam);
  }

  if( HIWORD( wParam ) == BN_CLICKED ) {
      WMouseEvent* evt = new WMouseEvent();
      POINT p;
      if( GetCursorPos(&p) ){
          evt->setCursorPos(p.x, p.y);
      }
      evt->setButton(WMouseButton::LeftButton);
      int mod = WMouseKeyModifiers::NoModifier;
      if( GetAsyncKeyState(VK_LSHIFT) < 0 || GetAsyncKeyState(VK_RSHIFT) < 0 ){
          mod |= WMouseKeyModifiers::ShiftModifier;
      }
      if( GetKeyState(VK_LCONTROL) < 0 || GetKeyState(VK_RCONTROL) < 0 ){
          mod |= WMouseKeyModifiers::ControlModifier;
      }
      if( GetAsyncKeyState(VK_LMENU) < 0 || GetAsyncKeyState(VK_RMENU) < 0 ){
          mod |= WMouseKeyModifiers::AltModifier;
      }
      if( GetAsyncKeyState(VK_LWIN) < 0 || GetAsyncKeyState(VK_RWIN) < 0 ){
          mod |= WMouseKeyModifiers::MetaModifier;
      }
      evt->setModifiers(mod);
      this->event(evt);
      return true;
  }
  return WWidget::processEvent(hWnd, message, wParam, lParam);
}

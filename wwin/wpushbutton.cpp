#include "wpushbutton.h"

#include "wwin/wmessagebox.h"
#include <iostream>

int WPushButton::style()
{
    return BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD;
}

bool WPushButton::mouseReleaseEvent(WMouseEvent *e)
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
    this->initWndClass(L"BUTTON");
}
WPushButton::WPushButton(WString title, WWidget *parent)
    : WWidget(parent)
{
    _title = title;
    this->initWndClass(L"BUTTON");
}

int WPushButton::on_click(std::function<void(WMouseEvent*)> callback)
{
    _callbacks.push_back( callback );
    return _callbacks.size();
}

bool WPushButton::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if(message != WM_COMMAND){
    return WWidget::nativeEvent(hWnd, message, wParam, lParam);
  }

  if( HIWORD( wParam ) == BN_CLICKED ) {
      return this->event(new WMouseEvent);
  }
  return WWidget::nativeEvent(hWnd, message, wParam, lParam);
}

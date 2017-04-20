#include "wlineedit.h"
#include "wwin/wmessagebox.h"
#include <tchar.h>
#include <iostream>

WString WLineEdit::value() const
{
  return _title;
}

bool WLineEdit::changeEvent(WEvent *e)
{
  wchar_t *buf = new wchar_t[_maxLength];
  GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

  _title = WString(buf);

  delete buf;

  e->accept();
  return e->isAccepted();
}

bool WLineEdit::event(WEvent *e)
{
    if( e->type() == WEvent::Type::WindowTitleChange ){
        return changeEvent(e);
    }
    return e->isAccepted();
}

bool WLineEdit::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( EN_CHANGE == HIWORD(wParam) )
  {
    return this->event( new WEvent(WEvent::Type::WindowTitleChange) );
  }
  return WWidget::nativeEvent(hWnd, message, wParam, lParam);
}

void WLineEdit::setText(const WString &value)
{
  this->setTitle(value);
}

WLineEdit::WLineEdit(WWidget *parent) : WWidget(parent)
{
  this->initWndClass(L"EDIT");
}

WLineEdit::WLineEdit(WString value, WWidget *parent) : WWidget(parent)
{
  _title = value;
  this->initWndClass(L"EDIT");
}


int WLineEdit::style()
{
    int style = WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL;

    if( _echoMode == EchoMode::Password ) {
        style |= ES_PASSWORD;
    }

    return style;
}

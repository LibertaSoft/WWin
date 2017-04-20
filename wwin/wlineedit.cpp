#include "wlineedit.h"
#include "wwin/wmessagebox.h"
#include <tchar.h>
#include <iostream>

WString WLineEdit::value() const
{
  return _title;
}

void WLineEdit::onUpateValue()
{
  wchar_t *buf = new wchar_t[_maxLength];
  GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

  _title = std::wstring(buf);
  std::wcout << _title << std::endl;
  std::wcout << buf << std::endl;

  delete buf;
}

bool WLineEdit::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( EN_CHANGE == HIWORD(wParam) )
  {
    onUpateValue();
    return true;
  }
  return WWidget::processEvent(hWnd, message, wParam, lParam);
}

void WLineEdit::setText(const WString &value)
{
  this->setTitle(value);
}

WLineEdit::WLineEdit(WWidget *parent) : WWidget(parent)
{
  _className = L"EDIT";
  this->init();
}

WLineEdit::WLineEdit(WString value, WWidget *parent) : WWidget(parent)
{
  _className = L"EDIT";
  _title = value;
  this->init();
}


int WLineEdit::style()
{
    int style = WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL;

    if( _echoMode == EchoMode::Password ) {
        style |= ES_PASSWORD;
    }

    return style;
}

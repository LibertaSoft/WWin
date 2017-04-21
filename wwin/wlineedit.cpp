#include "wlineedit.h"
#include "wwin/wmessagebox.h"
#include <tchar.h>
#include <iostream>

WString WLineEdit::value() const
{
    return _title;
}

void WLineEdit::setEchoMode(WLineEdit::EchoMode mode)
{
    _echoMode = mode;
    this->setStyle( this->style() );
}

WLineEdit::EchoMode WLineEdit::echoMode() const
{
    return _echoMode;
}

void WLineEdit::clear()
{
    _title.clear();
    SetDlgItemText( this->parentHwnd(), this->cid(), _title.c_str() );
}

int WLineEdit::on_change(std::function<void (WString)> callback)
{
    _cblChange.push_back( callback );
    return _cblChange.size();
}

bool WLineEdit::changeEvent(WEvent *e)
{
  wchar_t *buf = new wchar_t[_maxLength];
  GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

  _title = WString(buf);

  delete buf;

  for(auto callback : _cblChange){
      callback( this->title() );
  }

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


int WLineEdit::maxLength() const
{
    return _maxLength;
}

void WLineEdit::setMaxLength(int maxLength)
{
    _maxLength = maxLength;
    SendMessage(this->hwnd(), EM_LIMITTEXT, _maxLength, 0);
}

int WLineEdit::style()
{
    int style = WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL;

    if( _echoMode == WLineEdit::EchoMode::Password ) {
        style |= ES_PASSWORD;
    }

    return style;
}

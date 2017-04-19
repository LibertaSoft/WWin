#include "wlineedit.h"
#include "wwin/wmessagebox.h"
#include <tchar.h>

std::string WLineEdit::value() const
{
  return _title;
}

bool WLineEdit::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( EN_CHANGE == HIWORD(wParam) )
  {
    TCHAR *buf = new TCHAR[_maxLength];
    GetDlgItemText( hWnd, this->cid(), buf, _maxLength);

    _title = WObject::tos(buf);

    delete buf;
    return true;
  }
  return WWidget::processEvent(hWnd, message, wParam, lParam);
}

void WLineEdit::setValue(const std::string &value)
{
  this->setTitle(value);
}

WLineEdit::WLineEdit(WWidget *parent) : WWidget(parent)
{
  _className = "EDIT";
  this->init();
}

WLineEdit::WLineEdit(std::string value, WWidget *parent) : WWidget(parent)
{
  _className = "EDIT";
  _title = value;
  this->init();
}


int WLineEdit::style()
{
  return WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT;
}

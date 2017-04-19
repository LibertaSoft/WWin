#include "wlineedit.h"

std::string WLineEdit::value() const
{
  return _title;
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

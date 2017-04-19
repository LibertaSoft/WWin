#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include "wwidget.h"

class WLineEdit : public WWidget
{
private:
  int style();

public:
  WLineEdit(WWidget* parent);
  WLineEdit(std::string value, WWidget *parent);
  void setValue(const std::string &value);
  std::string value() const;
};

#endif // WLINEEDIT_H

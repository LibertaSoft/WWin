#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include "wwidget.h"

class WLineEdit : public WWidget
{
private:
  int _maxLength = 255;
private:
  int style();

public:
  WLineEdit(WWidget* parent);
  WLineEdit(std::string value, WWidget *parent);
  void setValue(const std::string &value);
  std::string value() const;

  bool processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // WLINEEDIT_H

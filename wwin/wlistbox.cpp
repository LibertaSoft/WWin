#include "wlistbox.h"
#include <iostream>

WListBox::WListBox(WWidget *parent)
    : WWidget(parent)
{
  this->initWndClass(L"LISTBOX");
}

WListBox::WListBox(ListItems itemList, WWidget *parent)
    : WWidget(parent)
{
  this->initWndClass(L"LISTBOX");
  setItemList(itemList);
}

ListItems WListBox::itemList() const
{
  return _itemList;
}

void WListBox::setItemList(const ListItems &itemList)
{
  for(auto item : itemList)
  {
    addListItem(item);
  }
}

void WListBox::addListItem(const WString &item)
{
  _itemList.push_back(item);
  SendMessage(this->hwnd(), LB_ADDSTRING, 0, (LPARAM)item.c_str());
}

bool WListBox::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( message != WM_COMMAND )
  {
    return WWidget::nativeEvent(hWnd, message, wParam, lParam);
  }

  if(HIWORD(wParam) == LBN_SELCHANGE)
  {
    return changeEvent(new WEvent);
  }
  if(HIWORD(wParam) == LBN_DBLCLK)
  {
    return mouseDoubleClickEvent(new WMouseEvent);
  }

  return WWidget::nativeEvent(hWnd, message, wParam, lParam);
}

int WListBox::on_select(std::function<void (WListBox::Item)> callback)
{
  _callbacksSelelect.push_back( callback );
  return _callbacksSelelect.size();
}

int WListBox::on_dblClick(std::function<void (WListBox::Item)> callback)
{
  _callbacksDblClick.push_back( callback );
  return _callbacksDblClick.size();
}

int WListBox::style(int prameterAnable, int parameterDisable)
{
  int parameters = WWidget::style();

  parameters |= (int)prameterAnable;
  parameters ^= (int)parameterDisable;

  return parameters;
}



bool WListBox::changeEvent(WEvent *e)
{
  _selectedIndex = SendDlgItemMessage(this->parentHwnd(), this->cid(), LB_GETCURSEL, 0, 0);
  std::cout << _selectedIndex << std::endl;
  e->accept();
  return e->isAccepted();
}

bool WListBox::mouseDoubleClickEvent(WMouseEvent *e)
{
  Item item;
  for(auto callback : _callbacksDblClick){
      callback(item);
  }
  e->accept();
  return e->isAccepted();
}

int WListBox::style()
{
  return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ WListBoxParameters::sort;
}





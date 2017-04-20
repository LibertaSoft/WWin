#include "wlistbox.h"

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
//  SendDlgItemMessage(this->hwnd(),this->cid(),LB_ADDSTRING, 0, (LPARAM)item.c_str());
    SendMessage(this->hwnd(), LB_ADDSTRING, 0, (LPARAM)item.c_str());
}

bool WListBox::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( message != WM_COMMAND )
  {
    return WWidget::processEvent(hWnd, message, wParam, lParam);
  }

  if(HIWORD(wParam) == LBN_SELCHANGE)
  {
    __onSelChange();
    return true;
  }
  if(HIWORD(wParam) == LBN_DBLCLK)
  {
    __onDblClick();
    return true;
  }

  return WWidget::processEvent(hWnd, message, wParam, lParam);
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



void WListBox::__onSelChange()
{
  _selectedIndex = SendDlgItemMessage(this->hwnd(), this->cid(), LB_GETCURSEL, 0, 0);
}

void WListBox::__onDblClick()
{
  Item item;
  for(auto callback : _callbacksDblClick){
      callback(item);
  }
}

int WListBox::style()
{
  return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ (int)WListBoxParameters::sort;
}





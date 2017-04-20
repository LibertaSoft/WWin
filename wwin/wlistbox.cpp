#include "wlistbox.h"

ListItems WListBox::itemList() const
{
  return _itemList;
}

void WListBox::setItemList(const ListItems &itemList)
{
  _itemList = itemList;
}

bool WListBox::processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

}

int WListBox::style(int listParams)
{
  return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ listParams;
}

WListBox::WListBox(WWidget *parent)
  : WWidget(parent)
{
   _className = "LISTBOX";
   this->init();
}

WListBox::WListBox(ListItems itemList, WWidget *parent)
  : WWidget(parent)
{
  _itemList = itemList;
  _className = "LISTBOX";
  this->init();
}

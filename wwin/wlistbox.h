#ifndef WLISTBOX_H
#define WLISTBOX_H

#include "wwidget.h"
#include <list>
#include <functional>
#include <vector>

typedef std::list<std::string> ListItems;

enum class WListBoxParameters{
  sort = LBS_SORT,
  notify = LBS_NOTIFY,
  noredraw = LBS_NOREDRAW,
  multiplesel = LBS_MULTIPLESEL,
  ownerdrawfixed= LBS_OWNERDRAWFIXED,
  ownerdrawvariable = LBS_OWNERDRAWVARIABLE,
  hasstrings= LBS_HASSTRINGS,
  usetabstops = LBS_USETABSTOPS,
  nointegralheight= LBS_NOINTEGRALHEIGHT,
  multicolumn = LBS_MULTICOLUMN,
  wantkeyboardinput = LBS_WANTKEYBOARDINPUT,
  extendedsel = LBS_EXTENDEDSEL,
  disablenoscroll = LBS_DISABLENOSCROLL,
  nodata= LBS_NODATA,
  nosel = LBS_NOSEL,
  combobox= LBS_COMBOBOX,
};

class WListBox : public WWidget
{
private:
  ListItems _itemList;
  std::vector< std::function<void(WMouseEvent*)> > _callbacks;
private:
  int style(int listParams = LBS_SORT);

protected:

  virtual bool mouseEvent(WMouseEvent *e);

public:
  WListBox(WWidget *parent = nullptr );
  WListBox(ListItems itemList, WWidget *parent = nullptr );

  ListItems itemList() const;
  void setItemList(const ListItems &itemList);

  virtual bool processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // WLISTBOX_H

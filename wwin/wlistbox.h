#ifndef WLISTBOX_H
#define WLISTBOX_H

#include "wwidget.h"
#include <functional>
#include <vector>

typedef std::vector<WString> ListItems;

enum WListBoxParameters {
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
public:
  struct Item {
      int id;
      WString text;
  //    std::variant UserData; to future
    };
private:
  ListItems _itemList;
  int       _selectedIndex = 0;

  std::vector< std::function<void(Item)> > _callbacksSelelect;
  std::vector< std::function<void(Item)> > _callbacksDblClick;

protected:
  int style();

  virtual void __onSelChange();
  virtual void __onDblClick();

public:

  WListBox(WWidget *parent = nullptr) : WWidget(parent)
  {
    _className = L"LISTBOX";
    this->init();
  }
  WListBox(ListItems itemList, WWidget *parent = nullptr) : WWidget(parent)
  {
    _className = L"LISTBOX";
    this->init();
    setItemList(itemList);
  }

  ListItems itemList() const;
  WString getSelectedItem() const;
  void setItemList(const ListItems &itemList);
  void addListItem(const WString &item);
  int style(int prameterAnable = WListBoxParameters::sort,
            int parameterDisable = WListBoxParameters::multiplesel);
  virtual bool processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  int on_select(std::function<void(Item )> callback );
  int on_dblClick(std::function<void(Item )> callback );

};

#endif // WLISTBOX_H

#ifndef WLISTBOX_H
#define WLISTBOX_H

#include "wwidget.h"
#include <functional>
#include <vector>

typedef std::vector<WString> ListItems; /// < Глобавльное объявление типа с весьма неоднозначным именем

/**
 * @brief WListBoxParameters Перечисление (с)Кэп
 */
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

/**
 * @brief WListBox Примитивный класс списка
 */
class WListBox : public WWidget
{
public:
    /**
   * @brief Item структура описывающая элемент списка
   */
  struct Item {
      int id;
      WString text;
      //std::variant UserData; to future
    };
private:
  ListItems _itemList; /// < Список элементов
  int       _selectedIndex = 0; /// < Индекс выделенного элемента

  std::vector< std::function<void(Item)> > _callbacksSelelect; /// Коллбэки на событие выбора
  std::vector< std::function<void(Item)> > _callbacksDblClick; /// Коллбэки на событие клика

protected:
  int style();

  virtual bool changeEvent(WEvent *event);
  virtual bool mouseDoubleClickEvent(WMouseEvent *event);
  virtual bool event(WEvent *e);

public:

  WListBox(WWidget *parent = nullptr);
  WListBox(ListItems itemList, WWidget *parent = nullptr);

  ListItems itemList() const;
  WString getSelectedItem() const;
  void setItemList(const ListItems &itemList);
  void addListItem(const WString &item);

  int style(int prameterAnable = WListBoxParameters::sort,
            int parameterDisable = WListBoxParameters::multiplesel);

  //virtual bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  int on_select(std::function<void(Item )> callback );
  int on_dblClick(std::function<void(Item )> callback );

};

#endif // WLISTBOX_H

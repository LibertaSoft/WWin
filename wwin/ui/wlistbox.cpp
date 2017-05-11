#include "wlistbox.h"
#include <iostream>

/**
 * @brief WListBox::WListBox Конструктор с инициализацией базового класса
 * @param parent
 */
WListBox::WListBox(WWidget *parent)
    : WWidget(parent)
{
  this->initWndClass(L"LISTBOX");
}

/**
 * @brief WListBox::WListBox Конструктор с инициализацией базовго класса и списка элементов
 * @param itemList
 * @param parent
 */
WListBox::WListBox(ListItems itemList, WWidget *parent)
    : WWidget(parent)
{
  this->initWndClass(L"LISTBOX");
  setItemList(itemList);
}

/**
 * @brief WListBox::itemList получить список элементов
 * @return
 */
ListItems WListBox::itemList() const
{
  return _itemList;
}

/**
 * @brief WListBox::setItemList Устаноовить список элементов
 * @param itemList
 */
void WListBox::setItemList(const ListItems &itemList)
{
  for(auto item : itemList)
  {
    addListItem(item);
  }
}

/**
 * @brief WListBox::addListItem Добавить элемент в список
 * @param item
 */
void WListBox::addListItem(const WString &item)
{
  _itemList.push_back(item);
  SendMessage(this->hwnd(), LB_ADDSTRING, 0, (LPARAM)item.c_str());
}

/**
 * @brief WListBox::nativeEvent Обработка нативных сообщений системы и их перевод в систему событий WWin
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return
 */
/*
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
//*/

/**
 * @brief WListBox::on_select Подписка на событие выбора
 * @param callback
 * @return
 */
int WListBox::on_select(std::function<void (WListBox::Item)> callback)
{
  _callbacksSelelect.push_back( callback );
  return _callbacksSelelect.size();
}

/**
 * @brief WListBox::on_dblClick Подписка на событие клика
 * @param callback
 * @return
 */
int WListBox::on_dblClick(std::function<void (WListBox::Item)> callback)
{
  _callbacksDblClick.push_back( callback );
  return _callbacksDblClick.size();
}

/**
 * @brief WListBox::style Расширенный стиль виджета
 * @param prameterAnable
 * @param parameterDisable
 * @return
 */
int WListBox::style(int prameterAnable, int parameterDisable)
{
  int parameters = WWidget::style();

  parameters |= (int)prameterAnable;
  parameters ^= (int)parameterDisable;

  return parameters;
}

/**
 * @brief WListBox::changeEvent обработка события изменения выбранного элемента
 * @param e
 * @return
 */
bool WListBox::changeEvent(WEvent *e)
{
  _selectedIndex = SendDlgItemMessage(this->parentHwnd(), this->cid(), LB_GETCURSEL, 0, 0);
  std::cout << _selectedIndex << std::endl;
  e->accept();
  return e->isAccepted();
}

/**
 * @brief WListBox::mouseDoubleClickEvent обработка события клика на элемент
 * @param e
 * @return
 */
bool WListBox::mouseDoubleClickEvent(WMouseEvent *e)
{
  Item item;
  for(auto callback : _callbacksDblClick){
      callback(item);
  }
  e->accept();
  return e->isAccepted();
}

bool WListBox::event(WEvent *e)
{
    if( e->type() == WEvent::Type::ChangeEvent ){
        return this->changeEvent(e);
    }
    return WWidget::event(e);
}

/**
 * @brief WListBox::style Стиль виджета
 * @return
 */
int WListBox::style()
{
  return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ WListBoxParameters::sort;
}





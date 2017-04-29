#include "wlistview.h"

/**
 * @brief WListView::addItem Добавление пункта в LISTBOX
 * @param item
 */
void WListView::addItem(WString item)
{
    SendMessage(this->hwnd(), LB_ADDSTRING, 0, (LPARAM)item.c_str());
}

/**
 * @brief WListView::updateItem Замена пункта в LISTBOX
 * @param index - индекс
 * @param item - элемент
 */
void WListView::updateItem(const WModelIndex index, const WString item)
{
    SendMessage(this->hwnd(), LB_DELETESTRING, (WPARAM)index.row, 0);
    SendMessage(this->hwnd(), LB_INSERTSTRING, (WPARAM)index.row, (LPARAM)item.c_str());
}

/**
 * @brief WListView::addItemList Добавить список элементов в LISTBOX
 * @param list - WStringList
 */
void WListView::addItemList(WStringList list)
{
    for(auto item : list){
        this->addItem(item);
    }
}

/**
 * @brief WListView::clear Очистить LISTBOX
 */
void WListView::clear()
{
    SendMessage(this->hwnd(), LB_RESETCONTENT, 0, 0);
}

/**
 * @brief WListView::WListView Конструктор с инициализацией базового класса
 * @param parent
 */
WListView::WListView(WWidget *parent)
    : WAbstractItemView(parent)
{
    this->initWndClass(L"LISTBOX");
    _model = new WStringListModel(parent);
}

/**
 * @brief WListView::WListView Конструктор с инициализацией базового класса и модели
 * @param stringList
 * @param parent
 */
WListView::WListView(WStringList stringList, WWidget *parent)
    : WAbstractItemView(parent)
{
    this->initWndClass(L"LISTBOX");
    _model = new WStringListModel(stringList, parent);
    this->addItemList(stringList);
}

WListView::~WListView()
{
    delete _model;
}

/**
 * @brief WListView::setModel Метод для установки модели для View
 * @param model
 */
void WListView::setModel(WStringListModel *model)
{
    WAbstractItemView::setModel(model);
    if( _model ){
        delete _model;
    }
    if( model == nullptr ) {
        model = new WStringListModel;
    }
    _model = model;
    this->clear();
    this->addItemList( model->stringList() );
}

/**
 * @brief WListView::update Метод для обновления элемента.
 * Берёт информацию по индексу из модели
 * @param index
 */
void WListView::update(const WModelIndex index)
{
    this->updateItem(index, _model->data(index));
}

/**
 * @brief WListView::on_select Метод для добавления функции обратного вызова на событие выбора элемента в списке
 * @param callback
 * @return индекс последнего элемента (или нет, пока не знаю что ему нужно возвращать)
 */
int WListView::on_select(std::function<void (WModelIndex)> callback)
{
    _cblSelectItem.push_back( callback );
    return _cblSelectItem.size();
}

/**
 * @brief WListView::on_doubleClick Метод для добавления функции обратного вызова на событие двойного клика на элементе в списке
 * @param callback
 * @return индекс последнего элемента (или нет, пока не знаю что ему нужно возвращать)
 */
int WListView::on_doubleClick(std::function<void (WModelIndex)> callback)
{
    _cblDoubleClick.push_back( callback );
    return _cblDoubleClick.size();
}

/**
 * @brief WListView::event Обработчик событий, вызывающий все другие Event'ы
 * @param e - экземпляр события
 * @return
 */
bool WListView::event(WEvent *e)
{
    return e->isAccepted();
}

/**
 * @brief WListView::nativeEvent Обработчик событий системы транслирующий нативные события в систему событий WWin
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return WEvent is accepted
 */
bool WListView::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

/**
 * @brief WListView::style Стиль виджета списка
 * @return WINAPI стиль
 */
int WListView::style()
{
    return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ LBS_SORT;
}

/**
 * @brief WListView::mouseDoubleClickEvent Событие двойного клика на элементе списка
 * @warning Почему-то, сейчас, не двойного клика
 * @param e - Экземпляр WMouseEvent
 * @return bool - WEvent::isAccepted
 */
bool WListView::mouseDoubleClickEvent(WMouseEvent *e)
{
    for(auto callback : _cblDoubleClick){
        callback(_selectedIndex);
    }
    e->accept();
    return e->isAccepted();
}

/**
 * @brief WListView::changeEvent Событие смены элемента списка
 * @param e - Экземпляр WEvent
 * @return bool - WEvent::isAccepted
 */
bool WListView::changeEvent(WEvent *e)
{
    int selectedIndex = SendDlgItemMessage(this->parentHwnd(), this->cid(), LB_GETCURSEL, 0, 0);
    _selectedIndex = {selectedIndex, 0};

    for(auto callback : _cblSelectItem){
        callback(_selectedIndex);
    }

    e->accept();
    return e->isAccepted();
}

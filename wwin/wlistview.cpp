#include "wlistview.h"
#include <iostream>


void WListView::addItem(WString item)
{
    SendMessage(this->hwnd(), LB_ADDSTRING, 0, (LPARAM)item.c_str());
}

void WListView::updateItem(const WModelIndex index, const WString item)
{
    SendMessage(this->hwnd(), LB_DELETESTRING, (WPARAM)index.row, 0);
    SendMessage(this->hwnd(), LB_INSERTSTRING, (WPARAM)index.row, (LPARAM)item.c_str());
}

void WListView::addItemList(WStringList list)
{
    for(auto item : list){
        this->addItem(item);
    }
}

void WListView::clear()
{
    SendMessage(this->hwnd(), LB_RESETCONTENT, 0, 0);
}

WListView::WListView(WWidget *parent)
    : WAbstractItemView(parent)
{
    this->initWndClass(L"LISTBOX");
    _model = new WStringListModel(parent);
}

WListView::WListView(WStringList stringList, WWidget *parent)
    : WAbstractItemView(parent)
{
    this->initWndClass(L"LISTBOX");
    _model = new WStringListModel(stringList, parent);
    this->addItemList(stringList);
}

void WListView::setModel(WStringListModel *model)
{
    WAbstractItemView::setModel(model);
    if( _model ){
        delete _model;
    }
    _model = model;
    this->clear();
    this->addItemList( model->stringList() );
}

void WListView::update(const WModelIndex index)
{
    this->updateItem(index, _model->data(index));
}

void WListView::dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight, const std::vector<int> roles)
{
//    this->clear();
    WAbstractItemView::dataChanhed(topLeft,bottomRight, roles);
}

int WListView::on_select(std::function<void (WModelIndex)> callback)
{
    _cblSelectItem.push_back( callback );
    return _cblSelectItem.size();
}

int WListView::on_doubleClick(std::function<void (WModelIndex)> callback)
{
    _cblDoubleClick.push_back( callback );
    return _cblDoubleClick.size();
}

bool WListView::event(WEvent *e)
{
    return e->isAccepted();
}

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

int WListView::style()
{
    return (WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ LBS_SORT;
}

bool WListView::mouseDoubleClickEvent(WMouseEvent *e)
{
    for(auto callback : _cblDoubleClick){
        callback(_selectedIndex);
    }
    e->accept();
    return e->isAccepted();
}

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

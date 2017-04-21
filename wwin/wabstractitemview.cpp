#include "wabstractitemview.h"

WModelIndex WAbstractItemView::currentIndex() const
{
    return _selectedIndex;
}

WAbstractItemView::WAbstractItemView(WWidget *parent)
    : WWidget(parent)
{

}

void WAbstractItemView::setModel(WAbstractItemModel *model)
{
    _abstractModel = model;
    model->__addUpdateListener( this );
}

void WAbstractItemView::dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight, const std::vector<int> roles)
{
    for (int row = topLeft.first; row < bottomRight.first; ++row) {
        for (int col = topLeft.second; col < bottomRight.second; ++col) {
            WModelIndex index = {row, col};
            this->update(index);
        }
    }
}


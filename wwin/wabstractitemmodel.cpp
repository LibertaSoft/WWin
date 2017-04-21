#include "wabstractitemmodel.h"
#include "wabstractitemview.h"

WAbstractItemModel::WAbstractItemModel(WObject *parent)
    : WObject(parent)
{

}

void WAbstractItemModel::dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight, const std::vector<int> roles)
{
    for(WAbstractItemView* listener : _updateListeners){
        listener->dataChanhed(topLeft, bottomRight, roles);
    }
}

void WAbstractItemModel::__addUpdateListener(WAbstractItemView *view)
{
    _updateListeners.push_back( view );
}


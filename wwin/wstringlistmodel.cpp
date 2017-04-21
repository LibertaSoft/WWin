#include "wstringlistmodel.h"

WStringListModel::WStringListModel(WObject *parent)
    : WAbstractItemModel(parent)
{

}

WStringListModel::WStringListModel(const WStringList &strings, WObject *parent)
    : WAbstractItemModel(parent)
{
    this->setStringList(strings);
}

void WStringListModel::setStringList(const WStringList &strings)
{
    _stringList = strings;
    this->dataChanhed({0,0}, {strings.size(),1});
}

WStringList WStringListModel::stringList() const
{
    return _stringList;
}

WVariant WStringListModel::data(WModelIndex index)
{
    return _stringList[index.first];
}

bool WStringListModel::setData(WModelIndex index, WVariant data)
{
    if( index.first < 0 || index.first > this->rowCount() ){
        _stringList.push_back(data);
        this->dataChanhed({_stringList.size()-1,0}, {_stringList.size(),1});
    } else {
        _stringList[index.first] = data;
        this->dataChanhed({index.first,0}, {index.first+1,1});
    }
    return true;
}

bool WStringListModel::removeRow(WModelIndex index)
{
    _stringList.erase(_stringList.begin() + index.first, _stringList.begin() + index.first + 1);
    return true;
}

int WStringListModel::rowCount(WModelIndex) const
{
    return _stringList.size();
}

int WStringListModel::columnCount(WModelIndex) const
{
    return 0;
}


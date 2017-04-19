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
}

WStringList WStringListModel::stringList() const
{
    return _stringList;
}

WVariant WStringListModel::data(WModelIndex &index)
{
    return _stringList[index.first];
}

bool WStringListModel::setData(WModelIndex &index, WVariant data)
{
    _stringList[index.first] = data;
    return true;
}

bool WStringListModel::removeRow(WModelIndex &index)
{
    _stringList.erase(_stringList.begin() + index.first, _stringList.begin() + index.first + 1);
    return true;
}


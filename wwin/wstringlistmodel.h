#ifndef WSTRINGLISTMODEL_H
#define WSTRINGLISTMODEL_H

#include <vector>

#include "wwin/wstring.h"
#include "wwin/wobject.h"
#include "wwin/wabstractitemmodel.h"

typedef std::vector<WString> WStringList;

class WStringListModel : public WAbstractItemModel
{
private:
    WStringList _stringList;

public:
    WStringListModel(WObject *parent = nullptr);
    WStringListModel(const WStringList &strings, WObject *parent = nullptr);

    void setStringList(const WStringList& strings);
    WStringList stringList() const;

    virtual WVariant data(WModelIndex& index);
    virtual bool setData(WModelIndex& index, WVariant data);
    virtual bool removeRow(WModelIndex& index);
};

#endif // WSTRINGLISTMODEL_H

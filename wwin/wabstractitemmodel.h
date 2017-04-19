#ifndef WABSTRACTITEMMODEL_H
#define WABSTRACTITEMMODEL_H

#include <string>
#include <utility>

#include "wwin/wobject.h"

typedef std::string WVariant;
typedef std::pair<int,int> WModelIndex;

class WAbstractItemModel : public WObject
{
public:
    WAbstractItemModel(WObject* parent);

    virtual bool setData(WModelIndex& index, WVariant data) = 0;
    virtual WVariant data(WModelIndex& index) = 0;
    virtual bool removeRow(WModelIndex& index) = 0;
};

#endif // WABSTRACTITEMMODEL_H

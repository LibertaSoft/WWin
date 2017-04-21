#ifndef WABSTRACTITEMMODEL_H
#define WABSTRACTITEMMODEL_H

#include <utility>
#include <vector>

#include "wwin/wobject.h"
#include "wwin/wstring.h"

class WAbstractItemView;
//#include "wwin/wabstractitemview.h"

typedef WString WVariant;
typedef std::pair<int,int> WModelIndex;

class WAbstractItemModel : public WObject
{
private:
    std::vector<WAbstractItemView*> _updateListeners;

public:
    WAbstractItemModel(WObject* parent);

    virtual void dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight,
                             const std::vector<int> roles = std::vector<int>());

    virtual bool setData(WModelIndex index, WVariant data) = 0;
    virtual WVariant data(WModelIndex index) = 0;
    virtual bool removeRow(WModelIndex index) = 0;

    virtual int rowCount(WModelIndex parent = {0,0}) const = 0;
    virtual int columnCount(WModelIndex parent = {0,0}) const = 0;

    void __addUpdateListener(WAbstractItemView *view);
};

#endif // WABSTRACTITEMMODEL_H

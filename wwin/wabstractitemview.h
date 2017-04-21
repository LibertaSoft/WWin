#ifndef WABSTRACTITEMVIEW_H
#define WABSTRACTITEMVIEW_H

#include "wwin/wwidget.h"
#include "wwin/wabstractitemmodel.h"

class WAbstractItemView : public WWidget
{
private:
    WAbstractItemModel *_abstractModel;
protected:
    WModelIndex _selectedIndex = {0,0};

private:
    WModelIndex currentIndex() const;
public:
    WAbstractItemView(WWidget *parent);

    virtual void setModel(WAbstractItemModel *model);

    virtual void dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight,
                             const std::vector<int> roles = std::vector<int>());

    virtual void update(const WModelIndex index) = 0;
};

#endif // WABSTRACTITEMVIEW_H

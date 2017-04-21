#ifndef WLISTVIEW_H
#define WLISTVIEW_H

#include <functional>

#include "wwin/wwidget.h"
#include "wwin/wstringlistmodel.h"
#include "wwin/wabstractitemview.h"

class WListView : public WAbstractItemView
{
private:
    WStringListModel *_model = nullptr;

    std::vector< std::function<void(WModelIndex)> > _cblSelectItem;
    std::vector< std::function<void(WModelIndex)> > _cblDoubleClick;

    void addItem(WString item);
    void updateItem(const WModelIndex index, const WString item);
    void addItemList(WStringList list);
    void clear();
public:
    WListView(WWidget *parent = nullptr);
    WListView(WStringList stringList, WWidget *parent = nullptr);

    void setModel(WStringListModel *model);

    virtual void update(const WModelIndex index) override;

    virtual void dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight,
                             const std::vector<int> roles = std::vector<int>()) override;

    // Subscribes
public:
    int on_select(std::function<void(WModelIndex)> callback );
    int on_doubleClick(std::function<void(WModelIndex)> callback );

    // WObject interface
public:
    virtual bool event(WEvent *e) override;
    virtual bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

    // WWidget interface
protected:
    virtual int style() override;
    virtual bool mouseDoubleClickEvent(WMouseEvent *e) override;
    virtual bool changeEvent(WEvent *e) override;
};

#endif // WLISTVIEW_H

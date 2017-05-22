#ifndef WLISTVIEW_H
#define WLISTVIEW_H

#include <functional>

#include "wwin/ui/wwidget.h"
#include "wwin/wstringlistmodel.h"
#include "wwin/ui/wabstractitemview.h"

/**
 * @brief WListView Виджет для отображения модели списка.
 * Работает на основе системы Model-View реализованной в WWin.
 */
class WListView : public WAbstractItemView
{
private:
    WStringListModel *_model = nullptr; /// < Модель строк для списка \todo Добавить иконки, как-то
    bool _mineModel = false;

    /// Список функций обратного вызова для события выбора элемента
    std::vector< std::function<void(WModelIndex)> > _cblSelectItem;
    /// Список функций обратного вызова для события двойного клика на элемента \todo работает только обычный клик, странно
    std::vector< std::function<void(WModelIndex)> > _cblDoubleClick;

    void addItem(WString item);
    void updateItem(const WModelIndex index, const WString item);
    void addItemList(WStringList list);
    void clear();

public:
    WListView(WWidget *parent = nullptr);
    WListView(WStringList stringList, WWidget *parent = nullptr);
    ~WListView();

    void setModel(WStringListModel *model);

    virtual void update(const WModelIndex index) override;

    WStringListModel* model() const;

    // Subscribes
    int on_select(std::function<void(WModelIndex)> callback );
    int on_doubleClick(std::function<void(WModelIndex)> callback );

    // WWidget interface
protected:
    virtual int style() override;
    virtual bool mouseDoubleClickEvent(WMouseEvent *e) override;
    virtual bool changeEvent(WEvent *e) override;
    virtual bool event(WEvent *e) override;
};

#endif // WLISTVIEW_H

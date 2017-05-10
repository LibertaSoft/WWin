#ifndef WABSTRACTITEMVIEW_H
#define WABSTRACTITEMVIEW_H

#include "wwin/ui/wwidget.h"
#include "wwin/ui/wabstractitemmodel.h"

/**
 * @brief WAbstractItemView Базовый класс для всех View
 *
 * Является частью системы Model-View реализованной в WWin.
 *
 * Для реализации своего View необходимо унаследовать этот класс и реализовать недостающие методы.
 * При реализации метода setModel у вашего класса, необходимо обязательно вызвать метод базового
 * класса: `WAbstractItemView::setModel(model);` В нём реализуется важная часть системы Model-View.
 */
class WAbstractItemView : public WWidget
{
private:
    WAbstractItemModel *_abstractModel = nullptr; /// < Указатель на модель
protected:
    WModelIndex _selectedIndex = {0,0}; /// < Индекс выделенного элемента \todo сделать группу выделения

public:
    WAbstractItemView(WWidget *parent);
    WModelIndex currentIndex() const;

    virtual void setModel(WAbstractItemModel *model);

    virtual void dataChanged(const WModelIndex topLeft, const WModelIndex bottomRight);

    virtual void update(const WModelIndex index) = 0;
};

#endif // WABSTRACTITEMVIEW_H

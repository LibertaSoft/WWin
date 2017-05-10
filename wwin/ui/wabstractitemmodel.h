#ifndef WABSTRACTITEMMODEL_H
#define WABSTRACTITEMMODEL_H

#include <utility>
#include <vector>
#include <list>
#include <functional>

#include "wwin/wobject.h"
#include "wwin/wstring.h"

class WAbstractItemView; /// < Для избежания циклической заивисимости
typedef WString WVariant; /// < \todo заменить на нормальный класс, реализующий Variant

/**
 * @brief WModelIndex структура описывающая позицию в модели
 */
typedef struct WModelIndex {
    int row = 0;
    int col = 0;
    WModelIndex(int _row = 0, int _col = 0): row(_row), col(_col){}
} WModelIndex;

/**
 * @brief WAbstractItemModel Базовый класс для всех моделей описывающий основные методы
 * работы с моделью и являющийся частью механизма Model-View реализованного в WWin
 *
 * Для реализации собственной модели, Вам необходимо унаследовать этот класс
 * и реализовать абстрактные методы.
 * Реализуя методы в унаследованном классе не забывайте вызывать метод dataChanhed
 * с указанием диапозона изменившихся значений.
 *
 * Класс реализует систему связывания View и Model.
 * Для этого при регистрации модели во View, View вызывает метод модели __addUpdateListened
 * и подписывается на прослушивание сообщений об обновлении модели.
 * Данная система позволяет уведомлять все View к которым подключена одна модель о изменении данных.
 */
class WAbstractItemModel : public WObject
{
private:
    std::list< WAbstractItemView* > _updateListeners; /// < список View слушающийх сообщения об обновлении модели

public:
    WAbstractItemModel(WObject* parent);

    void dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight);

    virtual bool setData(WModelIndex index, WVariant data) = 0;
    virtual WVariant data(WModelIndex index) = 0;
    virtual bool removeRow(WModelIndex index) = 0;

    virtual int rowCount(WModelIndex parent = {0,0}) const = 0;
    virtual int columnCount(WModelIndex parent = {0,0}) const = 0;

    void __addUpdateListener(WAbstractItemView* view);
    void __removeUpdateListener(WAbstractItemView* view);
};

#endif // WABSTRACTITEMMODEL_H

#include "wabstractitemmodel.h"
#include "wabstractitemview.h"

/**
 * @brief WAbstractItemModel::WAbstractItemModel Конструктор класса
 * @param parent
 */
WAbstractItemModel::WAbstractItemModel(WObject *parent)
    : WObject(parent)
{}

/**
 * @brief WAbstractItemModel::dataChanhed событие изменения данных
 * @param topLeft - начало диапозона данных
 * @param bottomRight - конец диапозона данных
 * @param roles - [Не используется] роли данных
 */
void WAbstractItemModel::dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight, const std::vector<int> roles)
{
    for(WAbstractItemView* listener : _updateListeners){
        listener->dataChanhed(topLeft, bottomRight, roles);
    }
}

/**
 * @brief WAbstractItemModel::__addUpdateListener Метод для подписки View
 * на события модели об обновлении данных
 * @param view
 */
void WAbstractItemModel::__addUpdateListener(WAbstractItemView *view)
{
    _updateListeners.push_back( view );
}


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
void WAbstractItemModel::dataChanhed(const WModelIndex topLeft, const WModelIndex bottomRight)
{
    for(auto listener : _updateListeners){
        if( listener != nullptr ) {
            listener->dataChanged(topLeft, bottomRight);
        }
    }
}

/**
 * @brief WAbstractItemModel::__addUpdateListener Метод для подписки View
 * на события модели об обновлении данных
 * @param view
 */
void WAbstractItemModel::__addUpdateListener(WAbstractItemView *view)
{
    if( view != nullptr ){
        _updateListeners.push_back( view );
    }
}

void WAbstractItemModel::__removeUpdateListener(WAbstractItemView *view)
{
    _updateListeners.remove(view);
}


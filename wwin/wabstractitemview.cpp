#include "wabstractitemview.h"
#include <functional>

/**
 * @brief WAbstractItemView::currentIndex получить индекс текущего элемента
 * @return
 */
WModelIndex WAbstractItemView::currentIndex() const
{
    return _selectedIndex;
}

/**
 * @brief WAbstractItemView::WAbstractItemView Конструктор с инициализацией базового класса
 * @param parent
 */
WAbstractItemView::WAbstractItemView(WWidget *parent)
    : WWidget(parent)
{}

/**
 * @brief WAbstractItemView::setModel Метод для утановки модели.
 * @warning Обязательно должен быть вызван при переопределении.
 * @warning Никогда не передавайте сюда nullptr !!!
 * @param model
 */
void WAbstractItemView::setModel(WAbstractItemModel *model)
{
    if( model != nullptr ) {
        _abstractModel = model;
        model->__addUpdateListener( this );
    }
}

/**
 * @brief WAbstractItemView::dataChanhed Метод получающий информацию о изменениях в модели
 * и инициализирующий обновление данных во View
 * @param topLeft - Индекс начала изменившегося фрагмента
 * @param bottomRight - Индекс конца изменившегося фрагмента
 * @param roles - [Не используется] роли
 */
void WAbstractItemView::dataChanged(const WModelIndex topLeft, const WModelIndex bottomRight)
{
    for (int row = topLeft.row; row < bottomRight.row; ++row) {
        for (int col = topLeft.col; col < bottomRight.col; ++col) {
            WModelIndex index = {row, col};
            this->update(index);
        }
    }
}


#ifndef WPROGRESSBAR_H
#define WPROGRESSBAR_H

#include "wwin/ui/wwidget.h"
#include <list>
#include <functional>

/*!
 * \brief WProgressBar класс виджета прогресс-бара.
 * Предназначен для отображения прогресса какой-либо длительной операции.
 */
class WProgressBar : public WWidget
{
private:
    int _value = 0; /// < Текущее значение

    std::list< std::function<void(int)> > _cblChange; /// < Функции обратного вызова на событие изменение значения

public:
    WProgressBar(WWidget *parent);

    int value() const;
    void setValue(int value);

    void on_changed(std::function<void(int)> callback);

    // WWidget interface
protected:
    virtual int style() override;
};

#endif // WPROGRESSBAR_H

#ifndef WSPINBOX_H
#define WSPINBOX_H

#include "wwin/ui/wwidget.h"
#include <vector>
#include <functional>

/*!
 * \brief WSpinBox Класс реализует виджет поля для ввода с кнопками управления +/-
 * позволяет вводить только цифры в диапозоне signed int(от -32767 до +32767)
 * но можно задать свои ограничения, не больше диапозона integer
 */
class WSpinBox : public WWidget
{
private:
    HWND _spinHwnd = 0;
    int  _spinCid = 0;

    int _maxLength = 5;

    int _minimum = 0;
    int _maximum = 32767;
    int _value = 0;

    std::vector< std::function<void(int)> > _cblChange; /// < Список функций обратного вызова на событие изменения данных

public:
    WSpinBox(WWidget *parent);

    void show();

    int minimum() const;
    void setMinimum(int value);

    int maximum() const;
    void setMaximum(int value);

    int value() const;
    void setValue(int value);

    void on_changed(std::function<void(int)> callback);

    // WWidget interface
protected:
    virtual int style() override;

    bool changeEvent(WEvent *event);
    bool event(WEvent *event);
};

#endif // WSPINBOX_H

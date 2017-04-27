#include "wprogressbar.h"
#include <commctrl.h>

/*!
 * \brief WProgressBar::value Получить текущее значение прогресса
 * \return
 */
int WProgressBar::value() const
{
    return _value;
}

/*!
 * \brief WProgressBar::setValue установить новое значение пргресса
 * \param value
 */
void WProgressBar::setValue(int value)
{
    if( (value <= 100) && (value >= 0) ) {
        _value = value;
        SendMessage(this->hwnd(), PBM_SETPOS, _value, 0);

        for(auto callback : _cblChange){
            callback( _value );
        }
    }
}

/*!
 * \brief WProgressBar::on_changed Зарегистрировать функцию обратного вызова
 * на событие изменения значения.
 * \param callback
 */
void WProgressBar::on_changed(std::function<void (int)> callback)
{
    _cblChange.push_back( callback );
}

/*!
 * \brief WProgressBar::WProgressBar Конструктор с инициализацией
 * \param parent
 */
WProgressBar::WProgressBar(WWidget *parent)
    : WWidget(parent)
{
    this->initWndClass(PROGRESS_CLASS);
}

/*!
 * \brief WProgressBar::style Стили для окна прогресса
 * \return
 */
int WProgressBar::style()
{
    return WS_CHILD | WS_VISIBLE;
}


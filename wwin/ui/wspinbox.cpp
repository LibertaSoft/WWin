#include "wspinbox.h"
#include "../wapplication.h"

#include <commctrl.h>

/*!
 * \brief WSpinBox::minimum получить минимальное допустимое значение
 * \return
 */
int WSpinBox::minimum() const
{
    return _minimum;
}

/*!
 * \brief WSpinBox::setMinimum установить минимальное допустимое для ввода значение
 * \param value
 */
void WSpinBox::setMinimum(int value)
{
    _minimum = value;
}

/*!
 * \brief WSpinBox::maximum получить максимальное допустимое значение
 * \return
 */
int WSpinBox::maximum() const
{
    return _maximum;
}

/*!
 * \brief WSpinBox::setMaximum установить максимальное допустимое значение
 * \param value
 */
void WSpinBox::setMaximum(int value)
{
    _maximum = value;
}

/*!
 * \brief WSpinBox::value получть текущее значение
 * \return
 */
int WSpinBox::value() const
{
    return _value;
}

/*!
 * \brief WSpinBox::setValue установить текущее значение
 * \param value
 */
void WSpinBox::setValue(int value)
{
    _value = value;
    this->setTitle( std::to_wstring(_value) );
}

/*!
 * \brief WSpinBox::on_changed добавить функцию обратного вызова на событие изменения значения
 * \param callback
 */
void WSpinBox::on_changed(std::function<void(int)> callback)
{
    _cblChange.push_back( callback );
}

/*!
 * \brief WSpinBox::WSpinBox конструктор с инициализацией
 * \param parent
 */
WSpinBox::WSpinBox(WWidget *parent = nullptr)
    : WWidget(parent)
{
    this->initWndClass(L"EDIT");
}

/*!
 * \brief WSpinBox::show показать виджет
 */
void WSpinBox::show()
{
    WWidget::show();

    if( ! _spinHwnd ){
        _spinCid  = WWidget::nextCid();
        _spinHwnd = CreateUpDownControl( /// Using Windows Common Controls
              WS_CHILD
            | WS_VISIBLE
            | WS_BORDER
            | UDS_ALIGNRIGHT
            | UDS_ARROWKEYS
            | UDS_SETBUDDYINT
            | UDS_WRAP
            ,0,0,0,0, // Размеры окна не нужны, т.к. виджет используется вместе с EDIT
            this->parentHwnd(), // hwnd окна
            _spinCid,
            wApp->getHinstance(),
            this->hwnd(), // hwnd EDIT'а
            this->maximum(),
            this->minimum(),
            this->value()
        );
    }
}

/*!
 * \brief WSpinBox::style переопределение стиля для виджета
 * \return
 */
int WSpinBox::style()
{
    return WS_BORDER | WS_VISIBLE | WS_CHILD | ES_NUMBER;
}


/**
 * @brief WSpinBox::changeEvent Обработка события изменения содержимого в поле ввода
 * @param e - WEvent событие
 * @return WEvent::isAccepted
 */
bool WSpinBox::changeEvent(WEvent *event)
{
  wchar_t *buf = new wchar_t[_maxLength];
  GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

  _title = WString(buf);
  _value = std::stoi(_title);

  delete buf;

  for(auto callback : _cblChange){
      callback( this->value() );
  }

  event->accept();
  return event->isAccepted();
}

/**
 * @brief WSpinBox::event Обработка событий
 * @param e - экземпляр WEvent
 * @return WEvent::isAccepted
 */
bool WSpinBox::event(WEvent *e)
{
    if( e->type() == WEvent::Type::WindowTitleChange ){
        return changeEvent(e);
    }
    return WWidget::event(e);
}

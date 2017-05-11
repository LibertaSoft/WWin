#include "wlineedit.h"
#include "wwin/ui/wmessagebox.h"
#include <tchar.h>
#include <iostream>

/**
 * @brief WLineEdit::value получить значение из поля ввода
 * @return
 */
WString WLineEdit::value() const
{
    return _title;
}

/**
 * @brief WLineEdit::setEchoMode установить режим вывода
 * @param mode
 */
void WLineEdit::setEchoMode(WLineEdit::EchoMode mode)
{
    _echoMode = mode;
    this->setStyle( this->style() );
}

/**
 * @brief WLineEdit::echoMode получить метод ввода
 * @return
 */
WLineEdit::EchoMode WLineEdit::echoMode() const
{
    return _echoMode;
}

/**
 * @brief WLineEdit::clear очистить текст в поле ввода
 */
void WLineEdit::clear()
{
    _title.clear();
    SetDlgItemText( this->parentHwnd(), this->cid(), _title.c_str() );
}

/**
 * @brief WLineEdit::on_change подписатсья на событие изменения данных
 * @param callback - функция обратного вызова, с параметром WString
 * @return временно размер массива функций обратного вызова
 */
int WLineEdit::on_change(std::function<void (WString)> callback)
{
    _cblChange.push_back( callback );
    return _cblChange.size();
}

/**
 * @brief WLineEdit::changeEvent Обработка события изменения содержимого в поле ввода
 * @param e - WEvent событие
 * @return WEvent::isAccepted
 */
bool WLineEdit::changeEvent(WEvent *e)
{
  wchar_t *buf = new wchar_t[_maxLength];
  GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

  _title = WString(buf);

  delete buf;

  for(auto callback : _cblChange){
      callback( this->title() );
  }

  e->accept();
  return e->isAccepted();
}

/**
 * @brief WLineEdit::event Обработка событий
 * @param e - экземпляр WEvent
 * @return WEvent::isAccepted
 */
bool WLineEdit::event(WEvent *e)
{
    if( e->type() == WEvent::Type::WindowTitleChange ){
        return changeEvent(e);
    }
    return WWidget::event(e);
}

/**
 * @brief WLineEdit::setText установить текст в поле ввода
 * @param value
 */
void WLineEdit::setText(const WString &value)
{
  this->setTitle(value);
}

/**
 * @brief WLineEdit::WLineEdit Конструктор с инициализацией базового класса
 * @param parent
 */
WLineEdit::WLineEdit(WWidget *parent) : WWidget(parent)
{
  this->initWndClass(L"EDIT");
}

/**
 * @brief WLineEdit::WLineEdit Конструктор с инициализацией базового класса и текста в поле ввода
 * @param value
 * @param parent
 */
WLineEdit::WLineEdit(WString value, WWidget *parent) : WWidget(parent)
{
  _title = value;
  this->initWndClass(L"EDIT");
}

/**
 * @brief WLineEdit::maxLength Получить максимальную длину строки в поле ввода
 * @return
 */
int WLineEdit::maxLength() const
{
    return _maxLength;
}

/**
 * @brief WLineEdit::setMaxLength Установить максимальную длину строки в поле ввода
 * @param maxLength
 */
void WLineEdit::setMaxLength(int maxLength)
{
    _maxLength = maxLength;
    SendMessage(this->hwnd(), EM_LIMITTEXT, _maxLength, 0);
}

/**
 * @brief WLineEdit::style получить стиль окна
 * @return
 */
int WLineEdit::style()
{
    int style = WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL;

    if( _echoMode == WLineEdit::EchoMode::Password ) {
        style = style | ES_PASSWORD;
    }

    return style;
}

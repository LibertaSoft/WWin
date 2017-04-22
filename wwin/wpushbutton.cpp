#include "wpushbutton.h"

#include "wwin/wmessagebox.h"
#include <iostream>

/**
 * @brief WPushButton::style стиль кнопки
 * @return
 */
int WPushButton::style()
{
    return BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD;
}

/**
 * @brief WPushButton::mouseReleaseEvent событие отпускания кнопки
 * @param e - экземпляр WMouseEvent
 * @return
 */
bool WPushButton::mouseReleaseEvent(WMouseEvent *e)
{
    for(auto callback : _callbacks){
        callback(e);
    }

    e->accept();
    return e->isAccepted();
}

/**
 * @brief WPushButton::WPushButton Коснтруктор с инициализацией базового класса и окна кнопки
 * @param parent - родитель
 */
WPushButton::WPushButton(WWidget *parent)
    : WWidget(parent)
{
    this->initWndClass(L"BUTTON");
}

/**
 * @brief WPushButton::WPushButton Конструктор с инициализацией базового класса и окна кнопки,
 * плюс установкой надписи на кнопке
 * @param title - надпись на кнопке
 * @param parent - родитель
 */
WPushButton::WPushButton(WString title, WWidget *parent)
    : WWidget(parent)
{
    _title = title;
    this->initWndClass(L"BUTTON");
}

/**
 * @brief WPushButton::on_click Подписка на событие клика
 * @param callback - функция обратного вызова
 * @return индекс последнего элемента
 */
int WPushButton::on_click(std::function<void(WMouseEvent*)> callback)
{
    _callbacks.push_back( callback );
    return _callbacks.size();
}

/**
 * @brief WPushButton::nativeEvent Обработка нативных системных событий и их преобразование в
 * систему событий WWin
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return обработано ли событие
 */
bool WPushButton::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if(message != WM_COMMAND){
    return WWidget::nativeEvent(hWnd, message, wParam, lParam);
  }

  if( HIWORD( wParam ) == BN_CLICKED ) {
      return this->event(new WMouseEvent);
  }
  return WWidget::nativeEvent(hWnd, message, wParam, lParam);
}

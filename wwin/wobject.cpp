#include "wobject.h"
#include "wwin/wapplication.h"

#include <windows.h>

/**
 * @brief WObject::WObject Конструктор объекта
 * @param parent - родитель объекта
 */
WObject::WObject(WObject* parent = nullptr)
    : _parent(parent)
{}

/**
 * @brief WObject::~WObject Виртуальный дестркуктор
 */
WObject::~WObject(){}

/**
 * @brief WObject::setType Устанавливает тип объекта.
 * Используется при приведении типов, в одном месте, может стоит отказаться от него
 * @param type - тип копонента
 */
void WObject::setType(WObjectType::WObjectType type)
{
    _type = type;
}

/**
 * @brief WObject::type позволяет получить тип компонента из перечисления WObjectType
 * @return WOBjectType - тип компонента
 */
WObjectType::WObjectType WObject::type() const
{
    return _type;
}

/**
 * @brief WObject::parent Позволяет получить указатель на родителя компонента
 * @return WObject* - указатель на родителя компонента
 */
WObject *WObject::parent() const
{
    return _parent;
}

/**
 * @brief WObject::event базовыый обработчик событий, должен вызывать все остальные события
 * @param e - экземпляр объъекта WEvent с описанием и информацией события
 * @return `bool` - true если событие было обработано и `false` в противном случае
 */
bool WObject::event(WEvent *e)
{
    return e->isAccepted();
}

/**
 * @brief WObject::nativeEvent Метод для обработки событий от системы
 * Задача - преобразование системного события в собственную систему событий.
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return `bool` - true если событие было обработано и `false` в противном случае
 */
bool WObject::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if( message == WM_TIMER ){
      /// \todo process timer event
      /// return true;
  }

  return false;
}

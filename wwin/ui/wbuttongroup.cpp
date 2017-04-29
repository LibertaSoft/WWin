#include "wbuttongroup.h"
#include <iostream>

/*!
 * \brief WButtonGroup::WButtonGroup конструктор с  инициализацией
 * \param parent
 */
WButtonGroup::WButtonGroup(WObject parent = nullptr)
    : WObject(parent)
{

}

/*!
 * \brief WButtonGroup::~WButtonGroup Виртуальный деструктор с отвязкой кнопок от группы
 */
WButtonGroup::~WButtonGroup()
{
    for(WAbstractButton* btn : _buttons){
        btn->setButtonGroup(nullptr);
    }
}

/*!
 * \brief WButtonGroup::addButton Добавить кнопку в группу
 * \param button - указатель на добавляемую кнопку
 * \param id - [Не используется] какой-то id
 */
void WButtonGroup::addButton(WAbstractButton *button, int id)
{
    _buttons.push_back( button );
    _mapping[id] = button;

    // При переключении состояния, нужно обновить состояния всех остальных кнопок
    button->on_toggleed([=](WMouseEvent*,bool checked){
        if( checked == false ){
            button->setChecked(true);
        }
        if( this->exclusive() ){
            for(auto btn : this->buttons()){
                if( button != btn ){
                    btn->setChecked(false);
                }
            }
        }
    });
}

/*!
 * \brief WButtonGroup::button Получить кнопку по её id
 * \param id - id кнопки
 * \return WAbstractButton* - Указатель на кнопку
 */
WAbstractButton *WButtonGroup::button(int id)
{
    return _mapping[id];
}

/*!
 * \brief WButtonGroup::buttons получить список кнопок
 * \return
 */
std::list<WAbstractButton *> WButtonGroup::buttons() const
{
    return _buttons;
}

/*!
 * \brief WButtonGroup::checkedButton получить указатель на выделенную кнопку
 * \return
 */
WAbstractButton *WButtonGroup::checkedButton() const
{
    return _checkedButton;
}

/*!
 * \brief WButtonGroup::checkedId получить id выделенной кнопки
 * \return
 */
int WButtonGroup::checkedId() const
{
    return _checkedId;
}

/*!
 * \brief WButtonGroup::exclusive Включен ли режим для активации лишь одной кнопки из набора
 * \return
 */
bool WButtonGroup::exclusive() const
{
    return _exclusive;
}

/*!
 * \brief WButtonGroup::setExclusive Установить режим для активации лишь одной кнопки из набора
 * \param exclusive
 */
void WButtonGroup::setExclusive(bool exclusive)
{
    _exclusive = exclusive;
}

/*!
 * \brief WButtonGroup::id получить id кнопки по указателю на неё
 * \param button
 * \return
 */
int WButtonGroup::id(WAbstractButton *button) const
{
    for(auto btn : _mapping){
        if( btn.second == button ) {
            return btn.first;
        }
    }
    return -1;
}

/*!
 * \brief WButtonGroup::removeButton Удалить кнопку из группы
 * \param button
 */
void WButtonGroup::removeButton(WAbstractButton *button)
{
    // Защита от дурака
    if( button == nullptr ){
        return;
    }
    // Если удаляемая кнопка является чекнутой
    if( _checkedButton && (button == _checkedButton) ){
        _checkedButton = nullptr;
    }
    // Какое-то костыльное удаление
    for(auto btn : _mapping){
        if( btn.second == button ) {
            if( _checkedId == btn.first ){
                _checkedId = -1;
            }
            _mapping.erase(btn.first);
        }
    }
    for(auto btn = _buttons.begin(); btn != _buttons.end(); ++btn){
        if( *btn == button ) {
            _buttons.erase(btn);
        }
    }
    // Удалим у кнопки связь с этой группой
    button->setButtonGroup(nullptr);
}


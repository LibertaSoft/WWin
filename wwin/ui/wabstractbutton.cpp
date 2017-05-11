#include "wabstractbutton.h"
#include "wbuttongroup.h"
#include <iostream>

void WAbstractButton::checkStateSet()
{}

/*!
 * \brief Возвращает true если позиция кликабельного региона; в остальных случаях возвращает false.
 * По умолчанию кликабельная зона - внутри всего виджета.
 * Подклассы могут переопределять данный метод для реализации кликабельной зоны различных форм и размеров.
 * \return
 */
bool WAbstractButton::hitButton(const int x, const int y) const
{
    return true;
}

/*!
 * \brief WAbstractButton::nextCheckState переключить состояние кнопки на следующее
 * По умолчанию переключает setChecded(!isChecked()) если кнопка может переключаться - isCheckable()
 */
void WAbstractButton::nextCheckState()
{
    if( this->isCheckable() ){
        this->setChecked( ! this->isChecked() );
        for(auto callback : _cblToggled){
            callback( new WMouseEvent, this->isChecked() );
        }
    }

    // BM_SETSTYLE <? Стили
}

/*!
 * \brief WAbstractButton::on_pressed Добавляет метод обработки нажатия кнопки.
 * Срабатывает до клика и до отпускания(release)
 * \param callback - функция обработчик
 */
/*
void WAbstractButton::on_pressed(std::function<void (WMouseEvent *)> callback)
{
    _cblPressed.push_back( callback );
}
//*/

/*!
 * \brief WAbstractButton::on_releaseed Добавляет метод обработки нажатия кнопки.
 * Срабатывает после нажатия(press) и перед кликом
 * \param callback - функция обработчик
 */
/*
void WAbstractButton::on_releaseed(std::function<void (WMouseEvent *)> callback)
{
    _cblReleased.push_back( callback );
}
//*/

/*!
 * \brief WAbstractButton::on_clicked Добавляет метод обработки клика на кнопку.
 * Срабатывает после нажатия(press) и после отпускания(release)
 * \param callback - функция обработчик
 */
void WAbstractButton::on_clicked(std::function<void (WMouseEvent *, bool)> callback)
{
    _cblClicked.push_back( callback );
}

/*!
 * \brief WAbstractButton::on_Toggleed Добавляет обработчик при переключении состояния кнопки.
 * Срабатывает при изменении состояния кнопки
 * \param callback - функция обработчик
 */
void WAbstractButton::on_toggleed(std::function<void (WMouseEvent *, bool)> callback)
{
    _cblToggled.push_back( callback );
}

/*!
 * \brief WAbstractButton::WAbstractButton Конструктор кнопки
 * \param parent
 */
WAbstractButton::WAbstractButton(WWidget *parent)
    : WWidget(parent)
{}

/*!
 * \brief WAbstractButton::~WAbstractButton Виртуальный деструктор, с удалением кнопки из группы
 * чтобы избежать обращения по некорректному указателю
 */
WAbstractButton::~WAbstractButton()
{
    if( _buttonGroup ){
        this->group()->removeButton(this);
    }
}

/*!
 * \brief WAbstractButton::click метод имитирует клик на кнопку, не проверяет нахождение мыши в кликабельной зоне
 */
void WAbstractButton::click()
{
    this->nextCheckState();
    /// \todo press ?
    /// \todo release ?
    for(auto callback : _cblClicked){
        callback( new WMouseEvent, this->isChecked() );
    }
}

/*!
 * \brief WAbstractButton::isCheckable переключаются ли состояния кнопки
 * \return bool
 */
bool WAbstractButton::isCheckable() const
{
    return _checkable;
}

/*!
 * \brief WAbstractButton::setCheckable установить для кнопки возможность переключения состояний
 * \param checkable
 */
void WAbstractButton::setCheckable(bool checkable)
{
    _checkable = checkable;
}

/*!
 * \brief WAbstractButton::isChecked находится ли кнопка в "нажатом"(checked) состоянии
 * \return bool
 */
bool WAbstractButton::isChecked() const
{
    return _checked;
}

/*!
 * \brief WAbstractButton::setChecked установить состояние(checked) кнопки
 * \param checked
 */
void WAbstractButton::setChecked(const bool checked)
{
    _checked = checked;
    WPARAM state = (checked) ? BST_CHECKED : BST_UNCHECKED;
    SendMessage(this->hwnd(), BM_SETCHECK, state, 0);
}

void WAbstractButton::setButtonGroup(WButtonGroup *group)
{
    _buttonGroup = group;
}

WButtonGroup* WAbstractButton::group() const
{
    return _buttonGroup;
}

/*!
 * \brief WAbstractButton::toggle Переключить состояние кнопки.
 * Переводит кнопку в следующее состояние.
 * Вызывает установленные для кнопки обработчики на событие переключения состояния.
 */
void WAbstractButton::toggle()
{
    this->nextCheckState();
    for(auto callback : _cblToggled){
        callback( new WMouseEvent, this->isChecked() );
    }
}

/**
 * @brief WAbstractButton::mouseReleaseEvent событие отпускания кнопки
 * @param event - экземпляр WMouseEvent
 * @return WEvent::isAccepted
 */
bool WAbstractButton::mouseReleaseEvent(WMouseEvent *event)
{
    this->nextCheckState();

    for(auto callback : _cblReleased){
        callback(event);
    }
    for(auto callback : _cblClicked){
        callback(event, this->isChecked());
    }

    event->accept();
    return event->isAccepted();
}

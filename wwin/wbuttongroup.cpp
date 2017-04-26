#include "wbuttongroup.h"

WButtonGroup::WButtonGroup(WObject parent = nullptr)
    : WObject(parent)
{

}

WButtonGroup::~WButtonGroup()
{
    for(WAbstractButton* btn : _buttons){
        btn->setButtonGroup(nullptr);
    }
}

void WButtonGroup::addButton(WAbstractButton *button, int id)
{
    _buttons.push_back( button );
    _mapping[id] = button;

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

WAbstractButton *WButtonGroup::button(int id)
{
    return _mapping[id];
}

std::list<WAbstractButton *> WButtonGroup::buttons() const
{
    return _buttons;
}

WAbstractButton *WButtonGroup::checkedButton() const
{
    return _checkedButton;
}

int WButtonGroup::checkedId() const
{
    return _checkedId;
}

bool WButtonGroup::exclusive() const
{
    return _exclusive;
}

void WButtonGroup::setExclusive(bool exclusive)
{
    _exclusive = exclusive;
}

int WButtonGroup::id(WAbstractButton *button) const
{
    for(auto btn : _mapping){
        if( btn.second == button ) {
            return btn.first;
        }
    }
    return -1;
}

void WButtonGroup::removeButton(WAbstractButton *button)
{
    // Защита от дурака
    if( button == nullptr ){
        return;
    }
    // Если удаляемая кнопка является чекнутой
    if( button == _checkedButton ){
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


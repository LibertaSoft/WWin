#ifndef WBUTTONGROUP_H
#define WBUTTONGROUP_H

#include "wwin/wobject.h"
#include "wwin/ui/wabstractbutton.h"

#include <list>
#include <map>
#include <unordered_map>

/*!
 * \brief The WButtonGroup класс предоставляет контейнер для организации групп виджетов-кнопок.
 */
class WButtonGroup : public WObject
{
private:
    bool _exclusive = true;
    std::list<WAbstractButton*> _buttons;
    std::map<int, WAbstractButton*> _mapping; /// \todo what happened? unordered_map is not

    int _checkedId = -1;
    WAbstractButton* _checkedButton = nullptr;

public:
    WButtonGroup(WObject parent);
    virtual ~WButtonGroup();

    void addButton(WAbstractButton *button, int id = -1);
    WAbstractButton *button(int id);
    std::list<WAbstractButton*> buttons() const;
    WAbstractButton* checkedButton() const;
    int checkedId() const;

    bool exclusive() const;
    void setExclusive(bool exclusive);

    int id(WAbstractButton* button) const;
    void removeButton(WAbstractButton* button);

    // void setId(WAbstractButton* button, int id);
};

#endif // WBUTTONGROUP_H

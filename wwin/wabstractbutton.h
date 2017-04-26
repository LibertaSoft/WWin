#ifndef WABSTRACTBUTTON_H
#define WABSTRACTBUTTON_H

#include <functional>
#include <vector>

#include "wwidget.h"

/*!
 * \brief QAbstractButton Класс является базовым классом для виджетов кнопок,
 * реализует общий функционал для кнопок.
 */
class WAbstractButton : public WWidget
{
private:
    bool _checkable = false; /// < Переключает ли кнопка состояния
    bool _checked = false; /// < Состояние
    bool _down = false; /// < Зажата ли кнопка

    bool _autoExclusive = false; /// < [Не используется] Нужно для реализации поведения кнопки в группах. WRadioButton

    /// \todo needly WTimer
    bool _autoRepeat = false; /// < [Не используется] Авто-повтор событий
    int  _autoRepeatDelay = 1000;  /// < [Не используется] Время до срабатывания первого авто-повтора
    int  _autoRepeatInterval = 1000; /// < [Не используется] Интервал срабатывания авто-повтора

    // WButtonGroup* _buttonGroup; /// < [Не используется] Указатель на группу к которой относится кнопка

private: // Callbacks
    std::vector< std::function<void(WMouseEvent*)> > _cblPressed;
    std::vector< std::function<void(WMouseEvent*)> > _cblReleased;
    std::vector< std::function<void(WMouseEvent*, bool checked)> > _cblClicked;
    std::vector< std::function<void(WMouseEvent*, bool checked)> > _cblToggled;

protected: // Можно переопределять для изменения поведения при разных состояниях
    virtual void checkStateSet();
    virtual bool hitButton(const int x, const int y) const;
    virtual void nextCheckState();

public: // event sobscribers
    void on_pressed(std::function<void(WMouseEvent*)> callback);
    void on_releaseed(std::function<void(WMouseEvent*)> callback);
    void on_clicked(std::function<void(WMouseEvent*, bool checked)> callback);
    void on_toggleed(std::function<void(WMouseEvent*, bool checked)> callback);

public:
    WAbstractButton(WWidget *parent);

    bool isCheckable() const;
    void setCheckable(bool checkable);
    bool isChecked() const;
    void setChecked(bool checked);

    // WButtonGroup group() const;

    void click();
    void toggle();

    // void setIconSize(const WSize &size);
    // WSize iconSize() const;

    // void setIcon(WIcon &icon);
    // WIcon icon() const;

public:
    // bool event(WEvent *event);
    bool mouseReleaseEvent(WMouseEvent *event);
    bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // WABSTRACTBUTTON_H

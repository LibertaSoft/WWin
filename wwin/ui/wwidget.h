#ifndef WWIDGET_H
#define WWIDGET_H

#include "wwin/wobject.h"
#include "wwin/wstring.h"
#include "wwin/wsize.h"

#include "wwin/wmouseevent.h"
#include "wwin/wresizeevent.h"
#include "wwin/wmoveevent.h"
#include "wwin/wpaintdevice.h"
#include "wwin/wpaintevent.h"
/**
 * @brief WWidgetState перечисление с состояниями окна виджета
 */
enum WWidgetState{
    ForceMinimize = SW_FORCEMINIMIZE,
    Hide = SW_HIDE,
    Maximize = SW_MAXIMIZE,
    Minimize = SW_MINIMIZE,
    Restore = SW_RESTORE,
    Show = SW_SHOW,
    ShowDefault = SW_SHOWDEFAULT,
    ShowMaximized = SW_SHOWMAXIMIZED,
    ShowMinimized = SW_SHOWMINIMIZED,
    ShowMinNoActive = SW_SHOWMINNOACTIVE,
    ShowNoActive = SW_SHOWNA,
    ShowNoActivate = SW_SHOWNOACTIVATE,
    ShowNormal = SW_SHOWNORMAL
};

/**
 * @brief WWidget класс являющийся базовым для всех виджетов системы.
 *
 * Если Вы хотите реализовать свой виджет, то Вам необходимо унаследовать этот класс
 * и переопределить, как минимум, методы:
 * - style()
 * - nativeEvent()
 */
class WWidget : public WObject, public WPaintDevice
{
private:
    WRect _geometry; /// < Текущий размер виджета

    WSize _minSize; /// < Минимальный размер виджета
    WSize _maxSize; /// < Максимальный размер виджета

    /// \todo change to WRect or WMargins
    int _contentMargins_top    = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_right  = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_bottom = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_left   = 0; /// < [Не используется] отступы для системы Layout'ов

    // Widget
    int _windowIcon   = 0; /// < [Не используется] ICON from RC || file
    int _windowParams = 0; /// < Show/Hide текущие параметры виджета
    WString _name; /// < [Не используется]

    bool _isDisabled = false; /// < Отключен ли виджет
    bool _isFocused  = false; /// < Находится ли виджет в фокусе (фокус пока только устанавливается в true, но не теряется)
    bool _isVisible  = false; /// < Виден ли виджет

//    WLayout* _layout = nullptr;

    HWND _hwnd = nullptr; /// < Хендлер окна
    int _cid = 0; /// < ID компонента
    static int _componentCount; /// < Количество компонентов в системе

protected:
    WString _className = L"WWIDGET"; /// < Название класса окна
    WString _title; /// < Заголовок окна

    virtual int style();
    void setStyle(int style);
    bool initWndClass(WString className);
    static int nextCid();

    virtual bool event(WEvent *e) override;
    virtual bool mouseReleaseEvent(WMouseEvent *e);
    virtual bool mouseDoubleClickEvent(WMouseEvent *e);
    virtual bool changeEvent(WEvent *e);
    /*
    virtual bool keyPressEvent(WKeyEvent *e);
    virtual bool keyReleaseEvent(WKeyEvent *e);
    //*/
    virtual bool resizeEvent(WResizeEvent *e);
    virtual bool moveEvent(WMoveEvent *e);
    virtual bool paintEvent(WPaintEvent *e);
    /*
    virtual bool wheelEvent(WWheelEvent *e);
    virtual bool mouseMoveEvent(WMouseEvent *e);
    virtual bool mousePressEvent(WMouseEvent *e);

    virtual bool showEvent(WShowEvent *e);
    virtual bool hideEvent(WHideEvent *e);
    virtual bool closeEvent(WCloseEvent *e);

    virtual bool enterEvent(WEvent *e);



    virtual bool dragEnter(WDragEvent *e);
    virtual bool dragLeave(WDragEvent *e);
    virtual bool dragMove(WDragEvent *e);

    virtual bool dropEvent(WDropEvent *e);
    //*/

public:
    WWidget(WWidget *parent = nullptr, int params = WWidgetState::Show);
    virtual ~WWidget();

    HWND hwnd() const;
    HWND parentWindowHwnd() const;
    WORD cid() const;
    void hwnd(HWND hwnd);

    virtual void show();
    virtual void hide();

    void setGeometry(int x, int y, int width, int height);
    void geometry(int* x, int* y, int* width, int* height) const;
    WRect geometry() const;

    WString title() const;
    void setTitle(const WString &title);

    void setEnable(const bool enable);
    void disable();
    void enable();

    bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

    void setFocus();
    bool isVisible() const;
};

#endif // WWIDGET_H

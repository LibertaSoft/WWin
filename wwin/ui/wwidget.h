#ifndef WWIDGET_H
#define WWIDGET_H

#include "wwin/wobject.h"
#include "wwin/wstring.h"

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
    // Geometry
    /// \todo change to WRect ?
    int _x = 0;
    int _y = 0;
    int _width = 0;
    int _height = 0;

    /// \todo change to WSize
    int _maxWidth = 16777215;  /// < [Не используется] размеры для системы Layout'ов
    int _maxHeight = 16777215; /// < [Не используется] размеры для системы Layout'ов

    /// \todo change to WSize
    int _minWidth = 0;   /// < [Не используется] размеры для системы Layout'ов
    int _minHeight = 0;  /// < [Не используется] размеры для системы Layout'ов

    /// \todo change too WRect or WMargins
    int _contentMargins_top    = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_right  = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_bottom = 0; /// < [Не используется] отступы для системы Layout'ов
    int _contentMargins_left   = 0; /// < [Не используется] отступы для системы Layout'ов

    // Widget
    int  _windowIcon   = 0; /// < [Не используется] ICON from RC || file
    int  _windowParams = 0; /// < [Не используется] FullScreen || ! FullScreen
    WString _name; /// < [Не используется]

    bool _isDisabled = false; /// < [Не используется]
    bool _isFocused  = false; /// < [Не используется]
    bool _isVisible  = false; /// < [Не используется]

//    WLayout* _layout = nullptr;

    HWND _hwnd = nullptr; /// < Хендлер окна
    int _cid = 0; /// < ID компонента
    static int _componentCount; /// < Количество компонентов в системе

    WWidget *parentWidget() const;

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
    HWND parentHwnd() const;
    WORD cid() const;
    void hwnd(HWND hwnd);
    void show();

    void setGeometry(int x, int y, int width, int height);
    WString title() const;
    void setTitle(const WString &title);

    void setEnable(const bool enable);
    void disable();
    void enable();

    bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

    void setFocus();
};

#endif // WWIDGET_H

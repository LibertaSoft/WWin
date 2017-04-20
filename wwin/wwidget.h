#ifndef WWIDGET_H
#define WWIDGET_H

#include "wwin/wobject.h"
#include "wwin/wmouseevent.h"
#include "wwin/wstring.h"

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

class WWidget : public WObject
{
private:
    // Geometry
    int _x = 0;
    int _y = 0;
    int _width = 0;
    int _height = 0;

    int _maxWidth = 16777215;
    int _maxHeight = 16777215;

    int _minWidth = 0;
    int _minHeight = 0;

    int _contentMargins_top    = 0;
    int _contentMargins_right  = 0;
    int _contentMargins_bottom = 0;
    int _contentMargins_left   = 0;

    // Widget
    int  _windowIcon   = 0; // ICON from RC || file
    int  _windowParams = 0; // FullScreen || ! FullScreen
    WString _name;

    bool _isDisabled = false;
    bool _isFocused  = false;
    bool _isVisible  = false;

//    WLayout* _layout = nullptr;

    HWND _hwnd = nullptr;
    int _cid = 0;
    static int _componentCount;

    WWidget *parentWidget() const;



protected:
    WString _className = L"WWIDGET";
    WString _title;
    std::wstring _title2;

    virtual int style();
    bool init();

    virtual bool event(WEvent *e);
    virtual bool mouseEvent(WMouseEvent *e);
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

    bool processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

    void setFocus();
};

#endif // WWIDGET_H

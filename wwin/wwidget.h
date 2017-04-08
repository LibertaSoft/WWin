#ifndef WWIDGET_H
#define WWIDGET_H

#include "wwin/wobject.h"

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
    HWND _hwnd = nullptr;
    int  _windowParams = 0;
    std::string _name;

    bool _isDisabled = false;
    bool _isFocused  = false;
    bool _isVisible  = false;

//    WLayout* _layout = nullptr;

    int _windowIcon = 0; // ICON from RC || file
    int _windowState = 0; // FullScreen || ! FullScreen

    HWND hwnd() const;
    HWND parentHwnd() const;
    WWidget *parentWidget() const;

    virtual int style();
protected:
    std::string _className = "WWINAPI";
    std::string _title;
public:
    WWidget(WWidget *parent = nullptr, int params = WWidgetState::Show);

    void show();

    void setGeometry(int x, int y, int width, int height);
    std::string title() const;
    void setTitle(const std::string &title);
};

#endif // WWIDGET_H

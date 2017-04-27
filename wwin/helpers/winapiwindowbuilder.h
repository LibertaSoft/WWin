#ifndef WINAPIWINDOWBUILDER_H
#define WINAPIWINDOWBUILDER_H

#include <windows.h>
#include "wwin/wstring.h"

/**
 * @brief WinApiWindowBuilder Класс реализующий паттерн Builder для конструирования окна
 */
class WinApiWindowBuilder
{
private:
    int _x = 0;
    int _y = 0;
    int _width  = 0;
    int _height = 0;

    WString _className;
    WString _title;
    HWND _parent;

    DWORD _style = 0;

    HMENU _menu = nullptr;

    LPVOID _param = NULL;

    HINSTANCE _hinstance;

public:
    WinApiWindowBuilder(WString className = L"");

    WinApiWindowBuilder& geometry(int x,int y ,int width, int height);
    WinApiWindowBuilder& className(WString className);
    WinApiWindowBuilder& classExtra(LONG classex);
    WinApiWindowBuilder& title(WString title);
    WinApiWindowBuilder& parent(HWND parent);
    WinApiWindowBuilder& style(DWORD style);
    WinApiWindowBuilder& menu(HMENU menu);
    WinApiWindowBuilder& param(LPVOID param);
    WinApiWindowBuilder& hinstance(HINSTANCE hinstance);
    HWND build();
};

#endif // WINAPIWINDOWBUILDER_H

#ifndef WINAPIWINDOWBUILDER_H
#define WINAPIWINDOWBUILDER_H

#include <windows.h>
#include <string>

class WinApiWindowBuilder
{
private:
    int _x = 0;
    int _y = 0;
    int _width  = 0;
    int _height = 0;

    std::string _className;
    std::string _title;
    HWND _parent;

    DWORD _style = 0;

    HMENU _menu = nullptr;

    LPVOID _param = NULL;

    HINSTANCE _hinstance;

public:
    WinApiWindowBuilder(std::string className = "");

    WinApiWindowBuilder& geometry(int x,int y ,int width, int height);
    WinApiWindowBuilder& className(std::string className);
    WinApiWindowBuilder& title(std::string title);
    WinApiWindowBuilder& parent(HWND parent);
    WinApiWindowBuilder& style(DWORD style);
    WinApiWindowBuilder& menu(HMENU menu);
    WinApiWindowBuilder& param(LPVOID param);
    WinApiWindowBuilder& hinstance(HINSTANCE hinstance);
    HWND build();
};

#endif // WINAPIWINDOWBUILDER_H

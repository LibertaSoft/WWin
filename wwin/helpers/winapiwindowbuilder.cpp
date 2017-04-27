#include "winapiwindowbuilder.h"

/**
 * @brief WinApiWindowBuilder::WinApiWindowBuilder Конструктор с именем класса
 * @param className
 */
WinApiWindowBuilder::WinApiWindowBuilder(WString className)
{
    _className = className;
}

/**
 * @brief WinApiWindowBuilder::geometry задать расположение окна
 * @param x
 * @param y
 * @param width
 * @param height
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::geometry(int x, int y, int width, int height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::className задать имя класса
 * @param className
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::className(WString className)
{
    _className = className;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::title задать заголовок окна
 * @param title
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::title(WString title)
{
    _title = title;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::parent задать родительское окно
 * @param parent
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::parent(HWND parent = HWND_DESKTOP)
{
    _parent = parent;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::style задать стиль окна
 * @param style
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::style(DWORD style)
{
    _style = style;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::menu задать wParam окна
 * @param menu
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::menu(HMENU menu)
{
    _menu = menu;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::param задать lParam для окна
 * @param param
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::param(LPVOID param)
{
    _param = param;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::hinstance задать hinstance для окна
 * @param hinstance
 * @return
 */
WinApiWindowBuilder &WinApiWindowBuilder::hinstance(HINSTANCE hinstance)
{
    _hinstance = hinstance;
    return *this;
}

/**
 * @brief WinApiWindowBuilder::build создать окно с установленными ранее параметрами
 * @return HWND созданного окна
 */
HWND WinApiWindowBuilder::build()
{
    return
    CreateWindow(
        _className.c_str(),
        _title.c_str(),
        _style,
        _x, _y, _width, _height,
        _parent,
        _menu,
        _hinstance,
        _param
    );

//    CreateWindowEx(
//                _style,
//    );
}


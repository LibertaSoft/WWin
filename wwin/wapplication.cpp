#include "wapplication.h"
#include "wwin/wevent.h"
#include <string>

#include <iostream>

WApplication* WApplication::_appInstance = nullptr;

WApplication::WApplication(int &, char **)
{
    init();
}

WApplication::WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    _hInstance = hInstance;
    _hPrevInstance = hPrevInstance;
    _lpCmdLine = lpCmdLine;
    _nCmdShow = nCmdShow;

    init();
}

WApplication* WApplication::instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if( ! _appInstance ) {
        _appInstance = new WApplication(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
        return _appInstance;
    }
    return _appInstance;
}

WApplication* WApplication::instance()
{
    return _appInstance;
}

void WApplication::addComponent(WWidget *object)
{
    this->_objects[object->hwnd()] = object;
}

void WApplication::removeComponent(const WWidget* object)
{
    for (auto it = begin(_objects); it != end(_objects);) {
        if(it->first == object->hwnd()) {
            it = _objects.erase(it);
        } else {
            ++it;
        }
    }
}

HINSTANCE WApplication::getHinstance()
{
    return _hInstance;
}

int WApplication::run()
{
    MSG msg;

    while( GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return msg.wParam;
}

void WApplication::init()
{
    hideConsole();
    if( ! this->registerClass() ){
        return;
    }
    return;
}

ATOM WApplication::registerClass()
{
    WNDCLASS wcl;

    wcl.hInstance = _hInstance;
    wcl.lpszClassName = L"WWIDGET";
    wcl.lpfnWndProc = &WApplication::wndproc;
    wcl.style = CS_VREDRAW | CS_HREDRAW;
    wcl.hIcon = NULL;
    wcl.hCursor = NULL;
    wcl.lpszMenuName = NULL;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hbrBackground = ( HBRUSH )GetStockObject( WHITE_BRUSH );

    return RegisterClass( &wcl );
}

void WApplication::hideConsole()
{
    //*
    const LPCWSTR consoleName = L"WWIN-HIDE-5648-45748-DFJHV-SDAYUF-SNVNS";
    SetConsoleTitle(consoleName);
    HWND console = FindWindow(NULL, consoleName);
    if(console == 0) {
        /// \todo handle errors
    }
    ShowWindow(console, SW_HIDE);
    // */
}

LRESULT WApplication::wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch( message ){
      case WM_DESTROY:
        /// \todo Process in ever window, if close one closed all
        PostQuitMessage( EXIT_SUCCESS );
        break;
      case WM_COMMAND:
      case WM_CONTEXTMENU:
      case WM_KEYDOWN:
        WApplication::handleEvents( hWnd, message, wParam, lParam );
        break;
      default:
        return DefWindowProc( hWnd, message, wParam, lParam );
    }
    return wParam;
}

void WApplication::handleEvents(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    WObject* component = wApp->components()[hWnd];
    std::cout << "WApp::handleEvents: " << hWnd << std::endl;
    if( ! component ) {
        throw "NullPointerException: Widget is not exists.";
        return;
    }
    if( HIWORD( wParam ) == LBN_DBLCLK || HIWORD( wParam ) == BN_CLICKED ) {
        WEvent* evt = new WMouseEvent();
        component->event(evt);
    }
}

WComponentsMap WApplication::components()
{
    return _objects;
}

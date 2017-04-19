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
    (this->_objects[object->parentHwnd()])[object->cid()] = object;
}

void WApplication::removeComponent(const WWidget* object)
{
//    for (auto it_d = begin(_objects); it_d != end(_objects);) {
//        for (auto it_c = begin(*it_d); it_c != end(*it_d);){
//            if(it_c->first == object->hwnd()) {
//                it_c = _objects.erase(it_c);
//            } else {
//                ++it_c;
//            }
//        }
//    }
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
    WORD cid = LOWORD(wParam);
    WObject* component = wApp->component(hWnd, cid);
    if( ! component ) {
        // throw "NullPointerException: Widget is not exists.";
        return;
    }
    if( HIWORD( wParam ) == BN_CLICKED ) {
        WMouseEvent* evt = new WMouseEvent();
        POINT p;
        if( GetCursorPos(&p) ){
            evt->setCursorPos(p.x, p.y);
        }
        evt->setButton(WMouseButton::LeftButton);
        int mod = WMouseKeyModifiers::NoModifier;
        if( GetAsyncKeyState(VK_LSHIFT) < 0 || GetAsyncKeyState(VK_RSHIFT) < 0 ){
            mod |= WMouseKeyModifiers::ShiftModifier;
        }
        if( GetKeyState(VK_LCONTROL) < 0 || GetKeyState(VK_RCONTROL) < 0 ){
            mod |= WMouseKeyModifiers::ControlModifier;
        }
        if( GetAsyncKeyState(VK_LMENU) < 0 || GetAsyncKeyState(VK_RMENU) < 0 ){
            mod |= WMouseKeyModifiers::AltModifier;
        }
        if( GetAsyncKeyState(VK_LWIN) < 0 || GetAsyncKeyState(VK_RWIN) < 0 ){
            mod |= WMouseKeyModifiers::MetaModifier;
        }
        evt->setModifiers(mod);
        component->event(evt);
    }
}

WComponentsMap &WApplication::components(HWND hwnd)
{
    return _objects[hwnd];
}

WObject *WApplication::component(HWND hwnd, WORD cid)
{
    return _objects[hwnd][cid];
}

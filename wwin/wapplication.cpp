#include "wapplication.h"
#include "wwin/wobject.h"
#include <string>

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
    if( ! this->registerClass() ){
        return;
    }
    return;
}

ATOM WApplication::registerClass()
{
    WNDCLASS wcl;

    wcl.hInstance = _hInstance;
    wcl.lpszClassName = L"WWINAPI";
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

LRESULT WApplication::wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch( message ){
      case WM_DESTROY:
        PostQuitMessage( EXIT_SUCCESS );
        break;
    //      case WM_COMMAND:
    //        HandleEvents( hWnd, wParam);
    //        break;
      default:
        return DefWindowProc( hWnd, message, wParam, lParam );
    }
    return wParam;
}

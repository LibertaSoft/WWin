#include "wapplication.h"
#include "wwin/wevent.h"

#include <iostream>

WApplication* WApplication::_appInstance = nullptr;

/**
 * @brief [Не используется] WApplication::WApplication Конструктор инициализирующий приложение
 */
WApplication::WApplication(int &, char **)
{
    init();
}

/**
 * @brief WApplication::WApplication Конструктор с расширенными параметрами инициализирующий работу приложения.
 * @param hInstance
 * @param hPrevInstance
 * @param lpCmdLine
 * @param nCmdShow
 */
WApplication::WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    _hInstance = hInstance;
    _hPrevInstance = hPrevInstance;
    _lpCmdLine = lpCmdLine;
    _nCmdShow = nCmdShow;

    init();
}

/**
 * @brief WApplication::instance метод с параметрами для получения экземпляра приложения,
 * т.к. приложение является Singletone'ом, этот метод используется для первоначальной инициализации
 * экземпляра приложения.
 * @param hInstance
 * @param hPrevInstance
 * @param lpCmdLine - параметры командной строки
 * @param nCmdShow
 * @return
 */
WApplication* WApplication::instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if( ! _appInstance ) {
        _appInstance = new WApplication(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
        return _appInstance;
    }
    return _appInstance;
}

/**
 * @brief WApplication::instance метод для получения экземпляра приложение,
 * т.к. приложение является Singletone'ом этот метод необходимо использовать всюду
 * если вам необходим экземпляр приложения, так же можно воспользоваться макросом wApp
 * @return
 */
WApplication* WApplication::instance()
{
    return _appInstance;
}

/**
 * @brief WApplication::addComponent метод для регистрации нового компонента в приложении
 * необходимо для передачи компоненту всех событий приложения и их обработки.
 * Самостоятельно вызывается классом WWidget
 * @param object указатель на объект класса WWidget
 */
void WApplication::addComponent(WWidget *object)
{
    HWND hwnd = nullptr;
    if( object->parentHwnd() == nullptr ){
      hwnd = object->hwnd();
    } else {
      hwnd = object->parentHwnd();
    }
    (this->_objects[hwnd])[object->cid()] = object;
}

/**
 * @brief WApplication::removeComponent метод для удаления компонента
 * из списка компонентов приложения, компоненту больше не будут доставляться события от приложения.
 * @param object
 */
void WApplication::removeComponent(const WWidget* object)
{
    HWND hwnd = nullptr;
    if( object->parentHwnd() == nullptr ){
      hwnd = object->hwnd();
    } else {
      hwnd = object->parentHwnd();
    }
    (_objects[hwnd]).erase(object->cid());
}

/**
 * @brief WApplication::getHinstance метод позволяющий получить HINSTANCE приложения.
 * @return HINSTANCE - приложения
 */
HINSTANCE WApplication::getHinstance()
{
    return _hInstance;
}

/**
 * @brief WApplication::run метод запускающий цикл событий и обработку сообщений.
 * @return int - как результат работы приложения. Если приложение завершило работу
 * корректно будет равен `0`, в противном случае вернётся значение отличное от нуля.
 */
int WApplication::run()
{
    MSG msg;

    while( GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return msg.wParam;
}

/**
 * @brief WApplication::init инициализация приложения, вызывается в конструкторе.
 * Региструрует базовый класс для окон WWIDGET
 */
WString WApplication::applicationName() const
{
    return _applicationName;
}

void WApplication::setApplicationName(WString applicationName)
{
    _applicationName = applicationName;
}

WString WApplication::userName() const
{
    return _userName;
}

WString WApplication::applicationVersion() const
{
    return _applicationVersion;
}

void WApplication::setApplicationVersion(const WString &applicationVersion)
{
    _applicationVersion = applicationVersion;
}

void WApplication::init()
{
    wchar_t buffer[255];
    DWORD len = 255;
    GetEnvironmentVariable(L"USERNAME", buffer, len);
    _userName = WString(buffer);

    hideConsole();
    if( ! this->registerClass() ){
        return;
    }
    return;
}

/**
 * @brief WApplication::registerClass Регистрирует базовый класс для окон приложения WWIDGET.
 * @return ATOM - результат регистрации класса в WINAPI
 */
ATOM WApplication::registerClass()
{
    WNDCLASS wcl;

    wcl.hInstance = _hInstance;
    wcl.lpszClassName = L"WWIDGET";
    wcl.lpfnWndProc = &WApplication::wndproc;
    wcl.style = CS_VREDRAW | CS_HREDRAW;
    wcl.hIcon = NULL;
    wcl.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcl.lpszMenuName = NULL;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hbrBackground = ( HBRUSH )COLOR_WINDOW;//( HBRUSH )GetStockObject( COLOR_GRAYTEXT );

    return RegisterClass( &wcl );
}

/**
 * @brief WApplication::hideConsole метод для скрытия консоли
 * @warning работает 50/50
 */
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

/**
 * @brief WApplication::wndproc основная процедура обработки сообщений.
 * Вызывает WObject::nativeEvent для обработки сообщений.
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return
 */
LRESULT WApplication::wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    WORD cid = LOWORD(wParam);
    /*
    if( message == WM_LBUTTONDOWN ){
        cid = 5;
        SendMessage(hWnd, WM_COMMAND, BN_PUSHED | cid, 0);
        // CreateWindowEx()
    }
    //*/
    WObject* component = wApp->component(hWnd, cid);

    if( message == WM_DESTROY ){
        PostQuitMessage( EXIT_SUCCESS );
    }

    bool accept = false;
    if( component ) {
        accept = component->nativeEvent(hWnd, message, wParam, lParam);
    }
    if( ! accept ){
        return DefWindowProc( hWnd, message, wParam, lParam );
    }
    return wParam;
}

/**
 * @brief WApplication::components возвращает ссылку на компоненты окна по переданному HWND
 * @param hwnd - HWND окна, список компонентов которого будет возвращён.
 * @return WComponentsMap - список компонентов с ключём - CID(ComponentID)
 */
WComponentsMap &WApplication::components(HWND hwnd)
{
    return _objects[hwnd];
}

/**
 * @brief WApplication::component позволяет получить компонент по HWND и CID
 * @param hwnd - HWND окна в котором располагается искомый компонент
 * @param cid - CID(ComponentID) нужного компонента
 * @return WObject указатель на искомый компонент
 */
WObject *WApplication::component(HWND hwnd, WORD cid)
{
    return _objects[hwnd][cid];
}

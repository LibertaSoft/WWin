#ifndef WAPPLICATION_H
#define WAPPLICATION_H

#include <windows.h>
#include <map>
#include "wwin/ui/wwidget.h"
#include "wwin/wstring.h"

#define wApp WApplication::instance()
typedef std::map<WORD,WObject*> WComponentsMap;
typedef std::map<HWND,WComponentsMap> WDialogsMap;

/**
 * @brief Класс WApplication контроллирует работоу GUI компонентов приложения и основные настройками.
 */
class WApplication
{
private:
    static WApplication *_appInstance; /// < Singletone приложения

    WString _applicationName = L"WWinApplication";
    WString _applicationVersion = L"0.0.0";
    WString _userName = L"Unknown";

    HINSTANCE _hInstance = nullptr;
    HINSTANCE _hPrevInstance = nullptr;
    LPSTR     _lpCmdLine = nullptr;
    int       _nCmdShow  = 0;

    WDialogsMap _objects; /// < Все окна и компоненты приложения

    void init();
    ATOM registerClass();
    void hideConsole();
    static CALLBACK LRESULT wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    WComponentsMap& components(HWND hwnd);
    WObject* component(HWND hwnd, WORD cid);

    WApplication(int &argc, char** argv);
    WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

public:
    static WApplication *instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    static WApplication *instance(void);

    void addComponent(WWidget *object);
    void removeComponent(const WWidget *object);

    HINSTANCE getHinstance();

    int run();

    WString applicationName() const;
    void setApplicationName(WString applicationName);
    WString userName() const;
    WString applicationVersion() const;
    void setApplicationVersion(const WString &applicationVersion);
};

#endif // WAPPLICATION_H

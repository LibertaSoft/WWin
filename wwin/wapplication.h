#ifndef WAPPLICATION_H
#define WAPPLICATION_H

#include <windows.h>
#include "wwin/wwidget.h"
#include <unordered_map>

#define wApp WApplication::instance()

typedef std::unordered_map<HWND,WObject*> WComponentsMap;

class WApplication
{
private:
    static WApplication *_appInstance;

    HINSTANCE _hInstance = nullptr;
    HINSTANCE _hPrevInstance = nullptr;
    LPSTR     _lpCmdLine = nullptr;
    int       _nCmdShow  = 0;

    WComponentsMap _objects;

    void init();
    ATOM registerClass();
    void hideConsole();
    static CALLBACK LRESULT wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static void handleEvents(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    WComponentsMap components();

    WApplication(int &argc, char** argv);
    WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
public:
    static WApplication *instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    static WApplication *instance(void);

    void addComponent(WWidget *object);
    void removeComponent(const WWidget *object);

    HINSTANCE getHinstance();

    int run();
};

#endif // WAPPLICATION_H

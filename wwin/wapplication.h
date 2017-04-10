#ifndef WAPPLICATION_H
#define WAPPLICATION_H

#include <windows.h>
#include "wwin/wobject.h"
#include <unordered_map>

#define wApp WApplication::instance()

class WApplication
{
private:
    static WApplication *_appInstance;

    HINSTANCE _hInstance = nullptr;
    HINSTANCE _hPrevInstance = nullptr;
    LPSTR     _lpCmdLine = nullptr;
    int       _nCmdShow  = 0;

    std::unordered_map<HWND,const WObject*> _objects;

    void init();
    ATOM registerClass();
    void hideConsole();
    static CALLBACK LRESULT wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static void handleEvents(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    WApplication(int &argc, char** argv);
    WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
public:
    static WApplication *instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    static WApplication *instance(void);

    void addComponent(const WObject* object);
    void removeComponent(const WObject* object);

    HINSTANCE getHinstance();

    int run();
};

#endif // WAPPLICATION_H

#ifndef WAPPLICATION_H
#define WAPPLICATION_H

#include <windows.h>
#include <unordered_map>
#include "wwin/wwidget.h"

#define wApp WApplication::instance()
typedef std::unordered_map<WORD,WObject*> WComponentsMap;
typedef std::unordered_map<HWND,WComponentsMap> WDialogsMap;

class WApplication
{
private:
    static WApplication *_appInstance;

    HINSTANCE _hInstance = nullptr;
    HINSTANCE _hPrevInstance = nullptr;
    LPSTR     _lpCmdLine = nullptr;
    int       _nCmdShow  = 0;

    WDialogsMap _objects;

    void init();
    ATOM registerClass();
    void hideConsole();
    static CALLBACK LRESULT wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static void handleEvents(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

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
};

#endif // WAPPLICATION_H

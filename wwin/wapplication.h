#ifndef WAPPLICATION_H
#define WAPPLICATION_H

#include <windows.h>

class WApplication
{
private:
    static WApplication *_appInstance;

    HINSTANCE _hInstance = nullptr;
    HINSTANCE _hPrevInstance = nullptr;
    LPSTR     _lpCmdLine = nullptr;
    int       _nCmdShow  = 0;

    void init();
    ATOM registerClass();
    void hideConsole();
    static CALLBACK LRESULT wndproc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

    WApplication(int &argc, char** argv);
    WApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
public:
    static WApplication *instance(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    static WApplication *instance(void);

    HINSTANCE getHinstance();

    int run();
};

#endif // WAPPLICATION_H

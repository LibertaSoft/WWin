#include <WApplication>
#include "testwindow.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    TestWindow *w = new TestWindow(nullptr);
    w->show();
    w->initUi();

    return app->run();
}


/*
TCHAR * text;
#ifdef UNICODE
    // Simple C
    const size_t size = ( wcslen(text) + 1 ) * sizeof(wchar_t);
    wcstombs(&buffer[0], text, size);
    std::vector<char> buffer(size);
    //
    // Windows API (I would use this)
    std::vector<char> buffer;
    int size = WideCharToMultiByte(CP_UTF8, 0, text, -1, NULL, 0, NULL, NULL);
    if (size > 0) {
        buffer.resize(size);
        WideCharToMultiByte(CP_UTF8, 0, text, -1, static_cast<BYTE*>(&buffer[0]), buffer.size(), NULL, NULL);
    }
    else {
        // Error handling
    }
    ///
    WString string(&buffer[0]);
#else
    WString string(text);
#endif
//*/

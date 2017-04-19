#include <windows.h>
#include <wwin/wlineedit.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wscreen.h"
#include "wwin/wmessagebox.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

    TCHAR * text;

        /*/
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
        std::string string(&buffer[0]);
    #else
        std::string string(text);
    #endif
    //*/

    // Window pos
    int width  = 480;
    int height = 320;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    WWidget *wgt = new WWidget();
    wgt->setTitle("WWinApi Lib Title");
    wgt->setGeometry(x,y,width,height);
    wgt->show();

    WPushButton *btn = new WPushButton("My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();
    btn->on_click([](WMouseEvent*){
        WMessageBox::information(nullptr, "Title", "Button 1 clicked");
    });

    WLineEdit *edit = new WLineEdit("hellow", wgt);
    edit->setGeometry(10,80,250,20);
    edit->show();

    WPushButton *btn2 = new WPushButton("My Button Привет 2", wgt);
    btn2->setGeometry(140,10,120,60);
    btn2->show();
    btn2->setFocus();
    btn2->on_click([&](WMouseEvent*e){
        WMessageBox::information(nullptr, "Title", edit->value());
        if( e->modifiers() & WMouseKeyModifiers::ControlModifier ){
            WMessageBox::information(nullptr, "Title", "Control is hold");
        }
    });




    return app->run();
}

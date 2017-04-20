#include <windows.h>
#include <wwin/wlineedit.h>
#include <wwin/wlistbox.h>
#include "wwin/wapplication.h"
#include "wwin/wwidget.h"

#include "wwin/wpushbutton.h"
#include "wwin/wscreen.h"
#include "wwin/wmessagebox.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);


        /*/
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

    // Window pos
    int width  = 480;
    int height = 320;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    WWidget *wgt = new WWidget();
    wgt->setTitle(L"WWinApi Lib Заголовок");
    wgt->setGeometry(x,y,width,height);
    wgt->show();

    WPushButton *btn = new WPushButton(L"My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();
    btn->on_click([](WMouseEvent*){
        WMessageBox::information(nullptr, L"Title", L"Button 1 clicked");
    });

    WLineEdit *edit = new WLineEdit(L"hellow", wgt);
    edit->setGeometry(10,80,250,20);
    edit->show();

    ListItems items = {
      L"Item 1",
      L"Item 2",
      L"Item 3",
      L"Item 4"
    };

    WListBox *listbox = new WListBox(items, wgt);
    listbox->setGeometry(10, 110, 250, 100);
    listbox->show();

    WPushButton *btn2 = new WPushButton(L"My Button Привет 2", wgt);
    btn2->setGeometry(140,10,120,60);
    btn2->show();
    btn2->setFocus();
    btn2->on_click([&](WMouseEvent*e){
        WMessageBox::information(nullptr, L"Title", edit->value());
        listbox->addListItem(edit->value());
        if( e->modifiers() & WMouseEvent::KeyModifiers::ControlModifier ){
            WMessageBox::information(nullptr, L"Title", L"Control is hold");
        }
    });



//    listbox

    return app->run();
}

#include "wmessagebox.h"
#include <windows.h>

WMessageBox::WMessageBox(WWidget *parent)
    : WWidget(parent)
{

}

void WMessageBox::critical(WWidget *parent, std::string title, std::string message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, WObject::tow(message), WObject::tow(title), MB_OK | MB_ICONERROR);
}

void WMessageBox::information(WWidget *parent, std::string title, std::string message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, WObject::tow(message), WObject::tow(title), MB_OK | MB_ICONINFORMATION);
}

void WMessageBox::question(WWidget *parent, std::string title, std::string message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, WObject::tow(message), WObject::tow(title), MB_OK | MB_ICONQUESTION);
}


void WMessageBox::warning(WWidget *parent, std::string title, std::string message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, WObject::tow(message), WObject::tow(title), MB_OK | MB_ICONWARNING);
}

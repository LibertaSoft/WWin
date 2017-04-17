#include "wmessagebox.h"
#include <windows.h>

WMessageBox::WMessageBox()
    : WObject(nullptr)
{

}

void WMessageBox::information(std::string title, std::string message)
{
    MessageBox(NULL, WObject::tow(title), WObject::tow(message), MB_OK);
}


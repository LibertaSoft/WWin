#include "wscreen.h"

#include <windows.h>

WScreen::WScreen()
    : WObject(nullptr)
{

}

int WScreen::width()
{
    HDC scr = GetDC( NULL );
    return GetDeviceCaps( scr, HORZRES );
}

int WScreen::height()
{
    HDC scr = GetDC( NULL );
    return GetDeviceCaps( scr, VERTRES );
}


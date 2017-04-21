#include "wscreen.h"

#include <windows.h>

/**
 * @brief WScreen::WScreen Конструктор класса
 */
WScreen::WScreen()
    : WObject(nullptr)
{}


/**
 * @brief WScreen::width получить ширину экрана
 * @return int - ширина экрана в пикселях
 */
int WScreen::width()
{
    HDC scr = GetDC( NULL );
    return GetDeviceCaps( scr, HORZRES );
}

/**
 * @brief WScreen::height получить высоту экрана
 * @return int - высота экрана в пикселях
 */
int WScreen::height()
{
    HDC scr = GetDC( NULL );
    return GetDeviceCaps( scr, VERTRES );
}


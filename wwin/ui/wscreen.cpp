#include "wscreen.h"

#include <windows.h>
#include <iostream>

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
    HMONITOR monitor = MonitorFromWindow(0, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info;
    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    return info.rcMonitor.right - info.rcMonitor.left;
}

/**
 * @brief WScreen::height получить высоту экрана
 * @return int - высота экрана в пикселях
 */
int WScreen::height()
{
    HMONITOR monitor = MonitorFromWindow(0, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info;

    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    return info.rcMonitor.bottom - info.rcMonitor.top;
}


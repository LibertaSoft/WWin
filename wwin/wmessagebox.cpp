#include "wmessagebox.h"
#include <windows.h>

/**
 * @brief WMessageBox::WMessageBox Конструктор диалогового окна
 * @param parent
 */
WMessageBox::WMessageBox(WWidget *parent)
    : WWidget(parent)
{}

/**
 * @brief WMessageBox::critical Выдать критическое сообщение
 * @param parent - родитель окна
 * @param title - заголовок окна
 * @param message - текст сообщения
 */
void WMessageBox::critical(WWidget *parent, WString title, WString message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, message.c_str(), title.c_str(), MB_OK | MB_ICONERROR);
}

/**
 * @brief WMessageBox::critical Выдать информационное сообщение
 * @param parent - родитель окна
 * @param title - заголовок окна
 * @param message - текст сообщения
 */
void WMessageBox::information(WWidget *parent, WString title, WString message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
//    parent->disable();
    MessageBox(hwnd, message.c_str(), title.c_str(), MB_OK | MB_TOPMOST );
//    parent->enable();
}

/**
 * @brief WMessageBox::critical Выдать вопросительное сообщение
 * @param parent - родитель окна
 * @param title - заголовок окна
 * @param message - текст сообщения
 */
void WMessageBox::question(WWidget *parent, WString title, WString message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, message.c_str(), title.c_str(), MB_OK | MB_ICONQUESTION);
}

/**
 * @brief WMessageBox::critical Выдать предупредительное сообщение
 * @param parent - родитель окна
 * @param title - заголовок окна
 * @param message - текст сообщения
 */
void WMessageBox::warning(WWidget *parent, WString title, WString message)
{
    HWND hwnd = nullptr;
    if(parent){
        parent->hwnd();
    }
    MessageBox(hwnd, message.c_str(), title.c_str(), MB_OK | MB_ICONWARNING);
}

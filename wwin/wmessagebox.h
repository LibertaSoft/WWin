#ifndef WMESSAGEBOX_H
#define WMESSAGEBOX_H

#include <string>
#include "wwin/wwidget.h"

class WMessageBox : public WWidget
{
public:
    WMessageBox(WWidget *parent = nullptr);
    static void critical(WWidget* parent, std::string title, std::string message);
    static void information(WWidget* parent, std::string title, std::string message);
    static void question(WWidget* parent, std::string title, std::string message);
    static void warning(WWidget* parent, std::string title, std::string message);
};

#endif // WMESSAGEBOX_H

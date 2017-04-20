#ifndef WMESSAGEBOX_H
#define WMESSAGEBOX_H

#include "wwin/wstring.h"
#include "wwin/wwidget.h"

class WMessageBox : public WWidget
{
public:
    WMessageBox(WWidget *parent = nullptr);
    static void critical(WWidget* parent, WString title, WString message);
    static void information(WWidget* parent, WString title, WString message);
    static void question(WWidget* parent, WString title, WString message);
    static void warning(WWidget* parent, WString title, WString message);
};

#endif // WMESSAGEBOX_H

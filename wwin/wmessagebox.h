#ifndef WMESSAGEBOX_H
#define WMESSAGEBOX_H

#include <string>
#include "wwin/wobject.h"

class WMessageBox : WObject
{
public:
    WMessageBox();
    static void information(std::string title, std::string message);
};

#endif // WMESSAGEBOX_H

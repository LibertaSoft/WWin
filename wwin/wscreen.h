#ifndef WSCREEN_H
#define WSCREEN_H

#include "wwin/wobject.h"

class WScreen : public WObject
{
    WScreen();
public:

    static int width();
    static int height();
};

#endif // WSCREEN_H

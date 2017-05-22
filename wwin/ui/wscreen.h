#ifndef WSCREEN_H
#define WSCREEN_H

#include "wwin/wobject.h"

/**
 * @brief Класс WScreen позволяет получить информцию о экране
 */
class WScreen : public WObject
{
private:
    WScreen();

public:
    static int width();
    static int height();
};

#endif // WSCREEN_H

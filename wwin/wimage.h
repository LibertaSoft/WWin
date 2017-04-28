#ifndef WIMAGE_H
#define WIMAGE_H

#include "wwin/wstring.h"

/*!
 * \brief WImage класс для работы с картинками
 */
class WImage
{
private:
    HANDLE _image = nullptr; /// < Handle картинки
    int _width  = 0; /// < Ширина картинки
    int _height = 0; /// < Высота картинки

public:
    WImage();
    WImage(WString fileName, const char *format = nullptr);
    WImage(int width, int height);

    bool load(WString fileName, const char *format = nullptr);

    bool isNull() const;

    HANDLE handle() const;

    int width() const;
    void setWidth(int width);
    int height() const;
    void setHeight(int height);
};

#endif // WIMAGE_H

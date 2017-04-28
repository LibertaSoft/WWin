#include "wimage.h"
#include "wwin/wapplication.h"

/*!
 * \brief WImage::width получить ширину картинки
 * \return
 */
int WImage::width() const
{
    return _width;
}

/*!
 * \brief WImage::setWidth установить ширину картинки
 * \param width
 */
void WImage::setWidth(int width)
{
    _width = width;
}

/*!
 * \brief WImage::height получить высоту картинки
 * \return
 */
int WImage::height() const
{
    return _height;
}

/*!
 * \brief WImage::setHeight установить высоту картинки
 * \param height
 */
void WImage::setHeight(int height)
{
    _height = height;
}

/*!
 * \brief WImage::WImage конструктор по умолчанию
 */
WImage::WImage()
{}

/*!
 * \brief WImage::WImage конструктор с инициализацией
 * \param fileName - путь к существующему файлу на диске
 * \param format - формат изображения, пока доступно только "bmp" и его можно не указывать
 */
WImage::WImage(WString fileName, const char *format)
{
    this->load(fileName, format);
}

/*!
 * \brief WImage::WImage конструктор с инициализацией размеров
 * \param width
 * \param height
 */
WImage::WImage(int width, int height)
{
    this->setHeight(width);
    this->setHeight(height);
}

/*!
 * \brief WImage::load загрузить картинку из файла
 * \param fileName - путь к существующему файлу на диске
 * \param format - формат изображения, пока доступно только "bmp" и его можно не указывать
 * \return успех загрузки
 */
bool WImage::load(WString fileName, const char *format)
{
    _image = LoadImage(wApp->getHinstance(), fileName.c_str(), IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);
    return ( ! this->isNull() );
}

/*!
 * \brief WImage::isNull Есть ли картинка
 * \return false если картинка не была загружена
 */
bool WImage::isNull() const
{
    return _image == nullptr;
}

/*!
 * \brief WImage::handle доступ к handle на картинку
 * \return
 */
HANDLE WImage::handle() const
{
    return _image;
}


#include "wlabel.h"
#include "wwin/wapplication.h"
#include <iostream>

/*!
 * \brief WLabel::WLabel Конструктор с инициализацией
 * \param parent
 */
WLabel::WLabel(WWidget *parent)
    : WWidget(parent)
{
    this->initWndClass(L"STATIC");
}

/*!
 * \brief WLabel::WLabel Конструктор с инициализацией
 * \param parent
 */
WLabel::WLabel(WString text, WWidget *parent)
    : WWidget(parent)
{
    this->setTitle(text);
    this->initWndClass(L"STATIC");
}

/*!
 * \brief WLabel::setImage установить изображение в виджет
 * \param imagepath
 */
void WLabel::setImage(WString imagepath)
{
    this->setImage( WImage(imagepath) );
}

/*!
 * \brief WLabel::setImage установить изображение в виджет
 * \param image
 */
void WLabel::setImage(WImage image)
{
    if( ! image.isNull() ){
        _image = image;
        _isImage = true;
        this->setStyle( this->style() );
        SendMessage(this->hwnd(), (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)_image.handle());
    }
}

/*!
 * \brief WLabel::style переопределение стиля виджета
 * \return
 */
int WLabel::style()
{
    int style = WS_CHILD | WS_VISIBLE;
    if( _isImage ) {
        style |= SS_BITMAP | SS_REALSIZEIMAGE;
    }
    return style;
}


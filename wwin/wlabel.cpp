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
    _isImage = true;
    this->setStyle( this->style() );
    HANDLE img = LoadImage(wApp->getHinstance(), imagepath.c_str(), IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);
    if( ! img ){
        // Catch error
        std::cout << "Error load image: " << img << std::endl;
        _isImage = false;
    }
    SendMessage(this->hwnd(), (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)img);
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


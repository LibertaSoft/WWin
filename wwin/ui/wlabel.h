#ifndef WLABEL_H
#define WLABEL_H

#include "wwin/ui/wwidget.h"
#include "wwin/wimage.h"

/*!
 * \brief WLabel класс позволяет отображать надпии и изображения
 */
class WLabel : public WWidget
{
private:
    bool _isImage = false; /// < Картинка ли в виджете
    WImage _image; /// < Картинка

public:
    WLabel(WWidget *parent);
    WLabel(WString text, WWidget *parent);

    void setImage(WString imagepath);
    void setImage(WImage image);

    // WWidget interface
protected:
    virtual int style() override;
};

#endif // WLABEL_H

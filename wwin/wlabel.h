#ifndef WLABEL_H
#define WLABEL_H

#include "wwin/wwidget.h"

/*!
 * \brief WLabel класс позволяет отображать надпии и изображения
 */
class WLabel : public WWidget
{
private:
    bool _isImage = false;

public:
    WLabel(WWidget *parent);
    WLabel(WString text, WWidget *parent);

    void setImage(WString imagepath);

    // WWidget interface
protected:
    virtual int style() override;
};

#endif // WLABEL_H

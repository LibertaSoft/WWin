#ifndef WPLAINTEXTEDIT_H
#define WPLAINTEXTEDIT_H

#include "wwin/ui/wwidget.h"
#include "wwin/wstring.h"

#include <list>
#include <functional>

/*!
 * \brief WPlainTextEdit класс для простого текстового редактора без форматирования
 */
class WPlainTextEdit : public WWidget
{
private:
    unsigned long _maxLength = 65536; /// < Максимальная длина текста
    std::list< std::function<void(WString)> > _cblChanged;

public:
    WPlainTextEdit(WWidget *parent);

    void setPlainText(WString text);

    void on_changed(std::function<void(WString)> callback);

    // WWidget interface
protected:
    virtual int  style() override;
    virtual bool changeEvent(WEvent *e) override;

    // WObject interface
public:
    virtual bool event(WEvent *e) override;

};

#endif // WPLAINTEXTEDIT_H

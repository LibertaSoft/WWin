#ifndef WPLAINTEXTEDIT_H
#define WPLAINTEXTEDIT_H

#include "wwin/wwidget.h"
#include "wwin/wstring.h"

#include <list>
#include <functional>

class WPlainTextEdit : public WWidget
{
private:
    int _maxLength = 35536;
    std::list< std::function<void(WString)> > _cblChanged;

public:
    WPlainTextEdit(WWidget *parent);

    void on_changed(std::function<void(WString)> callback);

    // WWidget interface
protected:
    virtual int  style() override;
    virtual bool changeEvent(WEvent *e) override;

    // WObject interface
public:
    virtual bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
    virtual bool event(WEvent *e) override;

};

#endif // WPLAINTEXTEDIT_H

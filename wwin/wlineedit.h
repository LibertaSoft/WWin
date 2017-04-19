#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include "wwidget.h"


class WLineEdit : public WWidget
{
private:
    int _maxLength = 255;
    int _echoMode = EchoMode::Normal;
private:
    int style();

public:
    WLineEdit(WWidget* parent);
    WLineEdit(std::string value, WWidget *parent);

    void setText(const std::string &value);
    std::string value() const;

//    std::string selectedText() const;
//    void setPlaceholder(std::string text);
//    void setEchoMode(int);
//    void clear();

//    void copy() const;
//    void cut();
//    void paste();
//    void redo();
//    void undo();
//    void selectAll();

//    void on_chenge(WKeyEvent& event);
//    void on_editingFinished(WKeyEvent& event);
//    void on_returnPressed(WKeyEvent& event);
//    void on_textChanged(std::string text);
//    void on_selectionChanged();
//    void on_cursorPositionChanged(int old, int new);

    bool processEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    enum EchoMode {
        Normal,
        Password
    };
};

#endif // WLINEEDIT_H

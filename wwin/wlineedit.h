#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include <functional>
#include <vector>

#include "wwidget.h"
#include "wstring.h"

#define subscribers

class WLineEdit : public WWidget
{
public:
    enum class EchoMode : int {
        Normal,
        Password
    };
// callbacks
private:
    std::vector< std::function<void(WString)> > _cblChange;

private:
    int _maxLength = 255;
    WLineEdit::EchoMode _echoMode = EchoMode::Normal;
private:
    int style();

protected:
    bool changeEvent(WEvent *e);
    bool event(WEvent *e);

public:
    WLineEdit(WWidget* parent);
    WLineEdit(WString value, WWidget *parent);

    void setText(const WString &value);
    WString value() const;
    void clear();

    int maxLength() const;
    void setMaxLength(int maxLength);

//    std::string selectedText() const;
//    void setPlaceholder(std::string text);
    void setEchoMode(WLineEdit::EchoMode mode);
    WLineEdit::EchoMode echoMode() const;

//    void copy() const;
//    void cut();
//    void paste();
//    void redo();
//    void undo();
//    void selectAll();

public subscribers:
    int on_change(std::function<void(WString)> callback);
//    void on_editingFinished(WKeyEvent& event);
//    void on_returnPressed(WKeyEvent& event);
//    void on_textChanged(std::string text);
//    void on_selectionChanged();
//    void on_cursorPositionChanged(int old, int _new);

public:
    bool nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // WLINEEDIT_H

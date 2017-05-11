#ifndef WLINEEDIT_H
#define WLINEEDIT_H

#include <functional>
#include <vector>

#include "wwidget.h"
#include "../wstring.h"

/// ну так эксперимента ради...
#define subscribers

/**
 * @brief WLineEdit Виджет строки ввода текста или пароля
 */
class WLineEdit : public WWidget
{
public:
    enum class EchoMode : int {
        Normal,
        Password
    };
// callbacks
private:
    std::vector< std::function<void(WString)> > _cblChange; /// < Список функций обратного вызова на событие изменения данных

private:
    int _maxLength = 255; /// < Максимальная длина строки в поле ввода
    WLineEdit::EchoMode _echoMode = EchoMode::Normal; /// < Метод отображения тект/пароль
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
//    void cut(); 324
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

};

#endif // WLINEEDIT_H

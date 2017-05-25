#ifndef WSTACKEDWIDGET_H
#define WSTACKEDWIDGET_H

#include "wwin/ui/wwidget.h"
#include <vector>

class WStackedWidget : public WWidget
{
private:
    std::vector<WWidget*> _stack;
    int _currentIndex = 0;

public:
    WStackedWidget(WWidget* parent = nullptr);

    int addWidget(WWidget *widget);
    int count() const;

    int currentIndex() const;
    void setCurrentIndex(int index);

    WWidget* currentWidget() const;
    int indexOf(WWidget* widget) const;

    void show();

    // WWidget interface
protected:
    virtual int style() override;
};

#endif // WSTACKEDWIDGET_H

#include "wstackedwidget.h"
#include <iostream>

WStackedWidget::WStackedWidget(WWidget *parent)
    : WWidget(parent)
{

}

int WStackedWidget::addWidget(WWidget *widget)
{
    _stack.push_back(widget);
    widget->hide();
    _currentIndex = _stack.size() - 1;
    return _stack.size() - 1;
}

int WStackedWidget::count() const
{
    return _stack.size();
}

int WStackedWidget::currentIndex() const
{
    return _currentIndex;
}

void WStackedWidget::setCurrentIndex(int index)
{
    _currentIndex = index;
    for( auto page : _stack ){
        page->hide();
    }
    _stack.at(_currentIndex)->show();
}

WWidget *WStackedWidget::currentWidget() const
{
    return _stack.at( this->currentIndex() );
}

int WStackedWidget::indexOf(WWidget *widget) const
{
    int i = 0;
    for(auto it = _stack.begin(); it != _stack.end(); it++){
        if( *it == widget ){
            return i;
        }
        i++;
    }
    return i;
}

void WStackedWidget::show()
{
    for( auto page : _stack ){
        page->hide();
    }
    _stack.at(_currentIndex)->show();
    WWidget::show();
}

int WStackedWidget::style()
{
    return WS_VISIBLE | WS_CHILD | WS_BORDER;
}


#include "testwindow.h"

TestWindow::TestWindow(WWidget *parent)
    : WWidget(parent)
{

}

void TestWindow::initUi()
{
    auto wgt = this;
    int width  = 480;
    int height = 320;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    wgt->setTitle(L"WWinApi Lib Заголовок");
    wgt->setGeometry(x,y,width,height);

    WLineEdit *edit = new WLineEdit(L"hello", wgt);
    edit->setGeometry(10,80,250,20);
    edit->show();
    edit->setEchoMode(WLineEdit::EchoMode::Password);
    edit->on_change([](WString){/* ... */});

    WListBox *listbox = new WListBox({
        L"Item 1",
        L"Item 2",
        L"Item 3",
        L"Item 4"
    }, wgt);
    listbox->setGeometry(10, 110, 250, 100);
    listbox->show();

    WListView *listview = new WListView({
        L"One",
        L"Two",
        L"Three",
        L"Four"
    }, wgt);
    listview->setGeometry(270,10,186,100);
    listview->show();
    WStringListModel *listview_model = new WStringListModel({
        L"Une",
        L"Due",
        L"Tree",
        L"Quatro"
    }, wgt);
    listview->setModel(listview_model);
    listview->on_select([=](WModelIndex index){
        auto item = listview_model->data(index);
        WMessageBox::information(nullptr, L"Title", item);
    });

    WListView *listview2 = new WListView(wgt);
    listview2->setGeometry(270,120,186,100);
    listview2->show();
    listview2->setModel(listview_model);
    listview2->on_doubleClick([=](WModelIndex index){
        auto item = listview_model->data(index);
        WMessageBox::warning(nullptr, L"Title", item);
    });

    WPushButton *btn2 = new WPushButton(L"Мой батон", wgt);
    btn2->setGeometry(140,10,120,60);
    btn2->show();
    btn2->setFocus();
    btn2->on_click([=](WMouseEvent*e){
        listview_model->setData({-1,0}, edit->value());

        listbox->addListItem(edit->value());
        if( e->modifiers() & WMouseEvent::KeyModifiers::ControlModifier ){
            WMessageBox::information(nullptr, L"Title", L"Control is hold");
        }
    });

    WPushButton *btn = new WPushButton(L"My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();
    btn->on_click([&](WMouseEvent*){
        WMessageBox::information(wgt, L"Title", L"Button 1 clicked");
    });
//    delete btn;
}



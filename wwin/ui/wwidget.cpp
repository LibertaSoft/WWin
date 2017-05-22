#include "wwidget.h"
#include "wwin/wapplication.h"
#include "wwin/helpers/winapiwindowbuilder.h"
#include "wwin/ui/wscreen.h"

#include <iostream>

int WWidget::_componentCount = 0; /// < Количество компонентов в системе

/**
 * @brief WWidget::hwnd получить хендл окна виджета
 * @return
 */
HWND WWidget::hwnd() const
{
    return _hwnd;
}

/**
 * @brief WWidget::hwnd установить хендл окнна виджета
 * @param hwnd
 */
void WWidget::hwnd(HWND hwnd)
{
    _hwnd = hwnd;
    WPaintDevice::initPaintDevice(_hwnd);
}

/**
 * @brief WWidget::parentHwnd получить хендл родительского окна
 * @return
 */
HWND WWidget::parentHwnd() const
{
    HWND p_hwnd = HWND_DESKTOP;
    WWidget *parent = parentWidget();
    if( parent && parent->hwnd() ){
        p_hwnd = parent->hwnd();
    }
    return p_hwnd;
}

/**
 * @brief WWidget::parentWidget получить родительский виджет
 * @return родительский виджет или nullptr
 */
WWidget* WWidget::parentWidget() const
{
    WObject* parent = WObject::parent();
    if( parent && parent->type() == WObjectType::Widget ){
        return static_cast<WWidget*>( parent );
    }
    return nullptr;
}

int WWidget::nextCid()
{
    return _componentCount++;
}

/**
 * @brief WWidget::cid Получить ID компонента
 * @return id компонента
 */
WORD WWidget::cid() const
{
    return _cid;
}

/**
 * @brief WWidget::style Стиль виджета.
 * Стили для главного окна приложения
 * @return
 */
int WWidget::style()
{
    return WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
}

/**
 * @brief WWidget::setStyle установить стиль виджета
 * @warning Не работает
 * \todo реализовать метод
 * @param style2
 */
void WWidget::setStyle(int style)
{
    SetWindowLong(this->hwnd(),GWL_STYLE,style);
    SetWindowPos(this->hwnd(),0,0,0,0,0,SWP_NOZORDER|SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE|SWP_DRAWFRAME);
}
/**
 * @brief WWidget::initWndClass инициализировать окно класса.
 * @warning Обязательно должен быть вызван в конструкторе при унаследовании данного класса.
 * @param className - класс окна
 * @return успех инициализации окна
 */
bool WWidget::initWndClass(WString className)
{
    _className = className;
    HWND x = WinApiWindowBuilder()
         .className( _className )
         .title( this->title() )
         .style( this->style() )
         .geometry( _x, _y, _width, _height )
         .parent( this->parentHwnd() )
         .hinstance( wApp->getHinstance() )
         .param( reinterpret_cast<LPVOID>( _windowParams ) )
         .menu( reinterpret_cast<HMENU>( this->cid() ) )
         .build();
    this->hwnd(x);

    if( x != nullptr ){
        wApp->addComponent(this);
        return true;
    }
    return false;
}

/**
 * @brief WWidget::mouseReleaseEvent событие отпускания кнопки мыши
 * @param e - экземпляр WMouseEvent
 * @return WEvent::isAccepted()
 */
bool WWidget::mouseReleaseEvent(WMouseEvent *e)
{
    return e->isAccepted();
}

/**
 * @brief WWidget::mouseReleaseEvent событие двойного клика
 * @param e - экземпляр WMouseEvent
 * @return WEvent::isAccepted()
 */
bool WWidget::mouseDoubleClickEvent(WMouseEvent *e)
{
    return e->isAccepted();
}

/**
 * @brief WWidget::mouseReleaseEvent событие изменения виджета
 * @param e - экземпляр WEvent
 * @return WEvent::isAccepted()
 */
bool WWidget::changeEvent(WEvent *e)
{
    return e->isAccepted();
}

bool WWidget::resizeEvent(WResizeEvent *e)
{
    return e->isAccepted();
}

bool WWidget::moveEvent(WMoveEvent *e)
{
  return e->isAccepted();
}

bool WWidget::paintEvent(WPaintEvent *e)
{
  return e->isAccepted();
}

/**
 * @brief WWidget::event обработка потока событий
 * @param e - экземпляр WEvent
 * @return WEvent::isAccepted()
 */
bool WWidget::event(WEvent *e)
{
    if( e->type() == WEvent::Type::MouseReleaseEvent ){
        return this->mouseReleaseEvent( static_cast<WMouseEvent*>(e) );
    }
    if( e->type() == WEvent::Type::ResizeEvent ){
        return this->resizeEvent( static_cast<WResizeEvent*>(e) );
    }
    if( e->type() == WEvent::Type::MoveEvent ){
        return this->moveEvent( static_cast<WMoveEvent*>(e) );
    }
    if( e->type() == WEvent::Type::PaintEvent ){
        return this->paintEvent( static_cast<WPaintEvent*>(e) );
    }
    return WObject::event(e);
}

/**
 * @brief WWidget::WWidget Конструктор с инииализацией базового класса и компонента окна
 * @param parent - родительское окно
 * @param params - параметры окна
 */
WWidget::WWidget(WWidget *parent, int params)
    : WObject(parent), _windowParams(params)
{
    _cid = _componentCount++;
    this->setType(WObjectType::Widget);

    if( parent == nullptr ) {
        this->initWndClass(L"WWIDGET");
    }
}

/**
 * @brief WWidget::~WWidget Деструктор с удалением компонента из системы
 */
WWidget::~WWidget()
{
    wApp->removeComponent(this);
    DestroyWindow(this->hwnd());
}

/**
 * @brief WWidget::show отобразить виджет
 * @warning Если WWidget::initWndClass ещё небыло вызвано и _hwnd не установлен, вызовет самостоятельно
 */
void WWidget::show()
{
    if( ! this->hwnd() ) {
       this->initWndClass(L"WWIDGET");
    }
    ShowWindow( this->hwnd(), _windowParams );
    UpdateWindow( this->hwnd() );
}

/**
 * @brief WWidget::setGeometry установить размеры и положение виджета
 * @param x
 * @param y
 * @param width
 * @param height
 */
void WWidget::setGeometry(int x, int y, int width, int height)
{
    _x = x;
    _y = y;

    // Можно проще
    if( width < _minWidth ) {
        width = _minWidth;
    } else if( width > _maxWidth ) {
        width = _maxWidth;
    }
    if( height < _minHeight ) {
        height = _minHeight;
    } else if( height > _maxHeight ) {
        height = _maxHeight;
    }

    _width = width;
    _height = height;

    SetWindowPos(this->hwnd(), nullptr, _x, _y, _width, _height, 0);

}

/**
 * @brief WWidget::title получить заголовок виджета
 * @return WString - заголовок виджета
 */
WString WWidget::title() const
{
    return _title;
}

/**
 * @brief WWidget::setTitle Установить заголовок виджета
 * @param title - заголовок виджета
 */
void WWidget::setTitle(const WString &title)
{
    _title = title;
    SetWindowText(this->hwnd(), _title.c_str());
}

void WWidget::setEnable(const bool enable)
{
    EnableWindow( this->hwnd(), enable );
}

void WWidget::disable()
{
    this->setEnable(false);
}

void WWidget::enable()
{
    this->setEnable(true);
}

/**
 * @brief WWidget::nativeEvent Обработка нативных системных событий и их преобразование
 * в систему событий WWin
 * \warning порядок событий важен
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return
 */
bool WWidget::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if( message == WM_DESTROY ){
        PostQuitMessage( EXIT_SUCCESS );
        return true;
    }
    if(WM_SIZING == message || WM_SIZE == message) {
        /// \warning Странно себя ведёт, срабатывает для разных виджетов
        RECT rect;
        if( ! GetWindowRect(hWnd, &rect) ){
            /// \todo process error
            return false;
        }

        WSize oldSize(_width, _height);

        /// \todo export to WWidget::event(WResizeEvent*)
        _x = rect.left;
        _y = rect.top;
        _width = rect.right-rect.left;
        _height = rect.bottom - rect.top;

        WSize newSize(rect.right-rect.left, rect.bottom - rect.top);

        return this->event( new WResizeEvent(newSize, oldSize) );
    }
    if(WM_MOVE == message || WM_MOVING == message){
        WPoint oldPos( _x, _y);

        RECT rect;
        if( ! GetWindowRect(hWnd, &rect) ){
            /// \todo process error
            return false;
        }

        WPoint newPos(rect.left, rect.top);

        return this->event( new WMoveEvent(newPos, oldPos) );
    }
    if(WM_PAINT == message) {
        RECT wr;
        GetClientRect(this->hwnd(), &wr);
        WRect r(0, 0, wr.right, wr.bottom);
        return this->event( new WPaintEvent(r) );
    }
    if(WM_COMMAND == message){
        // Lists
        if(HIWORD(wParam) == LBN_SELCHANGE) {
            return this->event(new WEvent( WEvent::Type::ChangeEvent ));
        }
        if(HIWORD(wParam) == LBN_DBLCLK) {
            WMouseEvent* e = new WMouseEvent;
            e->setType(WEvent::Type::MouseDoubleClickEvent);
            return this->event(e);
        }

        // Buttons
        if( HIWORD( wParam ) == BN_CLICKED ) {
            return this->event(new WMouseEvent);
        }
        if( HIWORD( wParam ) == BN_PUSHED ) {
            /// \todo fixme Not fire
            return this->event(new WMouseEvent);
        }
        if( HIWORD( wParam ) == BN_UNPUSHED ) {
            /// \todo fixme Not fire
            return this->event(new WMouseEvent);
        }

        // Edits
        if( EN_CHANGE == HIWORD(wParam) ){
            return this->event( new WEvent(WEvent::Type::WindowTitleChange) );
        }
    }

    return WObject::nativeEvent(hWnd, message, wParam, lParam);
}

/**
 * @brief WWidget::setFocus Установить фокус на виджет
 */
void WWidget::setFocus()
{
    SetFocus( this->hwnd() );
}


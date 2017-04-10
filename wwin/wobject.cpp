#include "wobject.h"
#include "wwin/wapplication.h"

void WObject::setHwnd(HWND hwnd)
{
    _hwnd = hwnd;
}

WObject::WObject(WObject* parent = nullptr)
    : _parent(parent)
{
    wApp->addComponent(this);
}

WObject::~WObject()
{
    wApp->removeComponent(this);
}

HWND WObject::hwnd() const
{
    return _hwnd;
}

void WObject::setType(WObjectType::WObjectType type)
{
    _type = type;
}

WObjectType::WObjectType WObject::type() const
{
    return _type;
}

WObject *WObject::parent() const
{
    return _parent;
}

LPWSTR WObject::tow(const std::string &s)
{
    LPWSTR ws = new wchar_t[s.size()+1];
    copy( s.begin(), s.end(), ws );
    ws[s.size()] = 0;
    return ws;
}


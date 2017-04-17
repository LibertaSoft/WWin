#include "wobject.h"
#include "wwin/wapplication.h"

#include <iostream>

WObject::WObject(WObject* parent = nullptr)
    : _parent(parent)
{

}

WObject::~WObject()
{

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

bool WObject::event(WEvent *e)
{
    std::cout << "WObject::event" << std::endl;

    return e->isAccepted();
}

LPWSTR WObject::tow(const std::string &s)
{
    LPWSTR ws = new wchar_t[s.size()+1];
    copy( s.begin(), s.end(), ws );
    ws[s.size()] = 0;
    return ws;
}


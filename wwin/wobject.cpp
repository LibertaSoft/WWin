#include "wobject.h"

WObject::WObject(WObject* parent = nullptr)
    : _parent(parent)
{}

WObject::~WObject()
{}

LPWSTR WObject::tow(const std::string &s)
{
    LPWSTR ws = new wchar_t[s.size()+1];
    copy( s.begin(), s.end(), ws );
    ws[s.size()] = 0;
    return ws;
}


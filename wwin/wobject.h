#ifndef WOBJECT_H
#define WOBJECT_H

#include <windows.h>
#include <string>
#include <list>

class WObject
{
private:
    WObject *_parent;
    std::string objectName;

    std::list<WObject> _childrens;

public:
    WObject(WObject *parent);
    virtual ~WObject();

    void setObjectName(std::string &name);

    void setParent(WObject* parent);
    WObject parent() const;
    std::list<WObject*> children() const;

//    virtual bool event(WEvent *e);
//    virtual bool eventFilter(WObject *watched, WEvent *event);
    void removeEventFilter(WObject* obj);

    // опции и рекурсивно
    WObject* findChild(const std::string &name) const;
    std::list<WObject*> findChildren(const std::string &name) const;

//    std::string tr(const char *sourceText, constChar *disambiguation = nullptr, int n = -1);
    static LPWSTR tow( const std::string& s );
};

#endif // WOBJECT_H

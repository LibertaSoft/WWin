#ifndef WDEBUG_H
#define WDEBUG_H

#define W_DEBUG

#ifdef W_DEBUG
#define wDebug(obj) WDebug(#obj).print();

#include <string>
#include <map>
struct WDebugInfo {
    std::wstring className;
    std::wstring fileName;
    std::map<std::wstring, std::wstring> props;
};

// Classes
class WWidget;

class WDebug
{
public:
    WDebug();
    WDebug(WWidget wgt);
    void print();
};

#else
    #define wDebug(obj)
#endif

#endif // WDEBUG_H

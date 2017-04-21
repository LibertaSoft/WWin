#ifndef WSTRING_H
#define WSTRING_H

#include <string>
#include <windows.h>

/**
 * @brief WString Декларация класса строк.
 * На данный момент используется std::wstring, но вероятно потребуется расширять класс
 * и добавлять методы для работы со строками.
 */
typedef std::wstring WString;
/*
namespace WStringN {

    LPWSTR tow(const std::string &s)
    {
        LPWSTR ws = new wchar_t[s.size()+1];
        copy( s.begin(), s.end(), ws );
        ws[s.size()] = 0;
        return ws;
    }

    std::string tos(const TCHAR *s)
    {
      std::wstring arr_w( s );
      std::string arr_s( arr_w.begin(), arr_w.end() );
      return arr_s;
    }

}
*/
/*
class WString
{
public:
    WString();
};
//*/

#endif // WSTRING_H

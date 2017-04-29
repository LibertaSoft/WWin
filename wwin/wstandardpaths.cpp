#include "wstandardpaths.h"
#include "wwin/wapplication.h"
#include <windows.h>
#include <fstream>

/*!
 * \brief WStandardPaths::locate - искать первый найденный файл в списке системных директорий указанного типа
 * \param type - тип системной локации где производить поиск
 * \param fileName - имя искомого файла или директории, можете указать поддиректорию
 * \param options - что искать файл или директорию
 * \return первый найденный путь к файлу
 */
WString WStandardPaths::locate(WStandardPaths::StandardLocation type, WString fileName, WStandardPaths::LocateOption options)
{
    for( auto path : standardLocations(type) ){
        WString name( path + L"\\" + fileName );
        DWORD dwAttrib = GetFileAttributes( name.c_str() );
        if( dwAttrib != INVALID_FILE_ATTRIBUTES ) {
            bool isDir = (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);

            if( options == WStandardPaths::LocateOption::LocateDirectory && isDir ){
                return name;
            } else if( options == WStandardPaths::LocateOption::LocateFile && !isDir ) {
                return name;
            }
        }
    }
    return L"";
}

/*!
 * \brief WStandardPaths::locateAll - искать запрашиваемый файл в во всехсистемных директориях указанного типа
 * \param type - тип системной локации где производить поиск
 * \param fileName - имя искомого файла или директории, можете указать поддиректорию
 * \param options - что искать файл или директорию
 * \return список всех найденныйх файлов во всех системных директориях указанного типа
 */
WStringList WStandardPaths::locateAll(WStandardPaths::StandardLocation type, WString fileName, WStandardPaths::LocateOption options)
{
    WStringList list;
    for( auto path : standardLocations(type) ){
        WString name( path + L"\\" + fileName );
        DWORD dwAttrib = GetFileAttributes( name.c_str() );
        if( dwAttrib != INVALID_FILE_ATTRIBUTES ) {
            bool isDir = (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);

            if( options == WStandardPaths::LocateOption::LocateDirectory && isDir ){
                list.push_back( name );
            } else if( options == WStandardPaths::LocateOption::LocateFile && !isDir ) {
                list.push_back( name );
            }
        }
    }
    return list;
}

/*!
 * \brief WStandardPaths::standardLocations получить список всех системных директорий указанного типа
 * \param type - тип системных локаций(директорий)
 * \return
 */
WStringList WStandardPaths::standardLocations(WStandardPaths::StandardLocation type)
{
    switch( type ){
    case StandardLocation::AppConfigLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName()};
    case StandardLocation::AppDataLocation:
        return {
            L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Roaming\\" + wApp->applicationName(),
            L"C:\\ProgramData\\" + wApp->applicationName(),
            // <APPDIR>
            // <APPDIR>/data
        };
    case StandardLocation::ApplicationsLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs"};
    case StandardLocation::CacheLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\cache"};
    case StandardLocation::ConfigLocation:
        return {
            L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName(),
            L"C:\\ProgramData\\" + wApp->applicationName(),
        };
    case StandardLocation::DataLocation:
        return {
            L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName(),
            L"C:\\ProgramData\\" + wApp->applicationName(),
            // <APPDIR>
            // <APPDIR>/data
        };
    case StandardLocation::DesktopLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Desktop"};
    case StandardLocation::DocumentsLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Documents"};
    case StandardLocation::DownloadLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Downloads"};
    case StandardLocation::FontsLocation:
        return {L"C:\\Windows\\Fonts"}; /// \warning not writable
    case StandardLocation::HomeLocation:
        return {L"C:\\Users\\" + wApp->userName()};
    case StandardLocation::MoviewLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Videos"};
    case StandardLocation::MusicLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Music"};
    case StandardLocation::PicturesLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\Pictures"};
    case StandardLocation::TempLocation:
        return {L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\Temp"};
    }

    return {};
}

/*!
 * \brief WStandardPaths::writableLocation получить путь к доступной для записи системной директории указанного типа
 * \param type - тип директории
 * \return путь к доступной для записи директории указанного типа
 */
WString WStandardPaths::writableLocation(WStandardPaths::StandardLocation type)
{
    switch( type ){
    case StandardLocation::AppConfigLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName();
    case StandardLocation::AppDataLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData";
    case StandardLocation::ApplicationsLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs";
    case StandardLocation::CacheLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\cache";
    case StandardLocation::ConfigLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName();
    case StandardLocation::DataLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\" + wApp->applicationName();
    case StandardLocation::DesktopLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Desktop";
    case StandardLocation::DocumentsLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Documents";
    case StandardLocation::DownloadLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Downloads";
    case StandardLocation::FontsLocation:
        return L"C:\\Windows\\Fonts"; /// \warning not writable
    case StandardLocation::HomeLocation:
        return L"C:\\Users\\" + wApp->userName();
    case StandardLocation::MoviewLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Videos";
    case StandardLocation::MusicLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Music";
    case StandardLocation::PicturesLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\Pictures";
    case StandardLocation::TempLocation:
        return L"C:\\Users\\" + wApp->userName() + L"\\AppData\\Local\\Temp";
    }

    return L"";
}


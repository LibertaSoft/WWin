#ifndef WSTANDARDPATHS_H
#define WSTANDARDPATHS_H

#include "wwin/wstring.h"
#include "wwin/wstringlist.h"

/*!
 * \brief WStandardPaths класс предоставляет статические методы для доступа к системным путям.
 * Класс позволяет получить пути к доступным для записи местам в файловой системе,
 * где принято хранить те или иные ресурсы программы, типа данных, базы данных, локализаций и т.п.
 */
class WStandardPaths
{
private:
    WStandardPaths();

public:
    enum class LocateOption : int {
        LocateFile,
        LocateDirectory
    };
    enum class StandardLocation : int {
        DesktopLocation,
        DocumentsLocation,
        FontsLocation,
        ApplicationsLocation,
        MusicLocation,
        MoviewLocation,
        PicturesLocation,
        TempLocation,
        HomeLocation,
        DataLocation,
        CacheLocation,
        ConfigLocation,
        DownloadLocation,
        AppDataLocation,
        AppConfigLocation
    };

    // static WString displayName(StandardLocation type);
    static WString locate(StandardLocation type, WString fileName, LocateOption options = LocateOption::LocateFile);
    static WStringList locateAll(StandardLocation type, WString fileName, LocateOption options = LocateOption::LocateFile);
    static WStringList standardLocations(StandardLocation type);
    static WString writableLocation(StandardLocation type);

};

#endif // WSTANDARDPATHS_H

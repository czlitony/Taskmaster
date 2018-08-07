#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QString>


class FileUtils
{
public:
    static const QString getAppDir();

    static const QString getMusicSettingFile();

    static const QString getCookieFile();

    static const QString getGeneralSettingFile();
};

#endif // FILEUTILS_H

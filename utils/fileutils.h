#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QString>


class FileUtils
{
public:
    static const QString appDir();

    static const QString settingFile();

    static const QString generalSettingFile();

    static const QString taskResponseFile();
};

#endif // FILEUTILS_H

#include "fileutils.h"
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

const QString FileUtils::appDir()
{
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator();
}

const QString FileUtils::musicSettingFile()
{
    return appDir() + "music_setting.xml";
}

const QString FileUtils::cookieFile()
{
    return appDir() + "cookie.ini";
}

const QString FileUtils::generalSettingFile()
{
    return appDir() + "general_setting.ini";
}

const QString FileUtils::taskResponseFile()
{
    return appDir() + "task_response";
}

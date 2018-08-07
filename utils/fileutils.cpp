#include "fileutils.h"
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

const QString FileUtils::getAppDir()
{
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator();
}

const QString FileUtils::getMusicSettingFile()
{
    return getAppDir() + "music_setting.xml";
}

const QString FileUtils::getCookieFile()
{
    return getAppDir() + "cookie.ini";
}

const QString FileUtils::getGeneralSettingFile()
{
    return getAppDir() + "general_setting.ini";
}

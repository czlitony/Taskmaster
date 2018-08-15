#include "fileutils.h"
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

const QString FileUtils::appDir()
{
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator();
}

const QString FileUtils::settingFile()
{
    return appDir() + "setting.xml";
}

const QString FileUtils::generalSettingFile()
{
    return appDir() + "general_setting.ini";
}

const QString FileUtils::taskResponseFile()
{
    return appDir() + "task_response";
}

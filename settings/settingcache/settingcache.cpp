#include "settingcache.h"
#include "utils/fileutils.h"
#include "../musicsetting/taskmusic.h"
#include "../musicsetting/musicsettingitem.h"

namespace {
    const QString MUSIC_GROUP = "Music";
    const QString COOKIE_GROUP = "Cookie";
    const QString INTERVAL_GROUP = "Interval";

    const QString MUSIC_ON = "MusicOn";
    const QString QUICK_TASK_DEFAULT = "QuickTaskDefault";
    const QString QUICK_TASK_MUSIC = "QuickTaskMusic";
    const QString FILE_TASK_DEFAULT = "FileTaskDefault";
    const QString FILE_TASK_MUSIC = "FileTaskMusic";

    const QString COOKIE = "Cookie";

    const QString INTERVAL = "Interval";
}

SettingCache* SettingCache::m_pInstance = nullptr;

SettingCache *SettingCache::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new SettingCache;
        atexit(releaseIntance);
    }

    return m_pInstance;
}

void SettingCache::releaseIntance()
{
    if (m_pInstance)
    {
        m_pInstance->sync();

        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

SettingCache::SettingCache(): m_setting(FileUtils::settingFile(), QSettings::IniFormat)
{

}

void SettingCache::updateMusicSetting(const MusicSettingItem &settingItem)
{
    setValue(MUSIC_GROUP, MUSIC_ON, settingItem.isMusicOn());

    setValue(MUSIC_GROUP, QUICK_TASK_DEFAULT, settingItem.getQuickTaskMusic().isDefaultMusic());
    setValue(MUSIC_GROUP, QUICK_TASK_MUSIC, settingItem.getQuickTaskMusic().getFile());

    setValue(MUSIC_GROUP, FILE_TASK_DEFAULT, settingItem.getFileTaskMusic().isDefaultMusic());
    setValue(MUSIC_GROUP, FILE_TASK_MUSIC, settingItem.getFileTaskMusic().getFile());
}

void SettingCache::getMusicSetting(MusicSettingItem &settingItem) const
{
    settingItem.switchMusic(getValue(MUSIC_GROUP, MUSIC_ON).toBool());

    TaskMusic quickTaskMusic;
    quickTaskMusic.setAsDefault(getValue(MUSIC_GROUP, QUICK_TASK_DEFAULT).toBool());
    quickTaskMusic.setFile(getValue(MUSIC_GROUP, QUICK_TASK_MUSIC).toString());
    settingItem.setQuickTaskMusic(quickTaskMusic);

    TaskMusic fileTaskMusic;
    fileTaskMusic.setAsDefault(getValue(MUSIC_GROUP, FILE_TASK_DEFAULT).toBool());
    fileTaskMusic.setFile(getValue(MUSIC_GROUP, FILE_TASK_MUSIC).toString());
    settingItem.setFileTaskMusic(fileTaskMusic);
}

void SettingCache::updateCookie(const QString &cookie)
{
    setValue(COOKIE_GROUP, COOKIE, cookie);
}

const QString SettingCache::getCookie() const
{
    return getValue(COOKIE_GROUP, COOKIE).toString();
}

void SettingCache::updateRetrievalInterval(const int interval)
{
    setValue(INTERVAL_GROUP, INTERVAL, interval);
}

int SettingCache::getRetrievalInterval() const
{
    return getValue(INTERVAL_GROUP, INTERVAL).toInt();
}

void SettingCache::setValue(const QString &group, const QString &key, const QVariant &value)
{
    m_setting.setValue(group + "/" + key, value);
}

QVariant SettingCache::getValue(const QString &group, const QString &key, const QVariant &defaultValue) const
{
    return m_setting.value(group + "/" + key, defaultValue);
}

void SettingCache::sync()
{
    m_setting.sync();
}

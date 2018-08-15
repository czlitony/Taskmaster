#include "musicsetting.h"
#include"musicsettingitem.h"
#include "../settingcache/settingcache.h"

MusicSetting* MusicSetting::m_pInstance = nullptr;
MusicSetting* MusicSetting::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new MusicSetting();
        atexit(releaseIntance);
    }
    return m_pInstance;
}

void MusicSetting::releaseIntance()
{
    if (m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

MusicSettingItem MusicSetting::getMusicSettings()
{
    if (m_musicSettingItem)
    {
        return *m_musicSettingItem;
    }

    return MusicSettingItem();
}

MusicSetting::MusicSetting():
    m_musicSettingItem(new MusicSettingItem())
{
    readCache();
}

void MusicSetting::switchMusic(bool on)
{
    m_musicSettingItem->switchMusic(on);
    updateCache();
}

void MusicSetting::setDefaultQuickTaskMusic()
{
    QString selfQuickTaskMusicFile = m_musicSettingItem->getQuickTaskMusic().getFile();
    m_musicSettingItem->setQuickTaskMusic(TaskMusic(true, selfQuickTaskMusicFile));
    updateCache();
}

void MusicSetting::setSelfQuickTaskMusic(const QString &music)
{
    m_musicSettingItem->setQuickTaskMusic(TaskMusic(false, music));
    updateCache();
}

void MusicSetting::setDefaultFileTaskMusic()
{
    QString selfFileTaskMusicFile = m_musicSettingItem->getFileTaskMusic().getFile();
    m_musicSettingItem->setFileTaskMusic(TaskMusic(true, selfFileTaskMusicFile));
    updateCache();
}

void MusicSetting::setSelfFileTaskMusic(const QString &music)
{
    m_musicSettingItem->setFileTaskMusic(TaskMusic(false, music));
    updateCache();
}

void MusicSetting::updateCache()
{
    SettingCache::getInstance()->updateMusicSetting(*m_musicSettingItem);
}

void MusicSetting::readCache()
{
     SettingCache::getInstance()->getMusicSetting(*m_musicSettingItem);
}

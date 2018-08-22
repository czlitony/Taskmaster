#include "musicsetting.h"
#include"musicsettingitem.h"
#include "../settingcache/settingcache.h"

static const QString DEFAULT_QUICK_TASK_MUSIC = "qrc:/defaultmusic/Sunrise.wav";
static const QString DEFAULT_FILE_TASK_MUSIC = "qrc:/defaultmusic/Despacito.mp3";

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

bool MusicSetting::isMusicOn() const
{
    return m_musicSettingItem->isMusicOn();
}

void MusicSetting::setDefaultQuickTaskMusicOn()
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

bool MusicSetting::isDefaultQuickTaskMusicOn() const
{
    return m_musicSettingItem->getQuickTaskMusic().isDefaultMusicOn();
}

const QString MusicSetting::getDefaultQuickTaskMusic() const
{
    return DEFAULT_QUICK_TASK_MUSIC;
}

const QString MusicSetting::getSelfQuickTaskMusic() const
{
    return m_musicSettingItem->getQuickTaskMusic().getFile();
}

void MusicSetting::setDefaultFileTaskMusicOn()
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

bool MusicSetting::isDefaultFileTaskMusicOn() const
{
    return m_musicSettingItem->getFileTaskMusic().isDefaultMusicOn();
}

const QString MusicSetting::getDefaultFileTaskMusic() const
{
    return DEFAULT_FILE_TASK_MUSIC;
}

const QString MusicSetting::getSelfFileTaskMusic() const
{
    return m_musicSettingItem->getFileTaskMusic().getFile();
}

void MusicSetting::updateCache()
{
    SettingCache::getInstance()->updateMusicSetting(*m_musicSettingItem);
}

void MusicSetting::readCache()
{
     SettingCache::getInstance()->getMusicSetting(*m_musicSettingItem);
}

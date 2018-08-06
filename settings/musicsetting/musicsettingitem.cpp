#include "musicsettingitem.h"

MusicSettingItem::MusicSettingItem():
    m_musicOn(true)
{

}

MusicSettingItem::MusicSettingItem(const bool musicOn, const TaskMusic &quickTaskMusic, const TaskMusic &fileTaskMusic):
    m_musicOn(musicOn),
    m_quickTaskMusic(quickTaskMusic),
    m_fileTaskMusic(fileTaskMusic)
{

}

void MusicSettingItem::switchMusic(bool musicOn)
{
    this->m_musicOn = musicOn;
}

bool MusicSettingItem::isMusicOn() const
{
    return m_musicOn;
}

void MusicSettingItem::setQuickTaskMusic(const TaskMusic &quickTaskMusic)
{
    this->m_quickTaskMusic = quickTaskMusic;
}

const TaskMusic MusicSettingItem::getQuickTaskMusic() const
{
    return m_quickTaskMusic;
}

void MusicSettingItem::setFileTaskMusic(const TaskMusic &fileTaskMusic)
{
    this->m_fileTaskMusic = fileTaskMusic;
}

const TaskMusic MusicSettingItem::getFileTaskMusic() const
{
    return m_fileTaskMusic;
}

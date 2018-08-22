#include "musicplayer.h"
#include "settings/musicsetting/musicsetting.h"
#include "settings/musicsetting/musicsettingitem.h"
#include <QString>

MusicPlayer::MusicPlayer()
{
    m_playlist = new QMediaPlaylist;
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    m_mediaPlayer = new QMediaPlayer;
    m_mediaPlayer->setPlaylist(m_playlist);
}

MusicPlayer::~MusicPlayer()
{
    delete m_mediaPlayer;
    delete m_playlist;
}

void MusicPlayer::playQuickTaskMusic()
{
    if (!MusicSetting::getInstance()->isMusicOn())
    {
        return;
    }

    m_playlist->clear();

    if (MusicSetting::getInstance()->isDefaultQuickTaskMusicOn() ||
        MusicSetting::getInstance()->getSelfQuickTaskMusic().isEmpty())
    {
        m_playlist->addMedia(QUrl(MusicSetting::getInstance()->getDefaultQuickTaskMusic()));
    }
    else
    {
        m_playlist->addMedia(QUrl::fromLocalFile(MusicSetting::getInstance()->getSelfQuickTaskMusic()));
    }

    m_mediaPlayer->play();
}

void MusicPlayer::playFileTaskMusic()
{
    if (!MusicSetting::getInstance()->isMusicOn())
    {
        return;
    }

    m_playlist->clear();

    if (MusicSetting::getInstance()->isDefaultFileTaskMusicOn() ||
        MusicSetting::getInstance()->getSelfFileTaskMusic().isEmpty())
    {
        m_playlist->addMedia(QUrl(MusicSetting::getInstance()->getDefaultFileTaskMusic()));
    }
    else
    {
        m_playlist->addMedia(QUrl::fromLocalFile(MusicSetting::getInstance()->getSelfFileTaskMusic()));
    }

    m_mediaPlayer->play();
}

void MusicPlayer::stop()
{
    m_mediaPlayer->stop();
}

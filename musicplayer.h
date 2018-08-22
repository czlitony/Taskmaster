#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();

    void playQuickTaskMusic();
    void playFileTaskMusic();

    void stop();

private:
    QMediaPlaylist* m_playlist;
    QMediaPlayer* m_mediaPlayer;
};

#endif // MUSICPLAYER_H

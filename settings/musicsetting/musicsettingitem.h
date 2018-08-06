#ifndef MUSICSETTINGITEM_H
#define MUSICSETTINGITEM_H

#include "taskmusic.h"

class MusicSettingItem
{
public:
    explicit MusicSettingItem();
    explicit MusicSettingItem(const bool musicOn,
                     const TaskMusic& quickTaskMusic,
                     const TaskMusic& fileTaskMusic);

    void switchMusic(bool musicOn);
    bool isMusicOn() const;

    void setQuickTaskMusic(const TaskMusic& quickTaskMusic);
    const TaskMusic getQuickTaskMusic() const;

    void setFileTaskMusic(const TaskMusic& fileTaskMusic);
    const TaskMusic getFileTaskMusic() const;

private:
    bool m_musicOn;

    TaskMusic m_quickTaskMusic;
    TaskMusic m_fileTaskMusic;

};

#endif // MUSICSETTINGITEM_H

#ifndef MUSICSETTING_H
#define MUSICSETTING_H

#include <QObject>

class MusicSettingItem;
class MusicSettingCache;

class MusicSetting
{
public:
    static MusicSetting* getInstance();
    static void releaseIntance();

    void switchMusic(bool on);

    bool isMusicOn() const;

    void setDefaultQuickTaskMusicOn();
    void setSelfQuickTaskMusic(const QString& music);

    bool isDefaultQuickTaskMusicOn() const;
    const QString getDefaultQuickTaskMusic() const;
    const QString getSelfQuickTaskMusic() const;

    void setDefaultFileTaskMusicOn();
    void setSelfFileTaskMusic(const QString& music);

    bool isDefaultFileTaskMusicOn() const;
    const QString getDefaultFileTaskMusic() const;
    const QString getSelfFileTaskMusic() const;

private:
    MusicSetting();

    void updateCache();
    void readCache();

    static MusicSetting* m_pInstance;

    MusicSettingItem* m_musicSettingItem;

};

#endif // MUSICSETTING_H

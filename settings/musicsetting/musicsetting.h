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

    MusicSettingItem getMusicSettings();

    void switchMusic(bool on);

    void setDefaultQuickTaskMusic();
    void setSelfQuickTaskMusic(const QString& music);

    void setDefaultFileTaskMusic();
    void setSelfFileTaskMusic(const QString& music);

private:
    MusicSetting();

    void updateCache();
    void readCache();

    static MusicSetting* m_pInstance;

    MusicSettingItem* m_musicSettingItem;
    MusicSettingCache* m_musicSettingCache;

};

#endif // MUSICSETTING_H

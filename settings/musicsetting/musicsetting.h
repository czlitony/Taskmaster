#ifndef MUSICSETTING_H
#define MUSICSETTING_H

#include <QObject>

#include"musicsettingitem.h"

class MusicSettingCache;

class MusicSetting
{
public:
    MusicSetting();
    ~MusicSetting();

    void switchMusic(bool on);

private:
    void updateCache();

    MusicSettingItem* m_musicSettingItem;
    MusicSettingCache* m_musicSettingCache;

};

#endif // MUSICSETTING_H

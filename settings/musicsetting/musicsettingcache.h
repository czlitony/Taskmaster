#ifndef MUSICSETTINGCACHE_H
#define MUSICSETTINGCACHE_H

#include "musicsettingitem.h"

class MusicSettingCache
{
public:
    virtual ~MusicSettingCache() = default;

    virtual void setMusicSetting(const MusicSettingItem& settingItem) = 0;
    virtual void getMusicSetting(MusicSettingItem& settingItem) = 0;
};

#endif // MUSICSETTINGCACHE_H

#ifndef MUSICSETTINGXMLCACHE_H
#define MUSICSETTINGXMLCACHE_H

#include "musicsettingcache.h"

class MusicSettingXmlCache : public MusicSettingCache
{
public:
    void setMusicSetting(const MusicSettingItem& settingItem) override;
    void getMusicSetting(MusicSettingItem& settingItem) override;

private:
    MusicSettingItem m_musicSettingItem;
};

#endif // MUSICSETTINGXMLCACHE_H

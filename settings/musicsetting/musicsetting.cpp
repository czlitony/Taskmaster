#include "musicsetting.h"
#include "musicsettingcache.h"
#include "musicsettingxmlcache.h"


MusicSetting::MusicSetting():
    m_musicSettingItem(new MusicSettingItem()),
    m_musicSettingCache(new MusicSettingXmlCache())
{

}

MusicSetting::~MusicSetting()
{
    delete m_musicSettingCache;
}

void MusicSetting::switchMusic(bool on)
{
    m_musicSettingItem->switchMusic(on);

    updateCache();
}

void MusicSetting::updateCache()
{
    m_musicSettingCache->setMusicSetting(*m_musicSettingItem);
}

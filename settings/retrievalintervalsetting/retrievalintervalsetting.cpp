#include "retrievalintervalsetting.h"
#include "../settingcache/settingcache.h"

RetrievalIntervalSetting* RetrievalIntervalSetting::m_pInstance = nullptr;

RetrievalIntervalSetting *RetrievalIntervalSetting::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new RetrievalIntervalSetting();
        atexit(releaseIntance);
    }
    return m_pInstance;
}

void RetrievalIntervalSetting::releaseIntance()
{
    delete m_pInstance;
    m_pInstance = nullptr;
}


RetrievalIntervalSetting::RetrievalIntervalSetting()
{
    readCache();
}

void RetrievalIntervalSetting::setInterval(const int interval)
{
    m_interval = interval;

    updateCache();
}

int RetrievalIntervalSetting::getInterval() const
{
    return m_interval;
}

void RetrievalIntervalSetting::updateCache()
{
    SettingCache::getInstance()->updateRetrievalInterval(m_interval);
}

void RetrievalIntervalSetting::readCache()
{
    m_interval = SettingCache::getInstance()->getRetrievalInterval();
}

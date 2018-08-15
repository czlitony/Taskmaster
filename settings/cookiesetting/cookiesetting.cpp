#include "cookiesetting.h"
#include "../settingcache/settingcache.h"

CookieSetting* CookieSetting::m_pInstance = nullptr;

CookieSetting *CookieSetting::getInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new CookieSetting();
        atexit(releaseIntance);
    }
    return m_pInstance;
}

void CookieSetting::releaseIntance()
{
    delete m_pInstance;
    m_pInstance = nullptr;
}


CookieSetting::CookieSetting()
{
    readCache();
}

void CookieSetting::setCookie(const QString &cookie)
{
    m_cookie = cookie;

    updateCache();
}

const QString CookieSetting::getCookie() const
{
    return m_cookie;
}

void CookieSetting::updateCache()
{
    SettingCache::getInstance()->updateCookie(m_cookie);
}

void CookieSetting::readCache()
{
    m_cookie = SettingCache::getInstance()->getCookie();
}

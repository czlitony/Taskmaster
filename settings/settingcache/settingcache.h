#ifndef SETTINGCACHE_H
#define SETTINGCACHE_H

#include <QSettings>

class MusicSettingItem;

class SettingCache
{
public:
    static SettingCache *getInstance();
    static void releaseIntance();

    void updateMusicSetting(const MusicSettingItem& settingItem);
    void getMusicSetting(MusicSettingItem& settingItem) const;

    void updateCookie(const QString& cookie);
    const QString getCookie() const;

    void updateRetrievalInterval(const int interval);
    int getRetrievalInterval() const;

private:
    SettingCache();

    void setValue(const QString &group, const QString &key, const QVariant &value);
    QVariant getValue(const QString &group, const QString &key, const QVariant &defaultValue = QVariant()) const;

    void sync();

    static SettingCache* m_pInstance;
    QSettings m_setting;
};

#endif // SETTINGCACHE_H

#ifndef COOKIESETTING_H
#define COOKIESETTING_H

#include <QString>

class CookieSetting
{
public:
    static CookieSetting* getInstance();
    static void releaseIntance();

    void setCookie(const QString& m_cookie);
    const QString getCookie() const;

private:
    CookieSetting();

    void updateCache();
    void readCache();

    static CookieSetting* m_pInstance;
    QString m_cookie;
};

#endif // COOKIESETTING_H

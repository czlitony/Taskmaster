#ifndef RETRIEVALINTERVAL_H
#define RETRIEVALINTERVAL_H

#include <QString>

class RetrievalIntervalSetting
{
public:
    static RetrievalIntervalSetting* getInstance();
    static void releaseIntance();

    void setInterval(const int interval);
    int getInterval() const;

private:
    RetrievalIntervalSetting();

    void updateCache();
    void readCache();

    static RetrievalIntervalSetting* m_pInstance;
    int m_interval;
};

#endif // RETRIEVALINTERVAL_H

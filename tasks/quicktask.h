#ifndef QUICKTASK_H
#define QUICKTASK_H

#include "orderdetail.h"

class AbandonInfo
{
public:
    AbandonInfo() = default;
    explicit AbandonInfo(const QString& orderId, const QString& translatorId):
        m_orderId(orderId),
        m_translatorId(translatorId)
    {

    }

    AbandonInfo(const AbandonInfo& rhs)
    {
        this->m_orderId = rhs.m_orderId;
        this->m_translatorId = rhs.m_translatorId;
    }

    AbandonInfo& operator=(const AbandonInfo& rhs)
    {
        this->m_orderId = rhs.m_orderId;
        this->m_translatorId = rhs.m_translatorId;

        return *this;
    }

    const QString getOrderId() const
    {
        return m_orderId;
    }

    const QString getTranslatorId() const
    {
        return m_translatorId;
    }

private:
    QString m_orderId;
    QString m_translatorId;
};

class QuickTask
{
public:
    QuickTask();

    const OrderDetail getOrderDetail() const;
    void setOrderDetail(const OrderDetail& orderDetail);

    const QString getLanguage() const;
    void setLanguage(const QString& language);

    unsigned int getWordNumber() const;
    void setWordNumber(const unsigned int wordNum);

    const QString getAbstract() const;
    void setAbstract(const QString& abstract);

    const QString getFinishTime() const;
    void setFinishTime(const QString& finishTime);

    const QString getPay() const;
    void setPay(const QString& pay);

    const QString getBonus() const;
    void setBonus(const QString& bonus);

    const AbandonInfo getAbandonInfo() const;
    void setAbandonInfo(const AbandonInfo& abandonInfo);

private:
    OrderDetail m_orderDetail;
    QString m_language;
    unsigned short m_wordNum;
    QString m_abstract;
    QString m_finishTime;
    QString m_pay;
    QString m_bonus;
    AbandonInfo m_abandonInfo;
};

#endif // QUICKTASK_H

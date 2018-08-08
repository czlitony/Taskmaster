#ifndef QUICKTASK_H
#define QUICKTASK_H

#include "orderdetail.h"

class AbandonInfo
{
public:
    AbandonInfo() = default;
    explicit AbandonInfo(const QString& orderId, const QString& translatorId, const QString& source):
        m_orderId(orderId),
        m_translatorId(translatorId),
        m_source(source)
    {

    }

    AbandonInfo(const AbandonInfo& rhs)
    {
        this->m_orderId = rhs.m_orderId;
        this->m_translatorId = rhs.m_translatorId;
        this->m_source = rhs.m_source;
    }

    AbandonInfo& operator=(const AbandonInfo& rhs)
    {
        this->m_orderId = rhs.m_orderId;
        this->m_translatorId = rhs.m_translatorId;
        this->m_source = rhs.m_source;

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

    const QString getSource() const
    {
        return m_source;
    }

private:
    QString m_orderId;
    QString m_translatorId;
    QString m_source;
};

class QuickTask
{
public:
    QuickTask();

    const OrderDetail getOrderDetail() const;
    void setOrderDetail(const OrderDetail& orderDetail);

    const QString getLanguage() const;
    void setLanguage(const QString& language);

    const unsigned int getWordNumber() const;
    void setWordNumber(const unsigned int wordNum);

    const QString getAbstract() const;
    void setAbstract(const QString& abstract);

    const QString getFinishTime() const;
    void setFinishTime(const QString& finishTime);

    const double getPay() const;
    void setPay(const double pay);

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
    double m_pay;
    QString m_bonus;
    AbandonInfo m_abandonInfo;
};

#endif // QUICKTASK_H

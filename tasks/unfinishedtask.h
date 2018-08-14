#ifndef UnfinishedTask_H
#define UnfinishedTask_H

#include "orderdetail.h"

class UnfinishedTask
{
public:
    UnfinishedTask();

    const OrderDetail getOrderDetail() const;
    void setOrderDetail(const OrderDetail& orderDetail);

    const QString getLanguage() const;
    void setLanguage(const QString& language);

    unsigned int getWordNumber() const;
    void setWordNumber(const unsigned int wordNum);

    const QString getStatus() const;
    void setStatus(const QString& status);

    const QString getTimeLeft() const;
    void setTimeLeft(const QString& timeLeft);

    const QString getDeadline() const;
    void setDeadline(const QString& deadline);

    const QString getPay() const;
    void setPay(const QString& pay);

    const QString getBonus() const;
    void setBonus(const QString& bonus);

private:
    OrderDetail m_orderDetail;
    QString m_language;
    unsigned int m_wordNum;
    QString m_status;
    QString m_timeLeft;
    QString m_deadline;
    QString m_pay;
    QString m_bonus;
};

#endif // UnfinishedTask_H

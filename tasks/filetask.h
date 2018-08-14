#ifndef FileTask_H
#define FileTask_H

#include "orderdetail.h"

class FileTask
{
public:
    FileTask();

    const OrderDetail getOrderDetail() const;
    void setOrderDetail(const OrderDetail& orderDetail);

    const QString getLanguage() const;
    void setLanguage(const QString& language);

    unsigned int getWordNumber() const;
    void setWordNumber(const unsigned int wordNum);

    const QString getArea() const;
    void setArea(const QString& area);

    const QString getUsage() const;
    void setUsage(const QString& usage);

    const QString getDeadline() const;
    void setDeadline(const QString& deadline);

    const QString getTimeLeft() const;
    void setTimeLeft(const QString& timeLeft);

    const QString getPay() const;
    void setPay(const QString& pay);

    const QString getBonus() const;
    void setBonus(const QString& bonus);

private:
    OrderDetail m_orderDetail;
    QString m_language;
    unsigned short m_wordNum;
    QString m_area;
    QString m_usage;
    QString m_deadline;
    QString m_timeLeft;
    QString m_pay;
    QString m_bonus;
};

#endif // FileTask_H

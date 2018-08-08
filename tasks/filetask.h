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

    const unsigned int getWordNumber() const;
    void setWordNumber(const unsigned int wordNum);

    const QString getArea() const;
    void setArea(const QString& area);

    const QString getDeadline() const;
    void setDeadline(const QString& deadline);

    const QString getTimeLeft() const;
    void setTimeLeft(const QString& timeLeft);

    const double getPay() const;
    void setPay(const double pay);

    const QString getBonus() const;
    void setBonus(const QString& bonus);

private:
    OrderDetail m_orderDetail;
    QString m_language;
    unsigned short m_wordNum;
    QString m_area;
    QString m_deadline;
    QString m_timeLeft;
    double m_pay;
    QString m_bonus;
};

#endif // FileTask_H

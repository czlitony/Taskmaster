#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include "QString"

class OrderDetail
{
public:
    OrderDetail() = default;
    OrderDetail(const OrderDetail& rhs);
    OrderDetail& operator=(const OrderDetail& rhs);

    const QString getNumber() const;
    void setNumber(const QString& number);

    const QString getId() const;
    void setId(const QString& id);

    const QString getDetailLink() const;
    void setDetailLink(const QString& detailLink);

private:
    QString m_number;
    QString m_id;
    QString m_detailLink;
};

#endif // ORDERDETAIL_H

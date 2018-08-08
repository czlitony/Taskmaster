#include "orderdetail.h"

OrderDetail::OrderDetail(const OrderDetail &rhs)
{
    this->m_number = rhs.m_number;
    this->m_id = rhs.m_id;
    this->m_detailLink = rhs.m_detailLink;
}

OrderDetail &OrderDetail::operator=(const OrderDetail &rhs)
{
    this->m_number = rhs.m_number;
    this->m_id = rhs.m_id;
    this->m_detailLink = rhs.m_detailLink;

    return *this;
}

const QString OrderDetail::getNumber() const
{
    return m_number;
}

void OrderDetail::setNumber(const QString &number)
{
    m_number = number;
}

const QString OrderDetail::getId() const
{
    return m_id;
}

void OrderDetail::setId(const QString &id)
{
    m_id = id;
}

const QString OrderDetail::getDetailLink() const
{
    return m_detailLink;
}

void OrderDetail::setDetailLink(const QString &detailLink)
{
    m_detailLink = detailLink;
}

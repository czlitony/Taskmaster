#include "FileTask.h"

FileTask::FileTask():
    m_wordNum(0),
    m_pay(0.0)
{

}

const OrderDetail FileTask::getOrderDetail() const
{
    return m_orderDetail;
}

void FileTask::setOrderDetail(const OrderDetail &orderDetail)
{
    m_orderDetail = orderDetail;
}

const QString FileTask::getLanguage() const
{
    return m_language;
}

void FileTask::setLanguage(const QString &language)
{
    m_language = language;
}

const unsigned int FileTask::getWordNumber() const
{
    return m_wordNum;
}

void FileTask::setWordNumber(const unsigned int wordNum)
{
    m_wordNum = wordNum;
}

const QString FileTask::getArea() const
{
    return m_area;
}

void FileTask::setArea(const QString &area)
{
    m_area = area;
}

const QString FileTask::getDeadline() const
{
    return m_deadline;
}

void FileTask::setDeadline(const QString &deadline)
{
    m_deadline = deadline;
}

const QString FileTask::getTimeLeft() const
{
    return m_timeLeft;
}

void FileTask::setTimeLeft(const QString &timeLeft)
{
    m_timeLeft = timeLeft;
}

const double FileTask::getPay() const
{
    return m_pay;
}

void FileTask::setPay(const double pay)
{
    m_pay = pay;
}

const QString FileTask::getBonus() const
{
    return m_bonus;
}

void FileTask::setBonus(const QString &bonus)
{
    m_bonus = bonus;
}

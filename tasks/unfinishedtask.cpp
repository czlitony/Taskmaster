#include "unfinishedtask.h"

UnfinishedTask::UnfinishedTask():
    m_wordNum(0)
{

}

const OrderDetail UnfinishedTask::getOrderDetail() const
{
    return m_orderDetail;
}

void UnfinishedTask::setOrderDetail(const OrderDetail &orderDetail)
{
    m_orderDetail = orderDetail;
}

const QString UnfinishedTask::getLanguage() const
{
    return m_language;
}

void UnfinishedTask::setLanguage(const QString &language)
{
    m_language = language;
}

unsigned int UnfinishedTask::getWordNumber() const
{
    return m_wordNum;
}

void UnfinishedTask::setWordNumber(unsigned int wordNum)
{
    m_wordNum = wordNum;
}

const QString UnfinishedTask::getStatus() const
{
    return m_status;
}

void UnfinishedTask::setStatus(const QString &status)
{
    m_status = status;
}

const QString UnfinishedTask::getTimeLeft() const
{
    return m_timeLeft;
}

void UnfinishedTask::setTimeLeft(const QString &timeLeft)
{
    m_timeLeft = timeLeft;
}

const QString UnfinishedTask::getDeadline() const
{
    return m_deadline;
}

void UnfinishedTask::setDeadline(const QString &deadline)
{
    m_deadline = deadline;
}

const QString UnfinishedTask::getPay() const
{
    return m_pay;
}

void UnfinishedTask::setPay(const QString& pay)
{
    m_pay = pay;
}

const QString UnfinishedTask::getBonus() const
{
    return m_bonus;
}

void UnfinishedTask::setBonus(const QString &bonus)
{
    m_bonus = bonus;
}

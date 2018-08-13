#include "quicktask.h"

QuickTask::QuickTask():
    m_wordNum(0)
{

}

const OrderDetail QuickTask::getOrderDetail() const
{
    return m_orderDetail;
}

void QuickTask::setOrderNum(const OrderDetail &orderDetail)
{
    m_orderDetail = orderDetail;
}

const QString QuickTask::getLanguage() const
{
    return m_language;
}

void QuickTask::setLanguage(const QString &language)
{
    m_language = language;
}

unsigned int QuickTask::getWordNumber() const
{
    return m_wordNum;
}

void QuickTask::setWordNumber(const unsigned int wordNum)
{
    m_wordNum = wordNum;
}

const QString QuickTask::getAbstract() const
{
    return m_abstract;
}

void QuickTask::setAbstract(const QString &abstract)
{
    m_abstract = abstract;
}

const QString QuickTask::getFinishTime() const
{
    return m_finishTime;
}

void QuickTask::setFinishTime(const QString &finishTime)
{
    m_finishTime = finishTime;
}

const QString QuickTask::getPay() const
{
    return m_pay;
}

void QuickTask::setPay(const QString& pay)
{
    m_pay = pay;
}

const QString QuickTask::getBonus() const
{
    return m_bonus;
}

void QuickTask::setBonus(const QString &bonus)
{
    m_bonus = bonus;
}

const AbandonInfo QuickTask::getAbandonInfo() const
{
    return m_abandonInfo;
}

void QuickTask::setAbandonInfo(const AbandonInfo &abandonInfo)
{
    m_abandonInfo = abandonInfo;
}

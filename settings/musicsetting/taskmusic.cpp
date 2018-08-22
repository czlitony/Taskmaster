#include "taskmusic.h"

TaskMusic::TaskMusic():
    m_isDefault(true),
    m_file("")
{

}

TaskMusic::TaskMusic(bool isDefault, const QString &file):
    m_isDefault(isDefault),
    m_file(file)
{

}

bool TaskMusic::isDefaultMusicOn() const
{
    return m_isDefault;
}

void TaskMusic::setAsDefault(bool isDefault)
{
    m_isDefault = isDefault;
}

const QString TaskMusic::getFile() const
{
    return m_file;
}

void TaskMusic::setFile(const QString &file)
{
    m_file = file;
}

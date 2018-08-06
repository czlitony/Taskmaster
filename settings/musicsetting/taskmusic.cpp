#include "taskmusic.h"

TaskMusic::TaskMusic():
    m_type(TaskType::Quick_Task),
    m_isDefault(true),
    m_file("")
{

}

TaskMusic::TaskMusic(const TaskType &type, bool isDefault, const QString &file):
    m_type(type),
    m_isDefault(isDefault),
    m_file(file)
{

}

const TaskType TaskMusic::getType() const
{
    return m_type;
}

bool TaskMusic::isDefaultMusic() const
{
    return m_isDefault;
}

const QString TaskMusic::getFile() const
{
    return m_file;
}

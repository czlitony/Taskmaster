#ifndef TASKMUSIC_H
#define TASKMUSIC_H

#include "tasktype.h"

#include <QString>

class TaskMusic
{
public:
    TaskMusic();
    TaskMusic(const TaskType& type, bool isDefault, const QString& file);

    const TaskType getType() const;
    bool isDefaultMusic() const;
    const QString getFile() const;

private:
    TaskType m_type;
    bool m_isDefault;
    QString m_file;

};

#endif // TASKMUSIC_H

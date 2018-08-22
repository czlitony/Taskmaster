#ifndef TASKMUSIC_H
#define TASKMUSIC_H

#include "tasktype.h"

#include <QString>

class TaskMusic
{
public:
    TaskMusic();
    TaskMusic(bool isDefault, const QString& file);

    bool isDefaultMusicOn() const;
    void setAsDefault(bool isDefault);

    const QString getFile() const;
    void setFile(const QString& file);

private:
    bool m_isDefault;
    QString m_file;

};

#endif // TASKMUSIC_H

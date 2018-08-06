#ifndef MUSICSETTING_H
#define MUSICSETTING_H

#include <QObject>

class MusicSetting
{
public:
    MusicSetting();

    void switchOnMusic();
    void switchOffMusic();

private:
    bool isMusicOn;

};

#endif // MUSICSETTING_H

#include "musicsetting.h"

MusicSetting::MusicSetting():
    isMusicOn(true)
{

}

void MusicSetting::switchOnMusic()
{
    isMusicOn = true;
}

void MusicSetting::switchOffMusic()
{
    isMusicOn = false;
}

#include "musicsettingxmlcache.h"
#include <QtXml>
#include <QFile>


void MusicSettingXmlCache::setMusicSetting(const MusicSettingItem &settingItem)
{
    QDomDocument doc;
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml",
        "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("MusicSetting");
    doc.appendChild(root);

    QDomText text;

    // Quick Task Music setting
    QDomElement quickTask = doc.createElement("QuickTask");

    QDomElement isDefaultQuickTask = doc.createElement("IsDefault");
    text = doc.createTextNode(settingItem.getQuickTaskMusic().isDefaultMusic() ? "true" : "false");
    isDefaultQuickTask.appendChild(text);
    quickTask.appendChild(isDefaultQuickTask);

    QDomElement quickTaskMusic = doc.createElement("Music");
    text = doc.createTextNode(settingItem.getQuickTaskMusic().getFile());
    quickTaskMusic.appendChild(text);
    quickTask.appendChild(quickTaskMusic);

    // File Task Music setting
    QDomElement fileTask = doc.createElement("FileTask");

    QDomElement isDefaultFileTask = doc.createElement("IsDefault");
    text = doc.createTextNode(settingItem.getFileTaskMusic().isDefaultMusic() ? "true" : "false");
    isDefaultFileTask.appendChild(text);
    fileTask.appendChild(isDefaultFileTask);

    QDomElement fileTaskMusic = doc.createElement("Music");
    text = doc.createTextNode(settingItem.getFileTaskMusic().getFile());
    fileTaskMusic.appendChild(text);
    fileTask.appendChild(fileTaskMusic);

    root.appendChild(quickTask);
    root.appendChild(fileTask);

    QFile musicSettingFile("music_setting.xml");
    if (!musicSettingFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&musicSettingFile);
    doc.save(out, 4);
    musicSettingFile.close();
}

void MusicSettingXmlCache::getMusicSetting(MusicSettingItem &settingItem)
{

}

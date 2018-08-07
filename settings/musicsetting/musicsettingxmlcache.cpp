#include "musicsettingxmlcache.h"
#include "utils/fileutils.h"
#include <QtXml>
#include <QFile>
#include <QString>

namespace {

const QString ROOT = "MusicSetting";
const QString MUSIC_ON = "MusicOn";
const QString QUICK_TASK = "QuickTask";
const QString FILE_TASK = "FileTask";
const QString IS_DEFAULT = "IsDefault";
const QString MUSIC_FILE = "MusicFile";

}

void MusicSettingXmlCache::setMusicSetting(const MusicSettingItem &settingItem)
{
    QDomDocument doc;
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml",
        "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement(ROOT);
    doc.appendChild(root);

    QDomText text;

    // Music On/Off
    QDomElement musicOn = doc.createElement(MUSIC_ON);
    text = doc.createTextNode(settingItem.isMusicOn() ? "true" : "false");
    musicOn.appendChild(text);


    // Quick Task Music setting
    QDomElement quickTask = doc.createElement(QUICK_TASK);

    QDomElement isDefaultQuickTask = doc.createElement(IS_DEFAULT);
    text = doc.createTextNode(settingItem.getQuickTaskMusic().isDefaultMusic() ? "true" : "false");
    isDefaultQuickTask.appendChild(text);
    quickTask.appendChild(isDefaultQuickTask);

    QDomElement quickTaskMusic = doc.createElement(MUSIC_FILE);
    text = doc.createTextNode(settingItem.getQuickTaskMusic().getFile());
    quickTaskMusic.appendChild(text);
    quickTask.appendChild(quickTaskMusic);

    // File Task Music setting
    QDomElement fileTask = doc.createElement(FILE_TASK);

    QDomElement isDefaultFileTask = doc.createElement(IS_DEFAULT);
    text = doc.createTextNode(settingItem.getFileTaskMusic().isDefaultMusic() ? "true" : "false");
    isDefaultFileTask.appendChild(text);
    fileTask.appendChild(isDefaultFileTask);

    QDomElement fileTaskMusic = doc.createElement(MUSIC_FILE);
    text = doc.createTextNode(settingItem.getFileTaskMusic().getFile());
    fileTaskMusic.appendChild(text);
    fileTask.appendChild(fileTaskMusic);

    root.appendChild(musicOn);
    root.appendChild(quickTask);
    root.appendChild(fileTask);

    QFile musicSettingFile(FileUtils::getMusicSettingFile());
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
    QDomDocument doc;
    QFile musicSettingFile(FileUtils::getMusicSettingFile());
    if (!musicSettingFile.open(QIODevice::ReadOnly))
    {
        return;
    }

    if (!doc.setContent(&musicSettingFile))
    {
        musicSettingFile.close();
        return;
    }
    musicSettingFile.close();

    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    while (!n.isNull())
    {
        if (n.isElement())
        {
            QDomElement e = n.toElement();
            if (e.tagName() == MUSIC_ON)
            {
                settingItem.switchMusic(e.text() == "true" ? true : false);
            }
            else if (e.tagName() == QUICK_TASK)
            {
                TaskMusic quickTaskMusic;
                QDomNodeList list = e.childNodes();
                for (int i=0; i<list.count(); ++i)
                {
                    QDomNode node = list.at(i);
                    if (node.isElement() && node.toElement().tagName() == IS_DEFAULT)
                    {
                        quickTaskMusic.setAsDefault(node.toElement().text() == "true" ? true : false);
                    }
                    else if (node.isElement() && node.toElement().tagName() == MUSIC_FILE)
                    {
                        quickTaskMusic.setFile(node.toElement().text());
                    }
                }
                settingItem.setQuickTaskMusic(quickTaskMusic);
            }
            else if (e.tagName() == FILE_TASK)
            {
                TaskMusic fileTaskMusic;
                QDomNodeList list = e.childNodes();
                for (int i=0; i<list.count(); ++i)
                {
                    QDomNode node = list.at(i);
                    if (node.isElement() && node.toElement().tagName() == IS_DEFAULT)
                    {
                        fileTaskMusic.setAsDefault(node.toElement().text() == "true" ? true : false);
                    }
                    else if (node.isElement() && node.toElement().tagName() == MUSIC_FILE)
                    {
                        fileTaskMusic.setFile(node.toElement().text());
                    }
                }
                settingItem.setFileTaskMusic(fileTaskMusic);
            }
        }

        n = n.nextSibling();
    }

}

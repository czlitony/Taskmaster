#ifndef TASKPARSER_H
#define TASKPARSER_H

#include <QList>
#include <QString>

class UnfinishedTask;
class QuickTask;
class FileTask;

class TaskParser
{
public:
    TaskParser();

    bool parse(const QString& response,
               QList<UnfinishedTask>& unfinishedTask,
               QList<QuickTask>& quickTask,
               QList<FileTask>& fileTask);

private:
    void parseUnfinishedTask(const QString& unfinishedTaskStr, QList<UnfinishedTask>& unfinishedTask);
    void parseQuickTask(const QString& quickTaskStr, QList<QuickTask>& quickTask);
    void parseFileTask(const QString& fileTaskStr, QList<FileTask>& fileTask);

//    QString getTaskMetaData(const QString& taskStr, const QString& type);
    QString getTaskMetaData(const QString& taskStr, const QString& dataTag, const QString& dataLeftWrap = ">", const QString& dataRightWrap = "<");
    QString getQuickTaskTranslatorId(const QString& taskStr);


};

#endif // TASKPARSER_H

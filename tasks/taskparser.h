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
    void parseUnfinishedTask(QList<UnfinishedTask>& unfinishedTask);
    void parseQuickTask(QList<QuickTask>& quickTask);
    void parseFileTask(QList<FileTask>& fileTask);
};

#endif // TASKPARSER_H

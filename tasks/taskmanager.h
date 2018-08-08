#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>

class TaskRetriever;
class UnfinishedTask;
class QuickTask;
class FileTask;

class TaskManager : public QObject
{
    Q_OBJECT

public:
    TaskManager();

    void start();

public slots:
    void onTasksRetrieved(enum RetrievalResult result,
                          QList<UnfinishedTask> &unfinishedTask,
                          QList<QuickTask> &quickTask,
                          QList<FileTask> &fileTask);
    void onTasksRetrieved();

private:
    TaskRetriever* m_taskRetriever;
};

#endif // TASKMANAGER_H

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "unfinishedtask.h"
#include "quicktask.h"
#include "filetask.h"
#include <QObject>

class TaskRetriever;

class TaskManager : public QObject
{
    Q_OBJECT

public:
    TaskManager();

    void start();

public slots:
    void onTasksRetrieved(enum RetrievalResult result,
                          QList<UnfinishedTask> unfinishedTask,
                          QList<QuickTask> quickTask,
                          QList<FileTask> fileTask);

private:
    TaskRetriever* m_taskRetriever;
};

#endif // TASKMANAGER_H

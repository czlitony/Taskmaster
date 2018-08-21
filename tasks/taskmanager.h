#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "unfinishedtask.h"
#include "quicktask.h"
#include "filetask.h"
#include "taskretriever.h"
#include <QObject>
#include <functional>

using TaskRetrievalCallback = std::function<void(enum TaskRetrievalResult result,
                                                 const QList<UnfinishedTask>& unfinishedTask,
                                                 const QList<QuickTask>& quickTask,
                                                 const QList<FileTask>& fileTask)>;

class TaskManager : public QObject
{
    Q_OBJECT

public:
    TaskManager();

    void retrieveTask(TaskRetrievalCallback callback);

public slots:
    void onTasksRetrieved(enum TaskRetrievalResult result,
                          const QList<UnfinishedTask>& unfinishedTask,
                          const QList<QuickTask>& quickTask,
                          const QList<FileTask>& fileTask);

private:
    TaskRetriever* m_taskRetriever;

    TaskRetrievalCallback m_taskRetrievalCallbcak;
};

#endif // TASKMANAGER_H

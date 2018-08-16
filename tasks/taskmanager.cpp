#include "taskmanager.h"

TaskManager::TaskManager():
    m_taskRetriever(new TaskRetriever)
{
    QObject::connect(m_taskRetriever, SIGNAL(finished(enum RetrievalResult, const QList<UnfinishedTask>&, const QList<QuickTask>&, const QList<FileTask>&)),
                     this, SLOT(onTasksRetrieved(enum RetrievalResult, const QList<UnfinishedTask>&, const QList<QuickTask>&, const QList<FileTask>&)),
                     Qt::DirectConnection);
}

void TaskManager::retrieveTask(TaskRetrievalCallback callback)
{
    m_taskRetrievalCallbcak = callback;
    m_taskRetriever->retrieveTasks();
}

void TaskManager::onTasksRetrieved(enum RetrievalResult result,
                                   const QList<UnfinishedTask>& unfinishedTask,
                                   const QList<QuickTask>& quickTask,
                                   const QList<FileTask>& fileTask)
{
    if (m_taskRetrievalCallbcak)
    {
        m_taskRetrievalCallbcak(result, unfinishedTask, quickTask, fileTask);
    }
}

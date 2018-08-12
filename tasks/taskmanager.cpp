#include "taskmanager.h"
#include "taskretriever.h"

TaskManager::TaskManager():
    m_taskRetriever(new TaskRetriever)
{
    QObject::connect(m_taskRetriever, SIGNAL(finished(enum RetrievalResult, QList<UnfinishedTask>, QList<QuickTask>, QList<FileTask>)),
                     this, SLOT(onTasksRetrieved(enum RetrievalResult, QList<UnfinishedTask>, QList<QuickTask>, QList<FileTask>)),
                     Qt::DirectConnection);
}

void TaskManager::start()
{
    m_taskRetriever->retrieveTasks();
}

void TaskManager::onTasksRetrieved(RetrievalResult result,
                                   QList<UnfinishedTask> unfinishedTask,
                                   QList<QuickTask> quickTask,
                                   QList<FileTask> fileTask)
{
    qDebug() << "finished";
    qDebug() << result;
}

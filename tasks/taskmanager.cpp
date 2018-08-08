#include "taskmanager.h"
#include "taskretriever.h"
#include "unfinishedtask.h"
#include "quicktask.h"
#include "filetask.h"

TaskManager::TaskManager():
    m_taskRetriever(new TaskRetriever)
{
//    QObject::connect(m_taskRetriever, SIGNAL(finished(enum RetrievalResult result, QList<UnfinishedTask> &unfinishedTask, QList<QuickTask> &quickTask, QList<FileTask> &fileTask)),
//                     this, SLOT(onTasksRetrieved(enum RetrievalResult result, QList<UnfinishedTask> &unfinishedTask, QList<QuickTask> &quickTask, QList<FileTask> &fileTask)),
//                     Qt::DirectConnection);
    QObject::connect(m_taskRetriever, SIGNAL(finished()),
                     this, SLOT(onTasksRetrieved()),
                     Qt::DirectConnection);
}

void TaskManager::start()
{
    m_taskRetriever->retrieveTasks();
}

void TaskManager::onTasksRetrieved(RetrievalResult result,
                                   QList<UnfinishedTask> &unfinishedTask,
                                   QList<QuickTask> &quickTask,
                                   QList<FileTask> &fileTask)
{
    enum RetrievalResult ret = result;
    QList<UnfinishedTask> unfinishedTaskList = unfinishedTask;
    QList<QuickTask> quickTaskList = quickTask;
    QList<FileTask> fileTaskList = fileTask;
    qDebug() << "finished";
    qDebug() << ret;
}

void TaskManager::onTasksRetrieved()
{
    qDebug() << "finished";

    enum RetrievalResult result = RetrievalResult::UNKNOWN;
    QList<UnfinishedTask> unfinishedTask;
    QList<QuickTask> quickTask;
    QList<FileTask> fileTask;
    m_taskRetriever->getRetrievedTasks(result, unfinishedTask, quickTask, fileTask);
}

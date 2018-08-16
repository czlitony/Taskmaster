#ifndef TASKMASTER_H
#define TASKMASTER_H

#include <QObject>
#include <QTimer>

class TaskManager;
class UnfinishedTask;
class QuickTask;
class FileTask;

class TaskMaster : public QObject
{
    Q_OBJECT

public:
    TaskMaster();
    ~TaskMaster();

    void start();
    void stop();

public slots:
    void retrieveTask();

private:
    void init();

    void onTasksRetrieved(enum RetrievalResult result,
                          const QList<UnfinishedTask>& unfinishedTask,
                          const QList<QuickTask>& quickTask,
                          const QList<FileTask>& fileTask);

    TaskManager* m_taskManager;

    QTimer* m_taskRetrievalTimer;
};

#endif // TASKMASTER_H

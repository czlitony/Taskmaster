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

signals:
    void fireOnTasksRetrieved(enum TaskRetrievalResult result,
                              const QList<UnfinishedTask>& unfinishedTask,
                              const QList<QuickTask>& quickTask,
                              const QList<FileTask>& fileTask);

private:
    void init();

    void onTasksRetrieved(enum TaskRetrievalResult result,
                          const QList<UnfinishedTask>& unfinishedTask,
                          const QList<QuickTask>& quickTask,
                          const QList<FileTask>& fileTask);

    TaskManager* m_taskManager;

    QTimer* m_taskRetrievalTimer;
};

#endif // TASKMASTER_H

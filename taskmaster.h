#ifndef TASKMASTER_H
#define TASKMASTER_H

#include <QObject>
#include <QTimer>

class TaskManager;

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

    TaskManager* m_taskManager;

    QTimer* m_taskRetrievalTimer;
};

#endif // TASKMASTER_H

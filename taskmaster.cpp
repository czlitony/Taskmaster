#include "taskmaster.h"
#include "tasks/taskmanager.h"
#include "settings/retrievalintervalsetting/retrievalintervalsetting.h"
#include <functional>

TaskMaster::TaskMaster()
{
    init();
}

TaskMaster::~TaskMaster()
{
    delete m_taskManager;
}

void TaskMaster::init()
{
    m_taskManager = new TaskManager;

    m_taskRetrievalTimer = new QTimer(this);
    m_taskRetrievalTimer->setSingleShot(false);
    connect(m_taskRetrievalTimer, SIGNAL(timeout()), this, SLOT(retrieveTask()));
}

void TaskMaster::retrieveTask()
{
    m_taskManager->retrieveTask(std::bind(&TaskMaster::onTasksRetrieved, this,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void TaskMaster::start()
{
    retrieveTask();

    m_taskRetrievalTimer->start(RetrievalIntervalSetting::getInstance()->getInterval() * 1000);
}

void TaskMaster::stop()
{
    m_taskRetrievalTimer->stop();
}

void TaskMaster::onTasksRetrieved(RetrievalResult result,
                                  const QList<UnfinishedTask> &unfinishedTask,
                                  const QList<QuickTask> &quickTask,
                                  const QList<FileTask> &fileTask)
{
    qDebug() << "retrieved";
}

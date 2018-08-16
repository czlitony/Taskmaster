#include "taskmaster.h"
#include "tasks/taskmanager.h"
#include "settings/retrievalintervalsetting/retrievalintervalsetting.h"

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
    m_taskManager->retrieveTask();
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

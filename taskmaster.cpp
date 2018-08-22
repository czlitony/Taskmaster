#include "taskmaster.h"
#include "musicplayer.h"
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
    delete m_taskRetrievalTimer;
    delete m_musicPlayer;
}

void TaskMaster::init()
{
    m_taskManager = new TaskManager;

    m_taskRetrievalTimer = new QTimer(this);
    m_taskRetrievalTimer->setSingleShot(false);
    connect(m_taskRetrievalTimer, SIGNAL(timeout()), this, SLOT(retrieveTask()));

    m_musicPlayer = new MusicPlayer;
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
    m_musicPlayer->stop();
}

void TaskMaster::onTasksRetrieved(TaskRetrievalResult result,
                                  const QList<UnfinishedTask> &unfinishedTask,
                                  const QList<QuickTask> &quickTask,
                                  const QList<FileTask> &fileTask)
{
    qDebug() << "retrieved";

    playMusic(!quickTask.empty(), !fileTask.empty());

    emit fireOnTasksRetrieved(result, unfinishedTask, quickTask, fileTask);
}

void TaskMaster::playMusic(bool haveQuickTasks, bool haveFileTasks)
{
    if (haveFileTasks)
    {
        m_musicPlayer->playFileTaskMusic();
    }
    else if (haveQuickTasks)
    {
        m_musicPlayer->playQuickTaskMusic();
    }
    else
    {
        m_musicPlayer->stop();
    }
}

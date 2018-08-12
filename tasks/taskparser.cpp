#include "taskparser.h"
#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"

TaskParser::TaskParser()
{

}

bool TaskParser::parse(const QString &response, QList<UnfinishedTask> &unfinishedTask, QList<QuickTask> &quickTask, QList<FileTask> &fileTask)
{
    if (response.isEmpty())
    {
        return false;
    }

    QStringList list1 = response.split("<div class=\"unfinsh-task\">");
    if (list1.size() < 2)
    {
        return false;
    }

    QStringList list2 = list1[1].split("<div class=\"claim-task\">");
    if (list2.size() < 3)
    {
        return false;
    }

    parseUnfinishedTask(unfinishedTask);
    parseQuickTask(quickTask);
    parseFileTask(fileTask);
    //int unfinishedTaskStartPos = response.indexOf("<div class=\"unfinsh-task\">");
    //    int quickTaskStartPos = response.indexOf("");
}

void TaskParser::parseUnfinishedTask(QList<UnfinishedTask> &unfinishedTask)
{

}

void TaskParser::parseQuickTask(QList<QuickTask> &quickTask)
{

}

void TaskParser::parseFileTask(QList<FileTask> &fileTask)
{

}

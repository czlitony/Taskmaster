#include "taskparser.h"
#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"

//static const QString TASK_NAME = "task-name";
static const QString UNFINISHED_TASK_TAG = "<div class=\"unfinsh-task\">";
static const QString CLAIM_TASK_TAG = "<div class=\"claim-task\">";
static const QString DETAIL_TASK_TAG = "<tr class=\"detail-task\">";

static const QString TASK_NUM = "<div class=\"claim-num\"";
static const QString UNFINISHED_TASK_NUM = "<div class=\"task-num\"";
static const QString LANGUAGE = "<td class=\"lan\"";
static const QString WORD_NUM = "<td class=\"wordnum\"";
static const QString WORLD_NUM = "<td class=\"world\"";
static const QString AREA = "<td class=\"area\"";
static const QString USAGE = "<td class=\"use\"";
static const QString ABSTRACT = "<td class=\"abstract\"";
static const QString STATES = "<td class=\"states\"";
static const QString TIME_LEFT = "<td class=\"timeleft\"";
static const QString UNFINISHED_TASK_COMPLETE_TIME = "<td class=\"completetime\"";
static const QString FILE_TASK_COMPLETE_TIME = "<td class=\"comptime\"";
static const QString FINISH_TIME = "<td class=\"time\"";
static const QString PAY = "<td class=\"pay\"";
static const QString BONUS = "<td class=\"bonus\"";
static const QString TRANSLATOR_ID = " class=\"translatorId\"";

TaskParser::TaskParser()
{

}

bool TaskParser::parse(const QString &response, QList<UnfinishedTask> &unfinishedTask, QList<QuickTask> &quickTask, QList<FileTask> &fileTask)
{
    if (response.isEmpty())
    {
        return false;
    }

    QStringList list1 = response.split(UNFINISHED_TASK_TAG);
    if (list1.size() < 2)
    {
        return false;
    }

    QStringList list2 = list1[1].split(CLAIM_TASK_TAG);
    if (list2.size() < 3)
    {
        return false;
    }

    parseUnfinishedTask(list2[0], unfinishedTask);
    parseQuickTask(list2[1], quickTask);
    parseFileTask(list2[2], fileTask);

    return true;
}

void TaskParser::parseUnfinishedTask(const QString& unfinishedTaskStr, QList<UnfinishedTask> &unfinishedTask)
{
    int taskNum = getTaskMetaData(unfinishedTaskStr, UNFINISHED_TASK_NUM, "<span>", "</span>").toInt();
    if (taskNum < 1)
    {
        return;
    }

    int indexOfTask = unfinishedTaskStr.indexOf(DETAIL_TASK_TAG);
    while (indexOfTask != -1)
    {
        UnfinishedTask task;
        QString taskStr = unfinishedTaskStr.mid(indexOfTask);

        OrderDetail orderDetail;
        QString orderNumber = getTaskMetaData(taskStr, "href=");
        orderDetail.setNumber(orderNumber);
        orderDetail.setDetailLink("task.do?method=viewOrderDetail&orderId=" + orderNumber);
        task.setOrderDetail(orderDetail);

        task.setLanguage(getTaskMetaData(taskStr, LANGUAGE));
        task.setWordNumber(getTaskMetaData(taskStr, WORLD_NUM).toInt());
        task.setStatus(getTaskMetaData(taskStr, STATES));
        task.setTimeLeft(getTaskMetaData(taskStr, TIME_LEFT));
        task.setDeadline(getTaskMetaData(taskStr, UNFINISHED_TASK_COMPLETE_TIME));
        task.setPay(getTaskMetaData(taskStr, PAY));
        task.setBonus(getTaskMetaData(taskStr, BONUS));

        unfinishedTask.append(task);

        indexOfTask = unfinishedTaskStr.indexOf(DETAIL_TASK_TAG, indexOfTask + 1);
    }
}

void TaskParser::parseQuickTask(const QString& quickTaskStr, QList<QuickTask> &quickTask)
{
    int taskNum = getTaskMetaData(quickTaskStr, TASK_NUM, "<span>", "</span>").toInt();
    if (taskNum < 1)
    {
        return;
    }

    int indexOfTask = quickTaskStr.indexOf(DETAIL_TASK_TAG);
    while (indexOfTask != -1)
    {
        QuickTask task;
        QString taskStr = quickTaskStr.mid(indexOfTask);

        OrderDetail orderDetail;
        QString orderNumber = getTaskMetaData(taskStr, "href=");
        orderDetail.setNumber(orderNumber);
        orderDetail.setId("orderId" + orderNumber);
        orderDetail.setDetailLink("task.do?method=viewFastOrderDetail&orderId=" + orderNumber);
        task.setOrderDetail(orderDetail);

        task.setLanguage(getTaskMetaData(taskStr, LANGUAGE));
        task.setWordNumber(getTaskMetaData(taskStr, WORD_NUM).toInt());
        task.setAbstract(getTaskMetaData(taskStr, ABSTRACT));
        task.setFinishTime(getTaskMetaData(taskStr, FINISH_TIME));
        task.setPay(getTaskMetaData(taskStr, PAY));
        task.setBonus(getTaskMetaData(taskStr, BONUS));

        QString translatorId = getTaskMetaData(taskStr, TRANSLATOR_ID, "value=\"", "\"");
        AbandonInfo abandonInfo(orderNumber, translatorId);
        task.setAbandonInfo(abandonInfo);

        quickTask.append(task);

        indexOfTask = quickTaskStr.indexOf(DETAIL_TASK_TAG, indexOfTask + 1);
    }
}

void TaskParser::parseFileTask(const QString& fileTaskStr, QList<FileTask> &fileTask)
{
    int taskNum = getTaskMetaData(fileTaskStr, TASK_NUM, "<span>", "</span>").toInt();
    if (taskNum < 1)
    {
        return;
    }

    int indexOfTask = fileTaskStr.indexOf(DETAIL_TASK_TAG);
    while (indexOfTask != -1)
    {
        FileTask task;
        QString taskStr = fileTaskStr.mid(indexOfTask);

        OrderDetail orderDetail;
        QString orderNumber = getTaskMetaData(taskStr, "href=");
        orderDetail.setNumber(orderNumber);
        orderDetail.setDetailLink("task.do?method=viewOrderDetail&orderId=" + orderNumber);
        task.setOrderDetail(orderDetail);

        task.setLanguage(getTaskMetaData(taskStr, LANGUAGE));
        task.setWordNumber(getTaskMetaData(taskStr, WORD_NUM).toInt());
        task.setArea(getTaskMetaData(taskStr, AREA));
        task.setUsage(getTaskMetaData(taskStr, USAGE));
        task.setDeadline(getTaskMetaData(taskStr, FILE_TASK_COMPLETE_TIME));
        task.setTimeLeft(getTaskMetaData(taskStr, TIME_LEFT));
        task.setPay(getTaskMetaData(taskStr, PAY));
        task.setBonus(getTaskMetaData(taskStr, BONUS));

        fileTask.append(task);

        indexOfTask = fileTaskStr.indexOf(DETAIL_TASK_TAG, indexOfTask + 1);
    }
}

QString TaskParser::getTaskMetaData(const QString &taskStr, const QString &dataTag, const QString &dataLeftWrap, const QString &dataRightWrap)
{
    int pos = taskStr.indexOf(dataTag);
    if (pos  == -1)
    {
        return "";
    }

    int startPos = taskStr.indexOf(dataLeftWrap, pos+dataTag.size()) + dataLeftWrap.size();
    int endPos = taskStr.indexOf(dataRightWrap, startPos);
    if (startPos > 0 && endPos > 0 && endPos > startPos)
    {
        return taskStr.mid(startPos, endPos-startPos).trimmed();
    }

    return "";
}

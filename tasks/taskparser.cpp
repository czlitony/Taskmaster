#include "taskparser.h"
#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"

//static const QString TASK_NAME = "task-name";
//static const QString TASK_NUM = "claim-num";
static const QString ORDER_NUM = "\"ordernum\"";
static const QString LANGUAGE = "\"lan\"";
static const QString WORD_NUM = "\"wordnum\"";
static const QString ABSTRACT = "\"abstract\"";
static const QString FINISH_TIME = "\"time\"";
static const QString PAY = "\"pay\"";
static const QString BONUS = "\"bonus\"";

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

    parseUnfinishedTask(list2[0], unfinishedTask);
    parseQuickTask(list2[1], quickTask);
    parseFileTask(list2[2], fileTask);

    return true;
    //int unfinishedTaskStartPos = response.indexOf("<div class=\"unfinsh-task\">");
    //    int quickTaskStartPos = response.indexOf("");
}

void TaskParser::parseUnfinishedTask(const QString& unfinishedTaskStr, QList<UnfinishedTask> &unfinishedTask)
{

}

void TaskParser::parseQuickTask(const QString& quickTaskStr, QList<QuickTask> &quickTask)
{
    int indexOfTask = quickTaskStr.indexOf("<tr class=\"detail-task\">");
    while (indexOfTask != -1)
    {
        QuickTask task;
        QString taskStr = quickTaskStr.mid(indexOfTask);

        OrderDetail orderDetail;
        QString orderNumber = getTaskMetaData(taskStr, ORDER_NUM);
        orderDetail.setNumber(orderNumber);
        orderDetail.setId("orderId" + orderNumber);
        orderDetail.setDetailLink("task.do?method=viewFastOrderDetail&orderId=" + orderNumber);
        task.setOrderNum(orderDetail);

        task.setLanguage(getTaskMetaData(taskStr, LANGUAGE));
        task.setWordNumber(getTaskMetaData(taskStr, WORD_NUM).toInt());
        task.setAbstract(getTaskMetaData(taskStr, ABSTRACT));
        task.setFinishTime(getTaskMetaData(taskStr, FINISH_TIME));
        task.setPay(getTaskMetaData(taskStr, PAY));
        task.setBonus(getTaskMetaData(taskStr, BONUS));

        QString translatorId = getQuickTaskTranslatorId(taskStr);
        AbandonInfo abandonInfo(orderNumber, translatorId);
        task.setAbandonInfo(abandonInfo);

        quickTask.append(task);

        indexOfTask = quickTaskStr.indexOf("<tr class=\"detail-task\">", indexOfTask + 1);
    }

}

void TaskParser::parseFileTask(const QString& fileTaskStr, QList<FileTask> &fileTask)
{

}

QString TaskParser::getTaskMetaData(const QString& taskStr, const QString &type)
{
    int pos = taskStr.indexOf("<td class=" + type);
    if (pos  == -1)
    {
        return "";
    }

    if (type == ORDER_NUM)
    {
        pos = taskStr.indexOf("href", pos);
    }
    if (pos  == -1)
    {
        return "";
    }

    int startPos = taskStr.indexOf('>', pos+1);
    int endPos = taskStr.indexOf('<', startPos+1);
    if (startPos > 0 && endPos > 0 && endPos > startPos)
    {
        return taskStr.mid(startPos+1, endPos-startPos-1).trimmed();
    }

    return "";
}

QString TaskParser::getQuickTaskTranslatorId(const QString& taskStr)
{
    int pos = taskStr.indexOf("name=\"translatorId\"");
    if (pos  == -1)
    {
        return "";
    }

    pos = taskStr.indexOf("value=", pos+1);
    if (pos  == -1)
    {
        return "";
    }

    int startPos = taskStr.indexOf('\"', pos+1);
    int endPos = taskStr.indexOf('\"', startPos+1);
    if (startPos > 0 && endPos > 0 && endPos > startPos)
    {
        return taskStr.mid(startPos+1, endPos-startPos-1).trimmed();
    }

    return "";
}

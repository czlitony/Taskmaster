#ifndef TASKRETRIEVER_H
#define TASKRETRIEVER_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QList>

#include <atomic>

//class UnfinishedTask;
//class QuickTask;
//class FileTask;
#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"

class TaskParser;

enum RetrievalResult
{
    SUCCEED,
    SESSION_EXPIRED,
    NETWORK_ERROR,
    UNKNOWN
};

class TaskRetriever : public QObject
{
    Q_OBJECT

public:
    TaskRetriever();

    void retrieveTasks();
    void getRetrievedTasks(enum RetrievalResult result,
                           QList<UnfinishedTask> &unfinishedTask,
                           QList<QuickTask> &quickTask,
                           QList<FileTask> &fileTask);

public slots:
    void onResponseReceived(QNetworkReply *reply);

signals:
    void finished(enum RetrievalResult result,
                  QList<UnfinishedTask> &unfinishedTask,
                  QList<QuickTask> &quickTask,
                  QList<FileTask> &fileTask);
    void finished();

private:
    void writeResponseToCacheFile(const QByteArray& response);
    QString getResponseFromCacheFile() const;

    QNetworkRequest m_httpRequest;
    QNetworkAccessManager m_networkAccessManager;

    TaskParser* m_taskParser;

    std::atomic<bool> m_lastRetrievalInProgress;

    enum RetrievalResult m_result;
    QList<UnfinishedTask> m_unfinishedTask;
    QList<QuickTask> m_quickTask;
    QList<FileTask> m_fileTask;
};

#endif // TASKRETRIEVER_H

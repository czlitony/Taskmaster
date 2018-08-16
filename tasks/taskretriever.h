#ifndef TASKRETRIEVER_H
#define TASKRETRIEVER_H

#include "tasks/unfinishedtask.h"
#include "tasks/quicktask.h"
#include "tasks/filetask.h"
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QList>

#include <atomic>

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

public slots:
    void onResponseReceived(QNetworkReply *reply);

signals:
    void finished(enum RetrievalResult result,
                  const QList<UnfinishedTask>& unfinishedTask,
                  const QList<QuickTask>& quickTask,
                  const QList<FileTask>& fileTask);

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

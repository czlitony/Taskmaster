#ifndef TASKRETRIEVER_H
#define TASKRETRIEVER_H

#include "retrievalresult.h"
#include "unfinishedtask.h"
#include "quicktask.h"
#include "filetask.h"
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QList>

#include <atomic>

class TaskParser;

class TaskRetriever : public QObject
{
    Q_OBJECT

public:
    TaskRetriever();

    void retrieveTasks();

public slots:
    void onResponseReceived(QNetworkReply *reply);

signals:
    void finished(enum TaskRetrievalResult result,
                  const QList<UnfinishedTask>& unfinishedTask,
                  const QList<QuickTask>& quickTask,
                  const QList<FileTask>& fileTask);

private:
    void writeResponseToCacheFile(const QByteArray& response);
    QString getResponseFromCacheFile() const;

    enum TaskRetrievalResult getTaskRetrievalResult(int httpStatusCode);

    QNetworkRequest m_httpRequest;
    QNetworkAccessManager m_networkAccessManager;

    TaskParser* m_taskParser;

    std::atomic<bool> m_lastRetrievalInProgress;

    QList<UnfinishedTask> m_unfinishedTask;
    QList<QuickTask> m_quickTask;
    QList<FileTask> m_fileTask;
};

#endif // TASKRETRIEVER_H
